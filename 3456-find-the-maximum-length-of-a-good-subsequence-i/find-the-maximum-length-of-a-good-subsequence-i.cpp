class Solution {
public:
    int dp[501][501][26];
    int solve(int i , int prev , int k , vector <int> &nums){
        if(i == nums.size())
            return 0;
        int ans = INT_MIN;
        if(dp[i][prev + 1][k] != -1)
            return dp[i][prev + 1][k];
        ans = max(ans , solve(i + 1 , prev , k , nums));
        if(prev == -1)
            ans = max(ans , 1 + solve(i + 1 , i , k , nums)); // start the seq here
        else if(nums[i] == nums[prev])
            ans = max(ans , 1 + solve(i + 1 , i , k , nums));
        else if(k > 0)
            ans = max(ans , 1 + solve(i + 1 , i , k - 1 , nums));
        return dp[i][prev + 1][k] = ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 ,-1 , k , nums);
    }
};