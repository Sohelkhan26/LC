class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map <double,int> freq;
        long long ans = 0;
        for(auto it : rectangles){
            double w = it[0] , h = it[1];
            ans += freq[w / h]++;
        }
        return ans;
    }
};