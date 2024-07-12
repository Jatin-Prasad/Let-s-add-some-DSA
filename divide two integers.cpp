#include <limits.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the special case of overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Perform the division
        int ans = dividend / divisor;
        return ans;
    }
};
