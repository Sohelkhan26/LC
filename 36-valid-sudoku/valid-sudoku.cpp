class Solution {
public:
    int n;
    vector<set<int>> row , col;
    bool solve(int i , int j , vector<vector<char>> &board , set <pair<int,int>> &vis){
        set <int> square;
        if(vis.contains({i , j}))
            return true;
        for(int di = 0 ; di < 3 ; di++){
            for(int dj = 0 ; dj < 3 ; dj++){
                int newI = i + di , newJ = j + dj;
                if(newI >= n or newJ >= n)
                    return true;
                if(board[newI][newJ] == '.')
                    continue;
                int val = board[newI][newJ] - '0';
                board[newI][newJ] = '.';
                if(not row[newI].insert(val).second)
                    return false;
                if(not col[newJ].insert(val).second)
                    return false;
                if(not square.insert(val).second)
                    return false;
            }
        }
        // vis.insert({i + 3 , j});
        // vis.insert({i , j + 3});
        // vis.insert({i + 3 , j + 3});
        return solve(i + 3 , j , board , vis) and solve(i , j + 3 , board , vis) and
        solve(i + 3 , j + 3 , board , vis);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        n = board.size();
        row.resize(n);
        col.resize(n);
        set <pair<int,int>> vis;
        return solve(0 , 0 , board , vis);
    }
};