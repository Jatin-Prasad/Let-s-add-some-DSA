#include <string>
#include <map>
#include <stack>
#include <cctype>
#include <algorithm>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        stk.push({});
        int n = formula.size();
        
        for (int i = 0; i < n;) {
            if (formula[i] == '(') {
                stk.push({});
                ++i;
            } else if (formula[i] == ')') {
                map<string, int> top = stk.top();
                stk.pop();
                ++i;
                int start = i;
                while (i < n && isdigit(formula[i])) ++i;
                int multiplier = (start < i) ? stoi(formula.substr(start, i - start)) : 1;
                for (auto& [atom, count] : top) {
                    stk.top()[atom] += count * multiplier;
                }
            } else {
                int start = i;
                ++i;
                while (i < n && islower(formula[i])) ++i;
                string atom = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) ++i;
                int count = (start < i) ? stoi(formula.substr(start, i - start)) : 1;
                stk.top()[atom] += count;
            }
        }
        
        map<string, int> atomCounts = stk.top();
        string result;
        for (const auto& [atom, count] : atomCounts) {
            result += atom;
            if (count > 1) result += to_string(count);
        }
        return result;
    }
};

