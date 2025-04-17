class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first , vector<vector<int>> second) {
        if(first.empty() or second.empty())
            return {};
        int n = first.size() , m = second.size() , i = 0 , j = 0;
        vector <vector<int>> ans;
        while(i < n and j < m){
            int s1 = first[i][0] , e1 = first[i][1];
            int s2 = second[j][0] , e2 = second[j][1];
            if(s1 <= e2 and s2 <= e1) // visualizing helps understanding, try to memorize
                ans.push_back({max(s1 , s2) , min(e1 , e2)});
            if(e1 <= e2)
                i++;
            else j++;
        }
        return ans;
    }
};


/*
Main trick is incrementing the pointer.
Two case:
    ----------
-------   ------- (two or more)
or
-------   -------
    ----------
Do we apply brute force? For one interval in firstList check every interval in the secondList? We can but that's unnecessary. Both list are in sorted order. And the interval don't have common part themselves meaning j'th interval won't have common part with both i'th and (i + 1)th interval, each list of intervals is pairwise disjoint fact lets us solve this problem in two pointer method.
e1 <= e2 means i'th interval has some common part with j'th interval, and i'th interval is over before j'th interval. So, we should check the (i + 1)th interval with the j'th interval.
*/