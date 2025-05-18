class Solution {
public:
    int dp[501][501][26];
    int solve(int i , int prev , int k , vector <int> &nums){
        if(i == nums.size())
            return 0;
        int ans = INT_MIN;
        if(dp[i][prev + 1][k] != -1)
            return dp[i][prev + 1][k];
        ans = solve(i + 1 , prev , k , nums); // skip or don't start here condition
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

/*
We can include atmost k non-equal-adjacent value in the subsequence.
So keep track of previous index. 
About the start of the sequence. We shouldn't k-- for the starting element.
So, three case:
1. skip the current element.
2. Check for start of the subsequence.
3. Include i'th element depending on 'k'
*/