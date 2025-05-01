class Solution {
public:
    int dp[51][51];
    int solve(int left , int right , vector <int> &values){
        if(dp[left][right] != -1)
            return dp[left][right];
        int ans = INT_MAX;
        for(int i = left + 1 ; i < right ; i++)
            ans = min(ans , values[left] * values[i] * values[right] 
                            + solve(left , i , values)  // not solve(left + 1 , i) cause : same pair of vertex (left , right) can create different triangle based on various values of middle vertext i
                            + solve(i , right , values));
        return dp[left][right] = (ans == INT_MAX ? 0 : ans);
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , values.size() - 1 , values);
    }
};

/*
It's said to be a matrix triangulation problem.
Based on the order of multiplying number of operation varies, although the result matrix remains the same.
4 X 5 , 5 X 10 , 10 X 2
(a * b) * c = 4 * 5 * 5 * 10 + (4 * 10 * 10 * 2) = 1800 operation
a * (b * c) = 4 * 5 * 5 * 2 + (5 * 10 * 10 * 2) = 1200 operation
We have to form every possible traingle and take min result.
To form a triangle , we need three vertex. In this problem we fix two vertex and iterate in between for the third one. We need to fix two sides, based on the third one, diff triangle is formed.
Working without fixing two sides may be troublesome.
You need three vertices to form a triangle, and to track which part of the polygon you're triangulating, you must define a segment.

Without left and right, you can't represent which part of the polygon you're solving.
*/