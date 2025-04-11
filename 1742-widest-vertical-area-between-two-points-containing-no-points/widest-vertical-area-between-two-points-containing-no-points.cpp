class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin() , points.end());
        int n = points.size() , ans = 0;
        for(int i = 1 ; i < n ; i++)
            ans = max(ans , points[i][0] - points[i - 1][0]);
        return ans;
    }
};

/*
There can be no points inside them, so other than adjacent points will break this condition. So check for largest diff(x) between adjacent points.
*/