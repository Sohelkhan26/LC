class Solution {
public:
    int target;
    int dp[101][101][24];
    int solve(int i , int hood , int prev , vector<vector<int>> &cost , vector<int> &houses){
        int n = cost.size() , m = cost[0].size();
        if(i == n)
            return hood == target ? 0 : INT_MAX;

        if(hood > target)
            return INT_MAX;

        if(dp[i][hood][prev] != -1)
            return dp[i][hood][prev];
        long long ans = INT_MAX; 
        // start a new hood if current houses color don't match the previous
        if(houses[i] != 0) 
            ans = min(ans , 0LL + solve(i + 1 , hood + (prev != houses[i]) , houses[i] , cost , houses));
        else{
            for(int j = 0 ; j < m ; j++)
                ans = min(ans , 0LL + cost[i][j] + solve(i + 1 , hood + (j + 1 != prev) , j + 1 , cost , houses));
            
        }
        return dp[i][hood][prev] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int t) {
        target = t;
        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , 0 , 22 , cost , houses);

        return ans == INT_MAX ? -1 : ans;
    }
};