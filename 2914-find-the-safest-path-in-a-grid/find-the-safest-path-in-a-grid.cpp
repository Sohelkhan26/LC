class Solution {
public:
    typedef pair<int,int> P;
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();

        vector<vector<int>> dist(n , vector<int> (m , INT_MAX));
        // dist[i][j] distance to nearest thief
        queue <P> q;

        if(grid[0][0] == 1 or grid[n - 1][m - 1] == 1)
            return 0; 

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j])
                    q.push({i , j}) , dist[i][j] = 0;

        auto valid = [&](int i , int j){
            return min(i , j) >= 0 and i < n and j < m;
        };

        int path[6] = {1 , 0 , -1 , 0 , 1};
        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto [i , j] = q.front(); q.pop();
                for(int k = 0 ; k < 4 ; k++){
                    int newI = i + path[k] , newJ = j + path[k + 1];
                    if(valid(newI , newJ) and dist[newI][newJ] == INT_MAX){
                        q.push({newI , newJ});
                        dist[newI][newJ] = dist[i][j] + 1;
                    }
                }
            }
        }
        priority_queue <array<int,3>> pq; // find the farthest path from any thief
        pq.push({dist[0][0] , 0 , 0}); // min(dist[i][j]) along the path is max
        vector<vector<bool>> vis(n , vector<bool> (m));
        while(not pq.empty()){
            auto t = pq.top() ; pq.pop();
            int d = t[0] , i = t[1] , j = t[2];
            if(i == n - 1 and j == m - 1)
                return d;
            for(int k = 0 ; k < 4 ; k++){
                int newI = i + path[k] , newJ = j + path[k + 1];
                if(valid(newI , newJ) and not vis[newI][newJ]){
                    pq.push({min(d , dist[newI][newJ]) , newI , newJ});
                    vis[newI][newJ] = true;
                }
            }
        }
        return 0;
    }
};