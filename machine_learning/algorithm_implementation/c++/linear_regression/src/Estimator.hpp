#ifndef ESTIMATOR
#define ESTIMATOR

#include "Eigen/Dense"

class Estimator
{

public:
    // member functions ---
    Estimator() = default;

    virtual ~Estimator() = default;

    // overload fit
    virtual void fit(const Eigen::MatrixXd &X_train) = 0;
    virtual void fit(
        const Eigen::MatrixXd &X_train, const Eigen::MatrixXd &Y_train,
        const Eigen::MatrixXd &X_test, const Eigen::MatrixXd &Y_test) = 0;
    virtual void fit(
        const Eigen::MatrixXd &X_train, const Eigen::MatrixXd &Y_train) = 0;

    // prediction function
    virtual Eigen::MatrixXd predict(const Eigen::MatrixXd &data) const = 0;
};

#endif
