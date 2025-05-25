class Solution {
public:
    double maxAmount(string init, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map <string,double> dp;
        dp[init] = 1.0;
        auto solve = [&](vector<vector<string>>& pairs , vector<double> rates){
            int n = pairs.size();
            for(int t = 0 ; t < n ; t++){
                for(int i = 0 ; i < n ; i++){
                    string from = pairs[i][0] , to = pairs[i][1];
                    dp[to] = max(dp[to] , rates[i] * dp[from]);
                    dp[from] = max(dp[from] , 1.0 / rates[i] * dp[to]);
                }
            }
        };
        solve(pairs1 , rates1);
        solve(pairs2 , rates2);
        return dp[init];
    }
};