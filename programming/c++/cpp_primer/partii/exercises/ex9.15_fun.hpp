#include <vector>
#include <iostream>

inline bool compare_vectors(const std::vector<int> &vec1, const std::vector<int> &vec2)
{
    bool result = vec1 == vec2;
    return result;
}