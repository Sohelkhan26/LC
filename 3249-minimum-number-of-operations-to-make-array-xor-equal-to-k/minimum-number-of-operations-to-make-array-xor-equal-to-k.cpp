class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return __builtin_popcount(accumulate(nums.begin() , nums.end() , 0 , [&](int sum , int n){return sum xor n;}) xor k);
    }
};