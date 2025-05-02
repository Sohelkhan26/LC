class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        set <pair<int,int>> vis;
        for(auto &p : points){
            //x1 , y1 , x2 , y2 are diagonal points.
            int x1 = p[0] , y1 = p[1];
            for(auto &[x2 , y2] : vis){
                if(vis.contains({x1 , y2}) and vis.contains({x2 , y1})) 
                    ans = min(ans , abs(x1 - x2) * abs(y1 - y2)); 
            }
            vis.insert({x1 , y1});
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

/*
Awesome problem. This solution effectively finds out all possible rectangles.
For every point in points, fix one point as it's diagonal point, now for these two points, if more two points exist in line with these two, then a rectangle can be formed.
*/