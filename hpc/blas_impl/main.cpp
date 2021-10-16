#include <iostream>
#include <cstdlib>
#include <memory>
#include <array>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>

#include "dgemm.hpp"
#include "mat_ops.hpp"

int main(int argc, const char *argv[])
{
    using mat_type = double;
    MatCreator<mat_type> mc(0, 10);
    const unsigned int max_mat_dim = 2000;

    auto mat_A = mc.generate_unif(max_mat_dim, max_mat_dim);
    auto mat_B = mc.generate_unif(max_mat_dim, max_mat_dim);
    auto mat_C = mc.generate_zero(max_mat_dim, max_mat_dim);
    auto mat_C_naive = mc.generate_zero(max_mat_dim, max_mat_dim);

    const unsigned int max_block_dim = 512;

    // determine num block_dim / mat_dim combinations to create
    // a fixed sized array to store results
    const unsigned int max_blocks = std::log2(max_block_dim / static_cast<double>(32)) + 1;
    const unsigned int temp = std::ceil((max_mat_dim - 100) / static_cast<double>(100)) + 1;
    const unsigned int num_row_output = temp + temp * max_blocks;
    const unsigned int num_col_output = 6;

    // array to store results
    std::array<double, num_col_output *num_row_output> results_arr = {0};
    unsigned int row_num(0);

    // declare vars for timing
    auto t0 = omp_get_wtime();
    auto t1 = omp_get_wtime();

    for (unsigned int m = 100; m <= max_mat_dim; m += 100)
    {
        results_arr[row_num * num_col_output] = m;
        for (unsigned int rep = 0; rep != 3; ++rep)
        {
            // reset C
            mc.fill_zero(mat_C_naive);
            t0 = omp_get_wtime();
            dgemm_naive(mat_A.data(), m, m, mat_B.data(), m, mat_C_naive.data());
            t1 = omp_get_wtime();
            results_arr[row_num * num_col_output + 3 + rep] = static_cast<double>(t1 - t0);
            std::printf("Type: Naive, mat size: %d, rep: %d", m, rep);
            std::cout << std::endl;
        }
        row_num += 1;
    }

    for (unsigned int m = 100; m <= max_mat_dim; m += 100)
    {
        for (unsigned int b = 32; b <= max_block_dim; b *= 2)
        {
            results_arr[row_num * num_col_output] = m;
            results_arr[row_num * num_col_output + 1] = b;
            results_arr[row_num * num_col_output + 2] = 1;

            for (unsigned int rep = 0; rep != 3; ++rep)
            {
                // reset C
                mc.fill_zero(mat_C);
                t0 = omp_get_wtime();
                dgemm(mc, mat_A.data(), m, m, mat_B.data(), m, mat_C.data(), b);
                t1 = omp_get_wtime();
                results_arr[row_num * num_col_output + 3 + rep] = static_cast<double>(t1 - t0);
                std::printf("Type: Blocked, mat size: %d, block size: %d, rep: %d", m, b, rep);
                std::cout << std::endl;
            }
            row_num += 1;
        }
    }

    std::fstream output_file;
    output_file.open("output_timings.csv", std::ios::out);

    // output header
    output_file << "mat_dim,"
                << "block_size,"
                << "impl_type,"
                << "time_1,"
                << "time_2,"
                << "time_3"
                << "\n";

    if (output_file)
    {
        for (unsigned int i(0); i < num_row_output; ++i)
        {
            for (unsigned int j(0); j < num_col_output; ++j)
            {
                // write N/A for no block size
                if (j == 1 && (results_arr[i * num_col_output + j] == 0))
                {

                    output_file << "N/A";
                }
                else
                {
                    output_file << results_arr[i * num_col_output + j];
                }

                if (j != (num_col_output - 1))
                {
                    output_file << ",";
                }
            }

            output_file << "\n";
        }
    }
    else
    {
        throw std::runtime_error("unable to open output file for timings");
    }

    // // some debugging
    // unsigned int m = max_mat_dim;
    // mc.fill_zero(mat_C);
    // mc.fill_zero(mat_C_naive);

    // t0 = omp_get_wtime();
    // dgemm_naive(mat_A.data(), m, m, mat_B.data(), m, mat_C_naive.data());
    // double naive_time = static_cast<double>(omp_get_wtime() - t0);
    // t0 = omp_get_wtime();
    // dgemm(mc, mat_A.data(), m, m, mat_B.data(), m, mat_C.data());
    // double blocked_time = static_cast<double>(omp_get_wtime() - t0);

    // std::printf("Naive impl took: %.4f, blocked impl took: %.4f\n", naive_time, blocked_time);
    // std::cout << "Matrices equal: " << mat_equal(mat_C.data(), mat_C_naive.data(), m, m) << std::endl;

    return EXIT_SUCCESS;
}