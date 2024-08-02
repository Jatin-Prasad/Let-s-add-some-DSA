class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if the lengths of s and goal are the same
        if (s.size() != goal.size()) return false;

        // Iterate through all possible starting points for the rotation
        for (int i = 0; i < s.size(); ++i) {
            // Generate the rotated string starting from index i
            // s.substr(i) gives the substring from index i to the end
            // s.substr(0, i) gives the substring from the start up to index i
            // Concatenate these substrings to get the rotated string
            string rotated = s.substr(i) + s.substr(0, i);
            
            // Compare the rotated string with goal
            if (rotated == goal) {
                // If they match, s can be rotated to become goal
                return true;
            }
        }
        
        // If no rotation matches goal, return false
        return false;
    }
};
