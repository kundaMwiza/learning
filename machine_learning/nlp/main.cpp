#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <exception>

#include "ETL/ETL.hpp"
#include "torch/torch.h"
#include "boost/tokenizer.hpp"

int main(int argc, const char *argv[])
{

    const char *filename = nullptr;
    const char *delimiter = " :,./|\\-0123456789*!?@£$%^&()[]{}~+_'\"=";

    switch (argc)
    {
    case 1:
        throw std::runtime_error("You must provide a filename!");
        break;
    case 2:
        filename = argv[1];
        std::cout << "Using the default delimiter set" << std::endl;
        break;
    case 3:
        filename = argv[1];
        delimiter = argv[2];
        break;
    }

    SmartETL etl(filename);
    auto dh = etl.load_dataset();

    // for (auto &elem : dh.c_map)
    // {
    //     std::cout << "ID: " << elem.first << " Category: " << elem.second << std::endl;
    // }

    return EXIT_SUCCESS;
};