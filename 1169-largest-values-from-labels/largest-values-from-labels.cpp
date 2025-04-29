class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int ans = 0;
        priority_queue <pair<int,int>> pq;
        for(int i = 0 ; i < values.size() ; i++)
            pq.push({values[i] , labels[i]});
        unordered_map <int,int> cnt;
        for(int i = 0 ; i < numWanted and not pq.empty() ; ){  
            if(++cnt[pq.top().second] <= useLimit)
                ans += pq.top().first , i++;
            pq.pop();
        }
        return ans;
    }
};