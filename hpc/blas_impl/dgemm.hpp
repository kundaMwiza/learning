#ifndef DGEMM
#define DGEMM

#include "mat_ops.hpp"
#include <cmath>
#include <exception>

#ifdef _OPENMP
#include <omp.h>
#endif

template <typename T>
void dgemm_naive(
    T *A,
    const unsigned int A_rows,
    const unsigned int A_cols,
    T *B,
    const unsigned int B_cols,
    T *C)
{
    // var to write output to
    T cij;

#pragma omp parallel default(shared) private(cij)
    {
#pragma omp for
        for (unsigned int j = 0; j != B_cols; ++j)
        {
            for (unsigned int i = 0; i != A_rows; ++i)
            {
                cij = C[j * A_rows + i];
                for (unsigned int k = 0; k != A_cols; ++k)
                {
                    cij += A[k * A_rows + i] * B[j * A_cols + k];
                }
                C[j * A_rows + i] = cij;
            }
        }
    }
}

template <typename T>
void gebp(
    T *C,
    const unsigned int C_rows,
    const unsigned int C_cols,
    T *B_pack,
    const unsigned int lower_Br_pack,
    const unsigned int higher_Br_pack,
    T *A_pack,
    const unsigned int lower_Ar_pack,
    const unsigned int higher_Ar_pack,
    const unsigned int p,
    const unsigned int m,
    const unsigned int BLOCK_SIZE)
{
    // bounds for A pack and B pack
    unsigned int B_num_rows = (higher_Br_pack - lower_Br_pack) + 1;
    unsigned int A_num_rows = (higher_Ar_pack - lower_Ar_pack) + 1;

    // C row index, col index is the same as for B pack
    unsigned int c_i(0);

    // writing output for C
    T cij(0);
#pragma omp parallel default(shared) private(cij, c_i)
    {
#pragma omp for
        for (unsigned int j = 0; j != C_cols; ++j)
        {
            for (unsigned int i = 0; i != A_num_rows; ++i)
            {
                c_i = m * BLOCK_SIZE + i;
                cij = C[j * C_rows + c_i];

                for (unsigned int k = 0; k != B_num_rows; ++k)
                {
                    cij += A_pack[i * B_num_rows + k] * B_pack[j * B_num_rows + k];
                }

                C[j * C_rows + c_i] = cij;
            }
        }
    }
}

/*
Uses GEPP and GEBP
*/
template <typename T>
void dgemm(
    const MatCreator<T> &mc,
    T *A,
    const unsigned int A_rows,
    const unsigned int A_cols,
    T *B,
    const unsigned int B_cols,
    T *C,
    const unsigned int BLOCK_SIZE = 64)
{

    // allocate memory for B_pack and A_pack
    auto B_vec = mc.generate_zero(A_cols, B_cols);
    T *B_pack = B_vec.data();

    if (B_pack == nullptr)
    {
        throw std::runtime_error("Unable to allocate memory for B pack");
    }

    auto A_vec = mc.generate_zero(BLOCK_SIZE, BLOCK_SIZE);
    T *A_pack = A_vec.data();

    if (A_pack == nullptr)
    {
        throw std::runtime_error("Unable to allocate memory for A pack");
    }

    // number of matrix panels
    unsigned int num_panels = std::ceil(static_cast<double>(A_cols) / BLOCK_SIZE);

    // number of matrices in a panel - assumes a square matrix
    // for the auxiliary matrix we're going to pack for A
    unsigned int num_mats = std::ceil(static_cast<double>(A_rows) / BLOCK_SIZE);

    // bounds for A_pack and B_pack
    unsigned int lower_Br_pack(0), higher_Br_pack(0);
    unsigned int lower_Ar_pack(0), higher_Ar_pack(0);
    unsigned int B_pack_num_rows(0);
    unsigned int A_pack_num_rows(0);

    for (unsigned int p = 0; p != num_panels; ++p)
    {
        // indices for B_pack
        lower_Br_pack = p * BLOCK_SIZE;
        higher_Br_pack = std::min(p * BLOCK_SIZE + BLOCK_SIZE - 1, A_cols - 1);

        // pack B
        B_pack_num_rows = (higher_Br_pack - lower_Br_pack) + 1;

        for (unsigned int j = 0; j != B_cols; ++j)
        {
            for (unsigned int r = 0; r != B_pack_num_rows; ++r)
            {
                B_pack[j * B_pack_num_rows + r] = B[j * A_cols + p * BLOCK_SIZE + r];
            }
        }

        for (unsigned int m = 0; m != num_mats; ++m)
        {

            // indices for A_pack
            // note that cols for A_pack depend on B_pack
            lower_Ar_pack = m * BLOCK_SIZE;
            higher_Ar_pack = std::min(m * BLOCK_SIZE + BLOCK_SIZE - 1, A_rows - 1);
            A_pack_num_rows = (higher_Ar_pack - lower_Ar_pack) + 1;

            // here we pack A using row major access
            // so that A_pack * B_pack is the product of row major
            // access * column major access without striding
            for (unsigned int j = 0; j != B_pack_num_rows; ++j)
            {
                for (unsigned int r = 0; r != A_pack_num_rows; ++r)
                {
                    A_pack[r * B_pack_num_rows + j] = A[(j + p * BLOCK_SIZE) * A_rows + (m * BLOCK_SIZE) + r];
                }
            }

            gebp(
                C,
                A_rows,
                B_cols,
                B_pack,
                lower_Br_pack,
                higher_Br_pack,
                A_pack,
                lower_Ar_pack,
                higher_Ar_pack,
                p,
                m,
                BLOCK_SIZE);
        }
    }
}

#endif