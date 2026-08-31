class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = nums[0];

        int currentMax = nums[0];
        int maxSum = nums[0];

        int currentMin = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int num = nums[i];

            totalSum += num;

            // Normal Kadane for maximum
            currentMax = max(num, currentMax + num);
            maxSum = max(maxSum, currentMax);

            // Kadane for minimum
            currentMin = min(num, currentMin + num);
            minSum = min(minSum, currentMin);
        }

        // If all elements are negative
        if (maxSum < 0) {
            return maxSum;
        }

        // Maximum of normal and circular
        return max(maxSum, totalSum - minSum);
    }
};