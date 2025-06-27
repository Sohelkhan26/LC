class Solution {
public:
    unordered_map <int,int> freq;
    int dir[5] = {1 , 0 , -1 , 0 , 1} , group = 2 , n , m;
    bool valid(int i , int j){
        return min(i , j) >= 0 and i < n and j < m;
    }
    void dfs(int i , int j , vector<vector<int>> &grid){
        freq[grid[i][j] = group]++;
        for(int k = 0 ; k < 4 ; k++){
            int newI = i + dir[k] , newJ = j + dir[k + 1];
            if(valid(newI , newJ) and grid[newI][newJ] == 1)
                dfs(newI , newJ , grid);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j] == 1)
                    dfs(i , j , grid) , group++;
        int ans = 0;
        for(auto &[g , cnt] : freq)
            cout << g << ' ' << cnt << endl;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0){
                    set <int> unique;
                    int temp = 0;
                    for(int k = 0 ; k < 4 ; k++){
                        int newI = i + dir[k] , newJ = j + dir[k + 1];
                        if(valid(newI , newJ))
                            unique.insert(grid[newI][newJ]);
                    }
                    for(const int &i : unique)
                        temp += freq[i];
                    ans = max(ans , 1 + temp);
                }else ans = max(ans , freq[grid[i][j]]);
            }
        return ans;
    }
};