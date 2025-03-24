class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n = maze.size() , m = maze[0].size();
        queue <pair<int,int>> q;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(maze[i][j] == '.' and not (i == e[0] and j == e[1]))
                    if(i == 0 or i == n - 1 or j == 0 or j == m - 1)
                        q.push({i , j}) , maze[i][j] = '+';
        int path = 0;
        while(not q.empty()){
            int s = q.size();
            while(s--){
                auto [x , y] = q.front(); q.pop();
                if(x == e[0] and y == e[1])
                    return path;
                for(auto [dx , dy] : vector<pair<int,int>> {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}}){
                    int newX = x + dx , newY = y + dy;
                    if(min(newX , newY) >= 0 and newX < n and newY < m and maze[newX][newY] != '+')
                        q.push({newX , newY}) , maze[newX][newY] = '+';
                }
            }
            path++;
        }
        return -1;
    }
};

/*
Use multisource BFS. Push all border open cells and start traversing. If the entrance is encountered, return the path.
*/