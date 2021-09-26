#include <iostream>
#include <vector>
#include <string>

#include "Eigen/Dense"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

template <typename it_type, typename mat>
void print_mats(
    it_type b,
    it_type e,
    const mat &mat_ref
) {
    if (b != e) {
        std::cout << *b  << '\n' << mat_ref << std::endl; 
    }
}

template <typename it_type, typename mat, typename... otherMats>
void print_mats(
    it_type b,
    it_type e, 
    const mat &mat_ref,
    const otherMats&... other_mat_ref) {

    if (b != e) {
        std::cout << *b  << '\n' << mat_ref << std::endl; 
        print_mats(++b, e, other_mat_ref...);
    }

}


int main(int argc, const char *argv[]) {

    std::vector<std::string> mat_names = {"mat1", "mat2", "mat3"};
    Eigen::MatrixXd mat1 = Eigen::MatrixXd::Random(3,3);
    Eigen::MatrixXd mat2 = Eigen::MatrixXd::Random(3,3);
    Eigen::MatrixXd mat3 = Eigen::MatrixXd::Random(3,3);

    print_mats(mat_names.begin(), mat_names.end(), mat1, mat2, mat3); 

    // expression 
    mat1 = mat2 + mat3; 
    std::cout << mat1 << std::endl; 

    // assign to original col 
    mat1.col(1) = Eigen::MatrixXd::Random(3, 1); 
    std::cout << '\n' << mat1 << std::endl;

    // copy construct a column 
    Eigen::MatrixXd col_mat = mat1.col(1); 
    
    // change the values in col_mat 
    // no aliasing since no reused elems
    col_mat = col_mat.array() * 5; 

    std::cout << "origin col1\n" << mat1.col(1) << std::endl;

    std::cout << "modified col1\n" << col_mat << std::endl; 

    // create reference to column.. is this possible?
    const Eigen::MatrixXd &col_mat_ref = mat1.col(1);

    std::cout << "reference to column 1" << col_mat_ref << std::endl;

    return EXIT_SUCCESS; 
}