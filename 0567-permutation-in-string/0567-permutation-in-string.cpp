class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> s1Freq(26, 0);
        vector<int> windowFreq(26, 0);

        // Count frequency of s1
        for (char ch : s1) {
            s1Freq[ch - 'a']++;
        }

        int k = s1.size();

        for (int i = 0; i < s2.size(); i++) {

            // Add current character
            windowFreq[s2[i] - 'a']++;

            // Remove character outside the window
            if (i >= k) {
                windowFreq[s2[i - k] - 'a']--;
            }

            // Window size is exactly k
            if (i >= k - 1 && windowFreq == s1Freq) {
                return true;
            }
        }

        return false;
    }
};