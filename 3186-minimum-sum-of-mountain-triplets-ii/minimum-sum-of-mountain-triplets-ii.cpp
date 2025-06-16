class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int ans = INT_MAX , n = nums.size() , left = nums[0];
        vector <int> right(n);
        right[n - 1] = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--)
            right[i] = min(nums[i] , right[i + 1]);
        for(int peak = 1 ; peak < n - 1 ; peak++){
            if(left < nums[peak] and nums[peak] > right[peak + 1])
                ans = min(ans , left + nums[peak] + right[peak + 1]);
            left = min(left , nums[peak]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};