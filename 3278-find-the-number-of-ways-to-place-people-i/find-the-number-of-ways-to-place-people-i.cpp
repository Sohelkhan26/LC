class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size() , ans = 0;
        sort(points.begin() , points.end());
        for(int a = 0 ; a < n ; a++){
            int x1 = points[a][0] , y1 = points[a][1];
            for(int b = 0 ; b < n ; b++){
                if(a == b)
                    continue;
                int x2 = points[b][0] , y2 = points[b][1];
                bool ok = false;
                if(x1 <= x2 and y1 >= y2)
                    ok = true;
                for(int i = 0 ; i < n ; i++){ // find in - between points.
                    if(i == a or i == b)
                        continue;
                    int x3 = points[i][0] , y3 = points[i][1];
                    if(x1 <= x3 and x3 <= x2 and
                       y2 <= y3 and y3 <= y1) // made mistake here , b is lower than a
                        ok = false;
                }
                ans += ok;
            }
        }
        return ans;
    }
};

/*
count pair of points such that first point is on the upper-left side of b and no point in-between
a[0] <= b[0] (a is left of b)
a[1] >= b[1] (a is upper of b)
Points are distinct. Pairs can form a line? what does it mean? a , b can be on same line horizontally or vertically , not both(then same point).
Sort to handle in-between points?
n is small. brute force? 2 loop to compare pair, another to find out in-between point.
*/