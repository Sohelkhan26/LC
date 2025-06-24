class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector <int> ans;
        set <int> nodes;
        for(int i = 0 ; i < n ; i++)
            nodes.insert(i);
        for(auto &q : queries){
            int left = q[0] , right = q[1];
            nodes.erase(nodes.lower_bound(left + 1) , nodes.upper_bound(right - 1));
            ans.push_back(nodes.size() - 1);
        }
        return ans;
    }
};

/*
The condition q[i] = (x1 , y1) , q[j] = (x2 , y2)
x1 < x2 < y1 < y2 can't be possible.
meaning there will be no starting node in future query such that it is in the middle of another query in the past. No partial overlapping. This was key fact to solve this. But even after knowing it I couldn't.

Observation: shortest distance is count(nodes) - 1. It's given in the problem description that there are n - 1 edges, and each new query will only decrease edge-count.
So each new query will make the middle nodes redundant.
erase(start , end) removes in range [start , end) excluding the last pointer.
*/