#include "ETL.hpp"
#include "Eigen/Dense"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, const char *argv[])
{

    // filename, delim, columns
    ETL etl(argv[1], argv[2][0], std::stoi(argv[3]));

    // vector of vectors
    ETL::map_type columns;
    ETL::csv_type data;

    // load data
    std::tie(columns, data) = etl.load_dataset();

    // map data from vector<vector<string>> to Eigen::MatrixXd
    auto X = etl.transform_to_eigen(data);

    Eigen::MatrixXd X_train, Y_train, X_test, Y_test;
    std::tie(X_train, Y_train, X_test, Y_test) = etl.train_test_split(X, 0.8);

    Eigen::VectorXd m_vec, std_vec;
    auto norm_stats = etl.determine_norm_stats(X_train);

    std::cout << etl.normalize_data(X_train, norm_stats) << std::endl;

    // std::cout << m_vec.transpose() << std::endl;
    // std::cout << std_vec.cwiseInverse() << std::endl;
    // std::cout << X_train(Eigen::seq(1, 2), Eigen::all) << std::endl;
    // std::cout << (X_train(Eigen::seq(1, 2), Eigen::all).rowwise() - m_vec.transpose()) * std_vec.cwiseInverse().asDiagonal() << std::endl;

    // std::cout << X_train.rows() << ' ' << X_train.cols() << std::endl;
    // std::cout << Y_train.rows() << ' ' << Y_train.cols() << std::endl;
    // std::cout << X_test.rows() << ' ' << X_test.cols() << std::endl;
    // std::cout << Y_test.rows() << ' ' << Y_test.cols() << std::endl;

    return EXIT_SUCCESS;
}