class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans;
        vector<pair<int,int>> v;
        for(int i = 0 ; i < n ; i++)
            v.push_back({intervals[i][0] , i});
        sort(v.begin() , v.end());
        for(auto it : intervals){
            int s = it[0] , e = it[1];
            pair<int,int> target = {e , INT_MIN};
            auto i = lower_bound(v.begin() , v.end() , target);
            ans.push_back(i == v.end() ? -1 : i -> second);
        }
        // map <int,int> mp;
        // for(int i = 0 ; i < n ; i++)
        //     mp[intervals[i][0]] = i;
        // for(auto it : intervals){
        //     int e = it[1];
        //     auto i = mp.lower_bound(e);
        //     ans.push_back(i == mp.end() ? -1 : i -> second);
        // }
        return ans;
    }
};

/*
lower bound is used to find a value not less than the target value.
find a value greater than or equal to the target value.
So, sort the interval with their original index. For every "end" find the first value that is greater than or equal to "end"
*/