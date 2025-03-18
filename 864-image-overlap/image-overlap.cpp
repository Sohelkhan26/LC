class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size() , ans = 0;
        vector <pair<int,int>> a , b;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(img1[i][j])
                    a.push_back({i , j});
                if(img2[i][j])
                    b.push_back({i , j});
            }
        }
        map <pair<int,int>,int> freq;
        for(auto [x1 , y1] : a)
            for(auto [x2 , y2] : b){
                int diffX = x1 - x2 , diffY = y1 - y2;
                ans = max(ans , ++freq[{diffX , diffY}]);
            }
        return ans;
    }
};

/*
Map Every 1 from img1 to img2. 
freq[{x,y}] map counts how many 1 overlap with the exact same relative change {x , y} in position.
*/