class Solution {
public:
    vector <int> dp;
    int solve(int i , vector <vector<int>> &offers){
        int n = offers.size();
        if(i == n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int notTake = solve(i + 1 , offers);
        int low = i + 1 , high = n - 1 , mid , nextI = n;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(offers[mid][0] > offers[i][1])
                nextI = mid , high = mid - 1;
            else low = mid + 1;
        }
        // vector <int> target = {offers[i][1] , INT_MAX};
        // nextI = upper_bound(offers.begin() + i + 1 , offers.end() , target) - offers.begin();
        int take = offers[i][2] + solve(nextI , offers);
        return dp[i] = max(take , notTake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        dp.resize(offers.size() , -1);
        sort(offers.begin() , offers.end());
        return solve(0 , offers);
    }
};

/*
what if some houses are sold for i'th buyer want to buy? If any house is previously sold, we can't sell it to i'th buyer.
seems like a DP problem take/notTake/knapsack 
if we choose the i'th buyer out to choose the next buyer? ensuring 
their intended house don't clash? could do a linear search
storing the interval and manually check all. Or we can do binary search to find 
next earliest non-overlapping interval.
*/