#ifndef TWO_SUM
#define TWO_SUM

#include <map>
#include <vector>

class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // container to hold visited integers 
        std::map<int, int> searched_vals; 
        
        // container to hold the output vector
        std::vector<int> found_inds; 
        
        // off the end iterator in case integer is not found 
        auto map_end = searched_vals.cend(); 
        
        // O(n) time complexity, O(n) space complexity
        for (int i = 0; i != nums.size(); ++i) {
            auto found_elem = searched_vals.find(target - nums[i]); 
            if (found_elem != map_end) {
                found_inds.push_back(found_elem->second);
                found_inds.push_back(i);
            }  else {
                searched_vals[nums[i]] = i; 
            }
        }
        
        return found_inds; 
        
    }
};

#endif 