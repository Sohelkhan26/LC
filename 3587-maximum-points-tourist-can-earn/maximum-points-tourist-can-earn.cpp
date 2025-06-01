class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int dp[n][k];
        memset(dp , -1 , sizeof(dp));
        function<int(int,int)> solve = [&](int curr , int day){
            if(day >= k)
                return 0;
            if(dp[curr][day] != -1)
                return dp[curr][day];
            int ans = stayScore[day][curr] + solve(curr , day + 1);

            for(int city = 0 ; city < n ; city++)
                ans = max(ans , travelScore[curr][city] + solve(city , day + 1));
            
            return dp[curr][day] = ans;
        };
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            ans = max(ans , solve(i , 0));
        return ans;
    }
};