class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector <int> nums;
        for(auto it : grid)
            for(int i : it)
                nums.push_back(i);
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n ; i++)
            if(nums[i] % x != nums[0] % x)
                return -1;
        int ans = INT_MAX , total = accumulate(nums.begin() , nums.end() , 0ll) , pref = 0;
        for(int i = 0 ; i < n ; i++){
            int leftCost = nums[i] * i - pref;
            int rightCost = (total - pref) - (nums[i] * (n - i));
            int operation = (leftCost + rightCost) / x;
            ans = min(ans , operation);
            pref += nums[i];
        }
        return ans;
    }
};