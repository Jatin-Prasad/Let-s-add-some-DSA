class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> map(26, 0);
        int maxlen = 0;
        int maxfreq = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            map[s[r] - 'A']++;
            maxfreq = max(maxfreq, map[s[r] - 'A']);
            
            // Check if current window is valid
            int windowSize = r - l + 1;
            int changesNeeded = windowSize - maxfreq;
            
            if (changesNeeded > k) {
                // Shrink the window from the left
                map[s[l] - 'A']--;
                l++;
            }
            
            // Update maximum length of the valid window
            maxlen = max(maxlen, r - l + 1);
        }
        
        return maxlen;
    }
};
