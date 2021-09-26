#ifndef ETL_CLASS
#define ETL_CLASS

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <tuple>
#include <Eigen/Dense>

class ETL
{

public:
    // type alias ---
    using csv_type = std::vector<std::vector<std::string> >;
    using map_type = std::map<unsigned int, std::string>;

    // member functions ---
    ETL(std::string name, char delim, bool header)
        : filename(name), delim(delim), header(header) {}

    std::tuple<map_type, csv_type> load_dataset() const;

    Eigen::MatrixXd transform_to_eigen(const csv_type &) const;

    // split train test data
    std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd>
    train_test_split(Eigen::MatrixXd &data, float train_size) const;

    // determine mean & std for each col in X
    std::pair<Eigen::VectorXd, Eigen::VectorXd>
    determine_norm_stats(Eigen::MatrixXd &X) const;

    // apply norm stats to data
    Eigen::MatrixXd normalize_data(
        Eigen::MatrixXd &X,
        std::pair<Eigen::VectorXd, Eigen::VectorXd> &norm_stats) const;

    // add a constant column to the input matrices
    void add_constant_col(Eigen::MatrixXd &mat) const;

private:
    // member functions ---
    map_type _get_column_names(std::ifstream &) const;
    std::pair<double, double> _get_mean_std(Eigen::Ref<Eigen::MatrixXd> col) const;

    // data members ---
    std::string filename;
    char delim;
    bool header;
};

#endif