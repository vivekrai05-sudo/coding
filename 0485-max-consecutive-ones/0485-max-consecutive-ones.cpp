class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int  current_count = 0;
        int max_Count = 0;
        int n=nums.size();

        for(int j = 0; j < n; j++) {

            if(nums[j] == 1) {
               current_count++;
            }
            else {
                
            max_Count = max(max_Count, current_count);
            current_count=0;
           
            }

        }
    ///last consecutive ones ke liye
        max_Count=max(max_Count,current_count);
        return max_Count;
    }
};