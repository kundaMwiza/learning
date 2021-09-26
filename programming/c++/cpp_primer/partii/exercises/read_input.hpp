#ifndef READ_INPUT
#define READ_INPUT 1

#include <iostream>
#include <vector>
#include <string>
#include <deque>

void read_file(std::istream &input_file, std::vector<int> &ref_container);
void read_file(std::istream &input_file, std::vector<float> &ref_container);
void read_file(std::istream &input_file, std::vector<std::string> &ref_container);

template <typename IT, typename OT>
void place_in_deque(const IT &input_container, OT &output_container)
{
    output_container.assign(input_container.cbegin(), input_container.cend());
}

#endif