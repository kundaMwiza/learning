#include <iostream>
#include "omp.h"
#include "cuda_runtime.h"

// RUN_MODE 0 - serial
// RUN_MODE 1 - openmp
#define RUN_MODE 1
#define N_ELEMENTS 10
#define WINDOW_SIZE 3

void moving_average_parallel(int *input, int *output, std::size_t n_elements, std::size_t window_size)
{

#pragma omp parallel for
    for (auto ind = 0, temp_ind = 0; (ind != n_elements) & (ind + window_size <= n_elements); ++ind)
    {
        unsigned sum = 0;
        for (auto wind_ind = 0; wind_ind != window_size; ++wind_ind)
        {
            sum += input[ind + wind_ind];
        }
        output[ind] += sum / window_size;
    }
}

void moving_average_serial(int *input, int *output, std::size_t n_elements, std::size_t window_size)
{

    unsigned sum = 0;
    bool enter = true;
    std::size_t out_ind = 0;
    for (auto ind = 0; ind != n_elements; ++ind)
    {
        if (enter)
        {
            sum += input[ind];
            if ((ind + 1) == window_size)
            {
                output[out_ind] = sum / window_size;
                enter = false;
                out_ind += 1;
            }
        }
        else
        {
            sum -= input[ind - window_size];
            sum += input[ind];
            output[out_ind] = sum / window_size;
            out_ind += 1;
        }
    }
}

__global__ void moving_average_cuda(int *dev_input, int *dev_output, std::size_t dev_n_elements, std::size_t dev_window_size)
{
    ;
}

__constant__ unsigned int d_n_elements;
__constant__ unsigned int d_window_size;

int main(int argc, const char *argv[])
{
    constexpr std::size_t n_elements = N_ELEMENTS;
    std::size_t window_size = WINDOW_SIZE;
    int input[n_elements] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int output[n_elements] = {0};

    dim3 blocksPerGrid(1, 1, 1);
    dim3 threadsPerBlock(n_elements, 1, 1);

    int *h_output;
    int *d_input;

    unsigned int val_size = sizeof(unsigned int) * n_elements;

    cudaMallocHost(static_cast<void **>(&h_output), val_size);
    cudaMalloc(static_cast<void **>(&d_input), val_size);

    cudaMemcpy(d_input, input, val_size, cudaMemcpyHostToDevice);
    cudaMemcpyToSymbol(d_n_elements, &n_elements, sizeof(unsigned int), 0, cudaMemcpyHostToDevice);
    cudaMemcpyToSymbol(d_window_size, &window_size, sizeof(unsigned int), 0, cudaMemcpyHostToDevice);

    moving_average_cuda<<<blocksPerGrid, threadsPerBlock>>>(int *d_input, int *h_output, std::size_t d_n_elements, std::size_t d_window_size);

    switch (RUN_MODE)
    {
    case 0:
    {
        moving_average_serial(input, output, n_elements, window_size);
        break;
    }
    case 1:
    {
        moving_average_parallel(input, output, n_elements, window_size);
        break;
    }
    }

    std::cout << "print output from moving average" << std::endl;

    for (auto &elem : output)
    {
        std::cout << elem << std::endl;
    }

    return 0;
}