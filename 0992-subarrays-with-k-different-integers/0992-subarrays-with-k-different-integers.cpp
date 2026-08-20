class Solution {
public:

    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int left = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {

            mp[nums[right]]++;

            // More than k distinct → shrink
            while (mp.size() > k) {
                mp[nums[left]]--;

                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }

                left++;
            }

            // All subarrays from left to right are valid
            count += right - left + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};