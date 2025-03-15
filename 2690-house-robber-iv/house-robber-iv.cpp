class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size() , low = 1 , high = 1e9 , mid , ans = -1;
        auto steal = [&](int mid) -> bool{
            int robbed = 0;
            for(int i = 0 ; i < n ; i++){
                if(nums[i] <= mid)
                    robbed++ , i++;
            }
            return robbed >= k;
        };
        while(low <= high){
            mid = low + (high - low) / 2;
            if(steal(mid)){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};

/*
Can't steal from adjacent homes.
Capability -> max(house) robbed.
Can steal from k or more houses. 
Always possible to steal from at least k house.
Return minimum capability out of all possible sequence of robbing houses.
Clearly min-max problem, so we require binary search.
Check funtion is somewhat complicated. 
Binary seach over the answer, i.e: min capability. So we have to find at least one sequence that has all the elements less than or equal to the mid. 
If we take one element we will skip the next element. 
If there exits a sequence, try to look for a lesser capability as we are required to find
min capability. 
*/