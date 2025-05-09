class Solution {
public:
    int n;
    unordered_map <int,int> dp;
    int solve(int op , vector<int> &nums , bitset<16> &vis){
        int mask = vis.to_ulong();
        if(dp.contains(mask))
            return dp[mask];
        dp[mask] = 0;
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 1)
                continue;
            for(int j = i + 1 ; j < n ; j++){
                if(vis[j] == 1)
                    continue;
                vis.set(i) , vis.set(j);
                int ans = op * __gcd(nums[i] , nums[j]) + solve(op + 1 , nums , vis);
                vis.reset(i) , vis.reset(j);
                dp[mask] = max(dp[mask] , ans);
            }
        }
        return dp[mask];
    }
    int maxScore(vector<int>& nums) {
        n = nums.size();
        bitset <16> vis = 0;
        return solve(1 , nums , vis);
    }   
};