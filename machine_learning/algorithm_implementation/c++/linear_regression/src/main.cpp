#include "ETL.hpp"
#include "Elastic_net_regression.hpp"

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

    Eigen::MatrixXd X_train_norm = etl.normalize_data(X_train, norm_stats);
    Eigen::MatrixXd X_test_norm = etl.normalize_data(X_test, norm_stats);

    // add a constant column to match the bias
    etl.add_constant_col(X_train);
    etl.add_constant_col(X_test);

    ElasticNetRegression test_model(0, 0.5, 50);

    test_model.fit(X_train, Y_train, X_test, Y_test);

    std::cout << "Test mse error: " << test_model.mse(X_test, Y_test) << std::endl;

    return EXIT_SUCCESS;
}