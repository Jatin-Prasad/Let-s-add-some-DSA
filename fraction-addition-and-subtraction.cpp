class Solution {
public:
    string fractionAddition(string expression) {
        // Initialize variables to store the result numerator and denominator.
        int resultNum = 0; // Result numerator (initially 0)
        int resultDen = 1; // Result denominator (initially 1)

        int n = expression.size();
        int i = 0;

        while (i < n) {
            // Parse the sign of the current fraction (if any)
            bool negative = false;
            char ch = expression[i];
            if (ch == '-' || ch == '+') {
                if (ch == '-') {
                    negative = true;
                }
                i++;
            }

            // Parse the numerator
            int start = i;
            while (i < n && isdigit(expression[i])) {
                i++;
            }
            int curNum = stoi(expression.substr(start, i - start));
            if (negative) curNum *= -1; // Apply the sign

            // Move past the '/'
            i++;

            // Parse the denominator
            start = i;
            while (i < n && isdigit(expression[i])) {
                i++;
            }
            int curDen = stoi(expression.substr(start, i - start));

            // Calculate the new numerator and denominator for the result
            resultNum = resultNum * curDen + curNum * resultDen;
            resultDen = resultDen * curDen;

            // Simplify the fraction by dividing by the greatest common divisor (GCD)
            int gcdValue = gcd(abs(resultNum), resultDen);
            resultNum /= gcdValue;
            resultDen /= gcdValue;
        }

        // Return the result as a string in the form "numerator/denominator"
        return to_string(resultNum) + "/" + to_string(resultDen);
    }

};
