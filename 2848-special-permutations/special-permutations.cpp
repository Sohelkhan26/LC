class Solution {
public:
    int mod = 1e9 + 7 , n , finish;
    vector<vector<int>> dp;
    int solve(int prev , vector <int> &nums , int vis){
        if(vis == finish)
            return 1;
        if(dp[prev][vis] != -1)
            return dp[prev][vis];
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(vis & (1 << i))
                continue;
            if(prev == n + 1 or nums[prev] % nums[i] == 0 or nums[i] % nums[prev] == 0)
                ans = (ans + solve(i , nums , vis | (1 << i))) % mod  ;
        }
        return dp[prev][vis] = ans;
    }
    int specialPerm(vector<int>& nums) {
        n = nums.size();
        finish = (1 << n) - 1;
        dp.resize(n + 2 , vector <int> ((1 << n) , -1));
        return solve(n + 1 , nums , 0);
    }
};

/*

*/