class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        int result = 0; 
        long long runningSum = 0; 
        for (int i = 0; i < nums.size() - 1; i++) {
            if ((runningSum += nums[i]) >= sum - runningSum) result++;
        }
        return result;
    }
};