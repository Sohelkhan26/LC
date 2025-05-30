class Solution {
public:
    int n , m;
    #define INT_MAX 1e9
    vector<vector<unordered_map<int,int>>> dp;
    int solve(int i , int j , int mask , vector <int> &nums , vector<int> &andValues){
        if(i == n and j == m)
            return 0;
        if(i == n or j == m)
            return INT_MAX;
        if(dp[i][j].contains(mask))
            return dp[i][j][mask];
        int split = INT_MAX;
        if((mask & nums[i]) == andValues[j]){
            split = nums[i] + solve(i + 1 , j + 1 , -1 , nums , andValues);
        }
        int dontSplit = solve(i + 1 , j , mask & nums[i] , nums , andValues);
        return dp[i][j][mask] = min(split , dontSplit);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        n = nums.size() , m = andValues.size();
        dp.resize(n , vector<unordered_map<int,int>> (m));
        int ans = solve(0 , 0 , -1 , nums , andValues);
        return ans == INT_MAX ? -1 : ans;
    }
};
