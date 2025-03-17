class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin() , nums.end()) , high = accumulate(nums.begin() , nums.end() , 0) , mid , ans = -1;
        auto canSplit = [&](int largest){
            int subArray = 0 , sum = 0;
            for(int i : nums){
                if(sum + i > largest){
                    subArray++;
                    sum = i;
                }else sum += i;
            }  
            return subArray + 1 <= k;
        };
        while(low <= high){
            mid = low + (high - low) / 2;
            if(canSplit(mid)){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};

/*
Same as this:
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
If we can split the array into less than "k" subarrays with mid as largest value, we can easily split it into exactly "k" subarrays. Then the largest sum will be lesser. I don't properly understand how the binary search finds out exacty largest sum. 
*/