class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map <int,vector <int>> freq;
        int n = nums.size() , ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            freq[nums[i]].push_back(i);
        }
        for(auto &[num , pos] : freq){
            int m = pos.size() , gap = (n - 1 - pos.back() + 1) + pos[0];
            for(int i = 1 ; i < m ; i++)
                gap = max(gap , pos[i] - pos[i - 1]);
            ans = min(ans , gap);
        }
        return ans / 2;
    }
};
