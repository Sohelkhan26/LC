class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int path[6] = {1 , 0 , -1 , 0 , 1} , n = matrix.size() , m = matrix[0].size();
        unordered_map <char,vector<pair<int,int>>> teleport;
        auto dist = [&](int i , int j){
            return n - 1 - i + m - 1 - j;
        };
        auto valid = [&](int i , int j){
            return i >= 0 and i < n and j >= 0 and j < m;
        };
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                char c = matrix[i][j];
                if(c == '.' or c == '#')
                    continue;
                teleport[c].push_back({i , j});
            }
        }

        int time = 0;
        queue <pair<int,int>> q;
        if(teleport.contains(matrix[0][0])){
            for(auto &[x , y] : teleport[matrix[0][0]])
                q.push({x , y});
        }
        
        q.push({0 , 0});
        matrix[0][0] = '#';

        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto [i , j] = q.front(); q.pop();
                if(i == n - 1 and j == m - 1)
                    return time;
                
                for(int k = 0 ; k < 4 ; k++){
                    int newI = i + path[k] , newJ = j + path[k + 1];
                    if(valid(newI , newJ) and matrix[newI][newJ] != '#'){
                        char c = matrix[newI][newJ];
                        if(teleport.contains(c)){
                            for(auto &[x , y] : teleport[c]){
                                q.push({x , y});
                                matrix[x][y] = '#';
                            }
                            teleport.erase(c);
                        }else{
                            q.push({newI , newJ});
                            matrix[newI][newJ] = '#';
                        }
                    }
                }
            }
            time++;
        }
        return -1;
    }
};

/*
Given a m * n grid.
# -> obstacle , '.' -> empty , A-Z teleport letter
start at (0,0) want to go to (m - 1 , n - 1) in min move can move 4 directoins
if stepped on a letter, can move to any other cell containing that letter.
In one path, each letter can be used 1 time only.
Note: character, not cell. i.e : at most 26 teleport

*/