class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0 , n = nums.size();
        for(int i = 0 ; i < n - 2 ; i++)
            if(nums[i] == 0)
                nums[i] ^= 1 , nums[i + 1] ^= 1 , nums[i + 2] ^= 1 , ans++;
        for(int i : nums)
            if(not i)
                return -1;
        return ans;
    }
};