class Solution {
public:
    bool magic(int r , int c , vector<vector<int>> &grid){
        vector <int> row(3) , col(3);
        int firstDiag = 0 , secondDiag = 0;
        unordered_set <int> st;
        for(int i = r ; i < r + 3 ; i++){
            for(int j = c ; j < c + 3 ; j++){
                int val = grid[i][j];
                int I = i - r , J = j - c; // to make 0 , 1 , 2 indexing 
                if(val < 1 or val > 9 or st.contains(val))
                    return false;
                st.insert(val);
                row[I] += val;
                col[J] += val;
                if(I == J)
                    firstDiag += val;
                if((I + J) == 2)
                    secondDiag += val;
            }
        }
        for(int i = 0 ; i < 3 ; i++)
            if(row[i] != 15 or col[i] != 15)
                return false;
        return firstDiag == secondDiag and firstDiag == 15;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , ans = 0;
        for(int i = 0 ; i < n - 2 ; i++){ // ensure there are at least 3 row and columns
            for(int j = 0 ; j < m - 2 ; j++){
                ans += magic(i , j , grid);
            }
        }
        return ans;
    }
};