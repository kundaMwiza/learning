#include "Elastic_net_regression.hpp"
#include <exception>
#include <iostream>
#include <cmath>

Eigen::MatrixXd ElasticNetRegression::predict(const Eigen::MatrixXd &data) const
{
    // this is just Xb
    return data * params;
}

double ElasticNetRegression::mse(const Eigen::MatrixXd &data, const Eigen::MatrixXd &resp) const
{

    // if the user has not called fit, throw error
    if (!fit_init)
    {
        throw std::runtime_error("Cannot calculate MSE before calling fit!");
    }

    // elastic net penalty components
    double ridge_penalty = 0.5 * (1 - alpha) * (params.transpose() * params)(0, 0);
    double lasso_penalty = alpha * params.cwiseAbs().sum();

    // OLS
    Eigen::MatrixXd y_xb = (resp - predict(data));
    double OLS = (0.5 / data.rows()) * (y_xb.transpose() * y_xb)(0, 0);

    // loss
    double loss = OLS + lambda * (ridge_penalty + lasso_penalty);

    return loss;
}

double ElasticNetRegression::update_parameter(double z) const
{

    double gamma = lambda * alpha;
    double ret_val = 0;
    if ((z > 0) && (gamma < std::abs(z)))
    {
        ret_val = z - gamma;
    }
    else if ((z < 0) && (gamma < std::abs(z)))
    {
        ret_val = z + gamma;
    }
    else
    {
        ret_val = 0;
    }

    return ret_val / (1 + lambda * (1 - alpha));
}

// use coordinate descent to update the parameters one by one
// implementation based on
// Regularization Paths for Generalized Linear Models via Coordinate Descent
// Jerome Friedman Trevor Hastie Rob Tibshirani
// Journal of Statistical Software
void ElasticNetRegression::fit(
    const Eigen::MatrixXd &X_train, const Eigen::MatrixXd &Y_train,
    const Eigen::MatrixXd &X_test, const Eigen::MatrixXd &Y_test)
{

    // user has called the fit function
    fit_init = true;

    // holder for the mse calculated
    double train_mse_val = 0, test_mse_val = 0;

    // set params to be the zero vector
    params = Eigen::MatrixXd::Zero(X_train.cols(), 1);

    // number of rows in the data
    unsigned int N = X_train.rows();

    // bias param is just the mean response
    params(params.rows() - 1, 0) = Y_train.mean();

    // calculate residuals
    Eigen::MatrixXd resids = Y_train - predict(X_train);

    for (std::size_t i = 0; i != n_iter; ++i)
    {
        // assumes at least one predictor
        for (std::size_t p = 0; p != params.rows() - 1; ++p)
        {

            double bp_old = params(p);

            double z = bp_old + (X_train(Eigen::all, p).transpose() * resids / N)(0, 0);

            double gamma = lambda * alpha;

            params(p, 0) = update_parameter(z);

            // if bp has been updated, update the residuals
            if (bp_old != params(p, 0))
            {
                resids = Y_train - predict(X_train);
            }
        }

        if (verbosity == 1)
        {
            std::cout << std::string(50, '-') << std::endl;
            std::cout << "Iteration number: " << i << std::endl;
            
            train_mse_val = mse(X_train, Y_train);
            std::cout << "train MSE: " << train_mse_val << std::endl;
            
            if ((!X_test.isZero(0)) && (!Y_test.isZero(0))) {
                test_mse_val = mse(X_test, Y_test);
                std::cout << "test MSE: " << test_mse_val << std::endl;
            }
            
        }
    }
}

void ElasticNetRegression::fit(const Eigen::MatrixXd &X_train, const Eigen::MatrixXd &Y_train) 
{

    // pass zero test data
    fit(X_train, Y_train, Eigen::MatrixXd::Zero(1,1), Eigen::MatrixXd::Zero(1,1)); 

}

void ElasticNetRegression::fit(const Eigen::MatrixXd &X_train)
{
    throw std::runtime_error("Cannot call fit() without response data for a supervised learning algorithm");
}