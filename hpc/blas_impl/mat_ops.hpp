#ifndef GEN_DATA
#define GEN_DATA

#include <random>
#include <algorithm>
#include <array>

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
    template <typename T, const unsigned int nrow, const unsigned int ncol>
    std::shared_ptr<std::array<T, nrow * ncol> > generate_int()
    {
        std::shared_ptr<std::array<T, nrow *ncol> > mat = std::make_shared<std::array<T, nrow * ncol> >();

        std::generate(
            mat->begin(),
            mat->end(),
            [&]()
            { return dist(dev_engine); });

        return mat;
    }

    template <typename T, const unsigned int nrow, const unsigned int ncol>
    std::shared_ptr<std::array<T, nrow * ncol> > generate_zero() const
    {
        std::shared_ptr<std::array<T, nrow *ncol> > mat = std::make_shared<std::array<T, nrow * ncol> >();
        std::fill(
            mat->begin(),
            mat->end(),
            0);

        return mat;
    }

    template <typename T, const unsigned int nrow, const unsigned int ncol>
    void fill_zero(std::shared_ptr<std::array<T, nrow * ncol> > &mat_ptr) const
    {
        std::fill(
            mat_ptr->begin(),
            mat_ptr->end(),
            0);
    }

    const unsigned int seed;
    std::mt19937_64 dev_engine;
    std::uniform_int_distribution<int> dist;
};

#endif