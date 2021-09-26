#include "Eigen/Dense"
#include <iostream>
#include <string>

int main(int argc, const char *argv[]) {


    Eigen::MatrixXd vec_one = Eigen::MatrixXd::Ones(10, 1); 
    Eigen::MatrixXd vec_two = Eigen::MatrixXd::Ones(10, 1); 

    std::cout << vec_one - vec_two << std::endl;

    std::cout << (vec_one.transpose() * vec_two) << std::endl; 

    std::string s(30, '-'); 

    std::cout << s << std::endl; 

    return EXIT_SUCCESS; 
}