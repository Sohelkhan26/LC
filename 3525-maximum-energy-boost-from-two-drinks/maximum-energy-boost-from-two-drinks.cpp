/*
For every index i we can either stay at A or switch to B. For every step we take the max of the two result. 
We can either start taking drink from A first or B.
*/
typedef long long ll;
class Solution {
public:
    vector<vector<long long>> dp;
    ll solve(int i , int curr , vector<int> &a , vector<int> &b){
        if(i == a.size())
            return 0;
        if(dp[i][curr] != -1)
            return dp[i][curr];
        ll ans = 0;
        if(curr)
            ans = max(b[i] + solve(i + 1 , curr , a , b) , solve(i + 1 , curr ^ 1 , a , b));
        else ans = max(a[i] + solve(i + 1 , curr , a , b) , solve(i + 1 , curr ^ 1 , a , b));
        return dp[i][curr] = ans;
    }
    long long maxEnergyBoost(vector<int>& A , vector<int>& B) {
        int n = A.size();
        dp.resize(n , vector<long long> (2 , -1));
        // function<long long(int,int)> solve = [&](int i , int curr) -> long long{
        //     if(i >= n)
        //         return 0;
        //     if(dp[i][curr] != -1)
        //         return dp[i][curr];
        //     long long ans = 0;
        //     if(curr) // curr = 1 -> A , 0 -> B
        //         ans = max(A[i] + solve(i + 1 , curr) , solve(i + 1 , curr ^ 1));
        //     else
        //         ans = max(B[i] + solve(i + 1 , curr) , solve(i + 1 , curr ^ 1));
        //     return dp[i][curr] = ans;
        // };
        return max(solve(0 , 0 , A , B) , solve(0 , 1 , A , B));
    }
};