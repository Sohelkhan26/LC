class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size() , limit = (1 << n);
        for(int mask = 0 ; mask < limit ; mask++){ // __int128_t int with 128 bit
            __int128_t sub[2] = {1 , 1}; // sub[0] stores unset bit product , sub[1] set bit product
            for(int j = 0 ; j < n ; j++){
                sub[((mask >> j) & 1) == 1] *= nums[j]; // (mask >> j) & 1 check if bit is set/unset
            }
            if(sub[0] == target and sub[1] == target)
                return true;
        }
        return false;
    }
};

/*
partition nums into two subsets such that product of each subset is equal to target.
*/