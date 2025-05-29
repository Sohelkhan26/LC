class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector <int> up(n + 1 , INT_MAX) , down(n + 1 , -1) , left(n + 1 , INT_MAX) , right(n + 1 , -1);
        for(auto &it : buildings){
            int x = it[0] , y = it[1];
            up[x] = min(up[x] , y); // store top-most building at position x(vertically)
            down[x] = max(down[x] , y);
            left[y] = min(left[y] , x); // store left-most building at position y(horizontally)
            right[y] = max(right[y] , x);
        } 
        int ans = 0;
        for(auto &it : buildings){
            int x = it[0] , y = it[1];
            if(x > left[y] and x < right[y] and y > up[x] and y < down[x])
                ans++;
        }
        return ans;
    }
};

/*
left[y] means left-most building at height  y(along the horizontal line)
up[x] means top-most building at width x(along the vertical line)
*/