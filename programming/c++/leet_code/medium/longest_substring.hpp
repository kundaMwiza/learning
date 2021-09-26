#ifndef LONGEST_SUBSTRING
#define LONGEST_SUBSTRING

#include <string>
#include <map>

class LongestSubstring
{

public:
    int find_longest(std::string s)
    {

        // early return for an empty string
        if (s == "")
        {
            return 0;
        }

        int b = 0, e = b + 1;
        int longest_length = 1;

        for (unsigned int i = 0; i != s.size(); ++i)
        {
            if (i == 0)
            {
                char_map[s[i]] = i;
            }
            else
            {
                if (char_map.find(s[i]) == char_map.end())
                {
                    e += 1;
                    char_map[s[i]] = i;
                }
                else
                {
                    b = char_map[s[i]] + 1;
                    e += 1;
                    // update the index of char_map[s[i]]
                    char_map[s[i]] = i;
                }

                // update longest length
                if ((e - b) > longest_length)
                {
                    longest_length = e - b;
                }
            }
        }

        return longest_length;
    }

    std::map<char, unsigned int> char_map;

private:
};

#endif