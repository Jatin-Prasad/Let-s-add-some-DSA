#include <stdlib.h>
#include <algorithm>
using namespace std;
#include <string>

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (isalpha(s[i]) && isalpha(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (isalpha(s[i]) == 0)
                i++;
            else 
                j--;
        }
        return s;
    }
};