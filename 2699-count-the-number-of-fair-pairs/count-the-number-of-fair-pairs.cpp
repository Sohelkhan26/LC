class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin() , nums.end());
        long long ans = 0 , n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int low = lower_bound(nums.begin() + i + 1 , nums.end() , lower - nums[i]) - nums.begin();
            int high = upper_bound(nums.begin() + i + 1 , nums.end() , upper - nums[i]) - nums.begin();
            ans += 1ll * (high - low);
        }
        return ans;
    }
};

/*
Problem is to find how many elements can be added to nums[i] such that it fits in the range [lower , upper], i = 0..n
So, for every i , we find j > i , that's why we add nums.begin() + i + 1
We could do the other way around (i > j), but all indices should fulfill the condition.
If we didn't add i + 1 , then every pair would have been counted twice. That's also acceptable just return ans / 2
*/