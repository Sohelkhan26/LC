class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue <pair<int,int> , vector<pair<int,int>> , greater<> > pq;
        for(int i = 0 ; i < nums.size() ; i++)
            pq.push({nums[i] , i});
        while(k--){
            auto [t , i] = pq.top(); pq.pop();
            pq.push({t * multiplier , i});
        }
        while(not pq.empty()){
            nums[pq.top().second] = pq.top().first; pq.pop();
        }
        return nums;
    }
};