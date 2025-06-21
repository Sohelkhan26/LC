class Solution {
public:
    typedef long long ll;
    #define inf 1e12
    ll dp[1001][501][3];
    long long solve(int i , int k , int type , vector<int> &price){
        if(i == price.size()) // type = 1/2 means we have unsold stock. which minimize profit -> undesirable
            return k >= 0 and type == 0 ? 0 : -inf;
        if(dp[i][k][type] != -1)
            return dp[i][k][type];
        ll take = -inf , dontTake = -inf;
        if(k > 0){ 
            if(type == 1) // bought before, sell now
                take = price[i] + solve(i + 1 , k - 1 , 0 , price);
            if(type == 2) // sold before , buy now
                take = -price[i] + solve(i + 1 , k - 1 , 0 , price);
            else if(type == 0) take = max(
                -price[i] + solve(i + 1 , k , 1 , price), // buy now, sell later
                price[i] + solve(i + 1 , k , 2 , price) // sell now buy later
            ); // decrease k when 1 transaction is complete.
        }
        dontTake = solve(i + 1 , k , type , price);
        return dp[i][k][type] = max(take , dontTake);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , k , 0 , prices);
    }
};

/*
at each index, have three choice:
buying decrease our profit
buying i'th stock = -price[i] added to answer
1. skip
2. buy now , sell later -price[i] + solve(i + 1)
3. sell now , buy later , +price[i] + solve(i + 1) confused? should there be - sign before solve() ?
the answer will be calculated as an sequence
-price[i] + price[j] - price[k] + price[f].... blah blah
So, if we sell at index i , +price[i]
at i + 1 we check which choice did we make previously
if it's type 2:(sold before , have to buy now)
we do -price[i + 1](buying decrease profit)
So, at the end answer is calculated as a series of +,-
*/