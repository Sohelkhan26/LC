class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set <int> compress;
        for(auto &pos : positions)
            compress.insert({pos[0] , pos[0] + pos[1] - 1});
        int t = 0 , maxH = 0;
        unordered_map <int,int> idx;
        for(const int& x : compress)
            idx[x] = t++;
        vector <int> heights(t) , ans;
        for(auto &p : positions){
            int left = idx[p[0]] , right = idx[p[0] + p[1] - 1] , height = 0; // [left , right] range is affected by this square 
            for(int i = left ; i <= right ; i++) // this square is going to fall on the highest stack in this range
                height = max(height , heights[i]);
            height += p[1]; // after falling height increases by side length
            for(int i = left ; i <= right ; i++) // even if there are smaller stack in this range, future square will fall on the highest stack. There could be some distance between smaller and highest stack depending on input.
                heights[i] = height; 
            maxH = max(height , maxH); // maxH is the highest stack across the x-axis
            ans.push_back(maxH);
        }
        return ans;
    }
};