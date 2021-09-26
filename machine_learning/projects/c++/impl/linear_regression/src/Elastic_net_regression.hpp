#ifndef ELASTIC_NET_REGRESSION
#define ELASTIC_NET_REGRESSION

#include "Estimator.hpp"
#include "Eigen/Dense"

class ElasticNetRegression : public Estimator
{
public:
    // member functions ---
    ElasticNetRegression(
        float lambda = 0.5, float alpha = 0.5, unsigned int n_iter = 50,
        bool data_norm = true, bool lambda_search = false, unsigned int verbosity = 1)
        : lambda(lambda), alpha(alpha), n_iter(n_iter), data_norm(data_norm),
          lambda_search(lambda_search), verbosity(verbosity) {}

    // training functions
    void fit(const Eigen::MatrixXd &data) override;
    void fit(const Eigen::MatrixXd &X_train, const Eigen::MatrixXd &Y_train) override;
    void fit(
        const Eigen::MatrixXd &X_train, const Eigen::MatrixXd &Y_train,
        const Eigen::MatrixXd &X_test, const Eigen::MatrixXd &Y_test
        ) override;
    Eigen::MatrixXd predict(const Eigen::MatrixXd &data) const override;

    // mse loss function
    virtual double mse(const Eigen::MatrixXd &data, const Eigen::MatrixXd &resp) const;

    // destructor
    virtual ~ElasticNetRegression() = default;

private:
    // member functions ---
    double update_parameter(double z) const;

    // data ---

    // elastic net params
    float lambda, alpha;

    // model params
    Eigen::MatrixXd params;

    // has the user used the fit function?
    bool fit_init = false;

    // optimisation params
    unsigned int n_iter;
    bool lambda_search;

    // user feedback
    unsigned int verbosity;

    // is the input data normalised
    bool data_norm;
};

#endif