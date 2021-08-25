#include "ETL.hpp"
#include <fstream>
#include <sstream>
#include <cmath>

ETL::map_type ETL::_get_column_names(std::ifstream &input_file) const
{
    std::string column_names;
    std::getline(input_file, column_names);
    std::istringstream column_stream(column_names);

    // create a map of column index to column name
    std::string temp;
    unsigned int ind = 0;
    map_type columns;

    while (std::getline(column_stream, temp, delim))
    {
        columns[ind++] = temp;
    }

    return columns;
}

// function to load the data into vector<vector<string>>
std::tuple<ETL::map_type, ETL::csv_type> ETL::load_dataset() const
{
    // open the file for reading
    std::ifstream input_file(filename);

    // line from a file
    std::string line;

    // dataset container
    csv_type dataset;
    map_type columns;

    if (header)
    {
        columns = _get_column_names(input_file);
    }

    // read each row
    while (std::getline(input_file, line))
    {
        std::istringstream row_stream(line);
        std::string ft_val;
        std::vector<std::string> row;
        while (std::getline(row_stream, ft_val, delim))
        {
            row.push_back(ft_val);
        }

        dataset.push_back(row);
    }

    return std::make_tuple(columns, dataset);
}

// function to map vector<vector<string>> to a matrix
Eigen::MatrixXd ETL::transform_to_eigen(
    const csv_type &vec_data) const
{
    unsigned int nrow = vec_data.size();
    unsigned int ncol = vec_data[0].size();

    Eigen::MatrixXd dataset(nrow, ncol);

    for (std::size_t j = 0; j != ncol; ++j)
    {
        for (std::size_t i = 0; i != nrow; ++i)
        {
            dataset(i, j) = std::stod(vec_data[i][j]);
        }
    }

    return dataset;
}

std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd>
ETL::train_test_split(Eigen::MatrixXd &data, float train_size) const
{

    unsigned int train_rows = round(data.rows() * train_size);
    auto train_rows_index = Eigen::seq(0, train_rows - 1);
    auto test_rows_index = Eigen::seq(train_rows, Eigen::last);
    auto ft_cols_index = Eigen::seq(0, Eigen::last - 1);

    Eigen::MatrixXd X_train = data(train_rows_index, ft_cols_index);
    Eigen::MatrixXd Y_train = data(train_rows_index, Eigen::last);
    Eigen::MatrixXd X_test = data(test_rows_index, ft_cols_index);
    Eigen::MatrixXd Y_test = data(test_rows_index, Eigen::last);

    return std::make_tuple(X_train, Y_train, X_test, Y_test);
}

std::pair<double, double>
ETL::_get_mean_std(Eigen::MatrixXd col) const
{

    double mean = col.mean();
    // unbiased std
    double std = sqrt(((col.array() - mean).matrix().squaredNorm() / (col.rows() - 1)));

    return std::make_pair(mean, std);
}

std::pair<Eigen::VectorXd, Eigen::VectorXd>
ETL::determine_norm_stats(Eigen::MatrixXd &X) const
{
    // candidate for parallelisation..
    Eigen::VectorXd m_vec(X.cols());
    Eigen::VectorXd std_vec(X.cols());

    for (std::size_t i = 0; i != X.cols(); ++i)
    {
        std::pair<double, double> stat_pair = _get_mean_std(X.col(i));
        m_vec(i) = stat_pair.first;
        std_vec(i) = stat_pair.second;
    }

    return std::make_pair(m_vec, std_vec);
}

Eigen::MatrixXd ETL::normalize_data(
    Eigen::MatrixXd &X,
    std::pair<Eigen::VectorXd, Eigen::VectorXd> &norm_stats) const
{

    X = (X.rowwise() - norm_stats.first.transpose()) * norm_stats.second.cwiseInverse().asDiagonal();

    return X;
}