#include <string>

class Solution {
public:
    bool isPalindrome(const std::string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }

    std::string longestPalindrome(const std::string& s) {
        int n = s.size();
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isPalindrome(s, i, j)) {
                    if ((j - i + 1) > maxLength) {
                        maxLength = (j - i + 1);
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};
