class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // remainder 0 appears before array starts
        mp[0] = -1;

        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int rem = prefixSum % k;

            if (mp.count(rem)) {
                if (i - mp[rem] >= 2) {
                    return true;
                }
            } else {
                // Store only first occurrence
                mp[rem] = i;
            }
        }

        return false;
    }
};