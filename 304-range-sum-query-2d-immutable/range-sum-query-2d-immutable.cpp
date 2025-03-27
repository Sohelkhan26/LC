class NumMatrix {
public:
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() , sum = 0;
        pref.resize(n + 1 , vector<int> (m + 1));
        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= m ; j++)
                pref[i][j] = matrix[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pref[row2 + 1][col2 + 1] - pref[row1][col2 + 1] - pref[row2 + 1][col1] + pref[row1][col1];
    }
};

/*
2D prefix sum array:
value at [i][j] represents sum of all elements that are above and left of [i][j].
One extra row and column is added to prefix sum array to avoid out of bounds problem.
For more information refer to : https://usaco.guide/silver/more-prefix-sums?lang=cpp
*/