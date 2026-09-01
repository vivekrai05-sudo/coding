class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (s.size() < p.size()) {
            return ans;
        }

        vector<int> pFreq(26, 0);
        vector<int> sFreq(26, 0);

        // Frequency of p
        for (char ch : p) {
            pFreq[ch - 'a']++;
        }

        int matches = 0;

        // Initially compare all 26 characters
        for (int i = 0; i < 26; i++) {
            if (pFreq[i] == sFreq[i]) {
                matches++;
            }
        }

        int left = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add right character
            int index = s[right] - 'a';

            sFreq[index]++;

            // Update matches
            if (sFreq[index] == pFreq[index]) {
                matches++;
            }
            else if (sFreq[index] == pFreq[index] + 1) {
                matches--;
            }

            // Window size > p.size()
            if (right - left + 1 > p.size()) {

                int removeIndex = s[left] - 'a';

                // Before removing
                if (sFreq[removeIndex] == pFreq[removeIndex]) {
                    matches--;
                }
                else if (sFreq[removeIndex] == pFreq[removeIndex] + 1) {
                    matches++;
                }

                sFreq[removeIndex]--;
                left++;
            }

            // Window size exactly equal to p.size()
            if (right - left + 1 == p.size() && matches == 26) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};