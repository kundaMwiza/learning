
#ifndef REVERSE_INTEGER
#define REVERSE_INTEGER

#include <cmath>
#include <iostream>

class ReverseInteger
{

public:
    int reverse(int x)
    {

        // early return if x is zero
        if (x == 0)
        {
            return x;
        }

        bool neg = x < 0;
        int max_value = neg ? pow(2, 31) : pow(2, 31) - 1;

        int output;

        int rem = x % 10;
        x /= 10;
        output = rem;

        while (x != 0)
        {
            rem = x % 10;
            x /= 10;

            if (output == 0)
            {
                output = rem;
            }
            else if ((max_value / output) > 10)
            {
                output = output * 10 + rem;
            }
            else
            {
                return 0;
            }
        }

        return output;
    }
};

#endif