class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0] = 1;

        int count = 0;
        int prefixSum = 0;

        for (int r = 0; r < nums.size(); r++) {

            prefixSum += nums[r];

            int target = prefixSum - k;

            if (mp.count(target)) {
                count += mp[target];
            }

            mp[prefixSum]++;
        }

        return count;
    }
};