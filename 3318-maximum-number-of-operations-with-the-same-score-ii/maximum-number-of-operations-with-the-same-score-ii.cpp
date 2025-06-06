class Solution {
public:
    vector<vector<int>> dp;
    int solve(int score , int i , int j , vector <int> &nums){
        if(i >= j)
            return 0;
        int ans = 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(nums[i] + nums[i + 1] == score)
            ans = max(ans , 1 + solve(score , i + 2 , j , nums));
        if(nums[j] + nums[j - 1] == score)
            ans = max(ans , 1 + solve(score , i , j - 2 , nums));
        if(nums[i] + nums[j] == score)
            ans = max(ans , 1 + solve(score , i + 1 , j - 1 , nums));
        return dp[i][j] = ans;
    }
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n , vector<int> (n , -1));
        int ans = solve(nums[0] + nums[1] , 2 , n - 1 , nums);
        ans = max({ans , solve(nums[n - 1] + nums[n - 2] , 0 , n - 3 , nums) , solve(nums[0] + nums[n - 1] , 1 , n - 2 , nums)});
        return ans + 1;
    }
};

/*
Remove:
1. first 2
2. last 2
3. first 1 , last 1
score is sum of removed elements.
What is max count of operation such that score of each is same.(all operation)
DP ? Maybe over kill. Since every operation score needs to be same.
Fix the first operaton out of 3 and simulate the rest ? 
n could be odd ? No TC like this.
Simulation needs memoization, cause there could be at most 3 choice.
DP state ? 3 (i , j , score) ? or 2(i , j) ? score is constant. So, just use i , j.
*/