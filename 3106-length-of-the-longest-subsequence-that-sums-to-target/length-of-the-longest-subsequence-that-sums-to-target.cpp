class Solution {
public:
    int dp[1001][1001];
    int solve(int i , vector <int> &nums , int target){
        if(target == 0) 
            return 0;
        if(target < 0 or i == nums.size()) 
            return INT_MIN;
        if(dp[i][target] != -1)
            return dp[i][target];
        int len = solve(i + 1 , nums , target);
        return dp[i][target] = max(len , 1 + solve(i + 1 , nums , target - nums[i]));
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp , -1 , sizeof(dp));
        int ans = solve(0 , nums , target);
        return ans <= 0 ? -1 : ans;
    }
};