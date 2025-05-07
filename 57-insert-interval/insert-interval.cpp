class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& in) {
        vector<vector<int>> ans;
        int i = 0 , n = intervals.size() , end = in[1] , start = in[0];
        while(i < n and intervals[i][1] < start)
            ans.push_back(intervals[i]) , i++;
        start = min(start , i < n ? intervals[i][0] : INT_MAX);
        while(i < n and end >= intervals[i][0])
            end = max(end , intervals[i][1]) , i++;
        ans.push_back({start , end});
        while(i < n)
            ans.push_back(intervals[i++]);
        return ans;
    }
};