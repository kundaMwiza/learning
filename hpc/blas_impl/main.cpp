#include <iostream>
#include <cstdlib>
#include <memory>
#include <array>
#include <chrono>

#include "dgemm.hpp"
#include "mat_ops.hpp"

int main(int argc, const char *argv[])
{
    constexpr unsigned int M = 3000, N = 3000, K = 3000;
    using mat_type = float;
    // auto mat = std::make_shared<double[10]>();
    // auto mat = std::make_shared < std::ar
    MatCreator mc(0, 10);
    auto mat_A = mc.generate_int<mat_type, M, N>();
    auto mat_B = mc.generate_int<mat_type, N, K>();
    auto mat_C = mc.generate_zero<mat_type, M, K>();
    auto mat_C_naive = mc.generate_zero<mat_type, M, K>();

    // auto t0_naive = std::chrono::high_resolution_clock::now();
    auto t0_naive = omp_get_wtime();
    dgemm_naive<M, N, K>(mat_A->data(), mat_B->data(), mat_C_naive->data());
    auto t1_naive = omp_get_wtime();
    // auto t1_naive = std::chrono::high_resolution_clock::now();

    // auto t0_blocked = std::chrono::high_resolution_clock::now();
    auto t0_blocked = omp_get_wtime();
    dgemm<M, N, K>(mc, mat_A->data(), mat_B->data(), mat_C->data());
    auto t1_blocked = omp_get_wtime();
    // auto t1_blocked = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double> naive_time(t1_naive - t0_naive);
    // std::chrono::duration<double> blocked_time(t1_blocked - t0_blocked);
    auto naive_time = t1_naive - t0_naive;
    auto blocked_time = t1_blocked - t0_blocked;
    // std::printf("Naive impl took: %.5f, Blocked impl took: %.5f \n", naive_time.count(), blocked_time.count());
    std::printf("Naive impl took: %.5f, Blocked impl took: %.5f \n", naive_time, blocked_time);

    // print_matrix(mat_C->data(), M, K);
    // print_matrix(mat_C_naive->data(), M, K);

    std::cout << "Matrices equal: " << mat_equal(mat_C->data(), mat_C_naive->data(), M, K) << std::endl;

    return EXIT_SUCCESS;
}