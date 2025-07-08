class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(int i , int k , vector <vector<int>> &events){
        if(i >= n or k == 0)
            return 0;
        if(dp[i][k] != -1)
            return dp[i][k];
        int take = INT_MIN , skip = INT_MIN;
        if(k){
            int low = i + 1 , high = n - 1 , mid , nextI = n;
            while(low <= high){
                mid = low + (high - low) / 2;
                if(events[mid][0] > events[i][1])
                    nextI = mid , high = mid - 1;
                else low = mid + 1;
            }
            take = events[i][2] + solve(nextI , k - 1 , events);
        }
        skip = solve(i + 1 , k , events);
        return dp[i][k] = max(take , skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin() , events.end());
        n = events.size();
        dp = vector<vector<int>> (n + 1 , vector<int> (k + 1 , -1));
        return solve(0 , k , events);
    }
};