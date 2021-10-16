#ifndef GEN_DATA
#define GEN_DATA

#include <random>
#include <algorithm>
#include <array>
#include <vector>

template <typename T>
bool mat_equal(const T *A, const T *B, const unsigned int nrow, const unsigned int ncol, bool col_major = true)
{

    bool equal = true;

    if (col_major)
    {

        for (unsigned int j(0); j != ncol; ++j)
        {
            for (unsigned int i(0); i != nrow; ++i)
            {
                if (A[j * nrow + i] != B[j * nrow + i])
                {
                    // std::cout << "row: " << i << " col: " << j << std::endl;
                    equal = false;
                }
            }
        }
    }
    else
    {
        for (unsigned int i(0); i != nrow; ++i)
        {
            for (unsigned int j(0); j != ncol; ++j)
            {
                if (A[i * ncol + j] != B[i * ncol + j])
                {
                    // std::cout << "row: " << i << " col: " << j << std::endl;
                    equal = false;
                }
            }
        }
    }

    return equal;
}
// print a column major matrix
template <typename T>
void print_matrix(const T *mat, const unsigned int nrow, const unsigned int ncol, bool col_major = true)
{

    if (col_major)
    {
        for (unsigned int i = 0; i != nrow; ++i)
        {

            std::cout << "| Row: " << i << "| ";
            for (unsigned int j = 0; j != ncol; ++j)
            {
                std::cout << mat[j * nrow + i] << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {

        for (unsigned int i = 0; i != nrow; ++i)
        {
            std::cout << "| Row: " << i << "| ";
            for (unsigned int j = 0; j != ncol; ++j)
            {
                std::cout << mat[i * ncol + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::cout << "\n"
              << std::endl;
}

template <typename T>
class MatCreator
{

public:
    // constructors
    MatCreator(
        const unsigned int min,
        const unsigned int max,
        const unsigned int seed = 123)
        : seed(seed), dist(min, max), dev_engine(seed)
    {
    }

    // member functions
    std::vector<T> generate_unif(const unsigned int nrow, const unsigned int ncol)
    {
        std::vector<T> mat(nrow * ncol);

        std::generate(
            mat.begin(),
            mat.end(),
            [&]()
            { return dist(dev_engine); });

        return mat;
    }

    std::vector<T>
    generate_zero(const unsigned int nrow, const unsigned int ncol) const
    {
        std::vector<T> mat(nrow * ncol, 0);

        return mat;
    }

    void fill_zero(std::vector<T> &mat_ptr) const
    {
        std::fill(
            mat_ptr.begin(),
            mat_ptr.end(),
            0);
    }

    const unsigned int seed;
    std::mt19937_64 dev_engine;
    std::uniform_real_distribution<T> dist;
};

#endif