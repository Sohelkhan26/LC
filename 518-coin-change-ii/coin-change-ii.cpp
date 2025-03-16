class Solution {
public:
    int dp[301][5002];
    int solve(int index , int amount , vector <int> &coin){
        if(amount == 0)
            return 1;
        if(index == coin.size() or amount < 0)
            return 0;
        if(dp[index][amount] != -1)
            return dp[index][amount];
        int take = solve(index , amount - coin[index] , coin);
        int dont = solve(index + 1 , amount , coin);
        return dp[index][amount] = take + dont;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , amount , coins);
    }
};