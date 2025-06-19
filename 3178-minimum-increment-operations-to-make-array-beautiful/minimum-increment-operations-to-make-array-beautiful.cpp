class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        long long n = nums.size() , ans = 0;
        for(int i = 1 ; i < n - 1 ; i++){
            int val = max(nums[i - 1] , max(nums[i] , nums[i + 1]));
            if(k > val){
                int minOp = k - val;
                nums[i - 1] += minOp , nums[i] += minOp , nums[i + 1] += minOp; // we don't know operation on which index will give minimum answer. So, we add to all three, so that they don't interfere in future.
                ans += minOp;
            }
        }
        return ans;
    }
};

/*
ensuring max-element in all 3 length subarray is same for all length > 3 subarray.
*/