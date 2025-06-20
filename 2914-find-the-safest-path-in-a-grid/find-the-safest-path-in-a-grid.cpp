class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();

        vector<vector<int>> dist(n , vector<int> (m , INT_MAX));
        auto good = [&](int i , int j){
            return min(i , j) >= 0 and i < n and j < m;
        };
        queue <pair<int,int>> q;
        int path[6] = {1 , 0 , -1 , 0 , 1};
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j])
                    q.push({i , j}) , dist[i][j] = 0;

        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto [i , j] = q.front(); q.pop();
                for(int k = 0 ; k < 4 ; k++){
                    int newI = i + path[k] , newJ = j + path[k + 1];
                    if(good(newI , newJ) and dist[newI][newJ] == INT_MAX){
                        q.push({newI , newJ});
                        dist[newI][newJ] = dist[i][j] + 1;
                    }
                }
            }
        }
        auto valid = [&](int mid){ // try to find a path such that min(dist[i][j]) along the path <= mid
            queue <pair<int,int>> q;
            vector<vector<bool>> vis(n , vector<bool> (m));
            q.push({0 , 0});
            if(dist[0][0] < mid)
                return false;
            while(not q.empty()){
                int len = q.size();
                while(len--){
                    auto [i , j] = q.front(); q.pop();
                    if(i == n - 1 and j == m - 1)
                        return true;
                    for(int k = 0 ; k < 4 ; k++){
                        int newI = i + path[k] , newJ = j + path[k + 1];
                        if(good(newI , newJ) and vis[newI][newJ] == false and dist[newI][newJ] >= mid){
                            q.push({newI , newJ});
                            vis[newI][newJ] = true;
                        }
                    }
                }
            }
            return false;
        };
        int low = 0 , high = max(n , m) , ans = -1 , mid;
        while(low <= high){ // binary search over max safeness factor
            mid = low + (high - low) / 2;
            if(valid(mid))
                ans = mid , low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};