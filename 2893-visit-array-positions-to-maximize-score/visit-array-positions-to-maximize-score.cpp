class Solution {
public:
    typedef long long ll;

    int n , x;

    ll dp[100001][2];

    long long solve(int i , bool prev , vector <int> &nums){
        if(i == n)
            return 0;
        if(dp[i][prev] != -1)
            return dp[i][prev];

        bool curr = nums[i] % 2;

        ll skip = solve(i + 1 , prev , nums);

        ll take = nums[i] + solve(i + 1 , curr , nums);

        if(prev != curr)
            take -= x;

        return dp[i][prev] = max(take , skip);
    }
    long long maxScore(vector<int>& nums, int X) {
        n = nums.size() , x = X;
        memset(dp , -1 , sizeof(dp));
        return nums[0] + solve(1 , nums[0] % 2 , nums);
    }
};

/*
given an array and integer x
start at index 0
can go to any later index j < n and receive nums[j] score
if source and destination element are of different parity, lose score of x
return max score
Seems like a DP problem?
can go to any later index and calculate score such that you start at that index(subproblem)
*/