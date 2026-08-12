class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_set<int> st;

        long long sum = 0;
        long long ans = 0;

        int left = 0;

        for(int right = 0; right < nums.size(); right++) {

            // Duplicate element aa gaya
            while(st.find(nums[right]) != st.end()) {
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            // Current element add karo
            st.insert(nums[right]);
            sum += nums[right];

            // Window size k se badi ho gayi
            if(right - left + 1 > k) {
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            // Valid window of size k
            if(right - left + 1 == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};