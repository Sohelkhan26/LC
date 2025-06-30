class Solution {
public:
    int width;
    int dp[1001][1001];
    int solve(int i , int maxH , int remW , vector<vector<int>> &books){
        if(i == books.size())
            return maxH;
        if(dp[i][remW] != -1)
            return dp[i][remW];
        int take = INT_MAX , skip = INT_MAX;
        int w = books[i][0] , h = books[i][1];
        if(remW - w >= 0){
            int newH = max(maxH , h);
            int newW = remW - w;
            take = max(newH , solve(i + 1 , newH , newW , books));
        }
        skip = maxH + solve(i + 1 , h , width - w , books);
        return dp[i][remW] = min(take , skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        width = shelfWidth;
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , width , books);
    }
};