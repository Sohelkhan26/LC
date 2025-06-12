class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size() , ans = 0 , side = INT_MAX;
        unordered_map <char,int> dist;
        for(int i = 0 ; i < n ; i++){
            int len = max(abs(points[i][0]) , abs(points[i][1]));
            char c = s[i];
            if(not dist.contains(c))
                dist[c] = len;
            else if(len < dist[c]){ // len is closest to origin
                side = min(side , dist[c]); // dist[c] is 2nd closest.
                dist[c] = len;
            }else{ // len is 2nd/more closest to origin
                side = min(side , len);
            }
        }
        for(auto &[c , d] : dist)
            if(d < side)
                ans++;
        return ans;
    }
};

/*
we can include at most 26 character to satisfy non-repeating characteristics.
If a character occurs at multiple positions, we greedily try to include a character that is closest to origin. To not include the 2nd same character the square length should be < 2nd character's distance(second closest distance) from the origin.
square side is the minimum of all character's second closest distance.
*/