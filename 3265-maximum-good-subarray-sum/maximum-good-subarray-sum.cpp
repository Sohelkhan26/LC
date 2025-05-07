class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map <int,long long> minPref;
        long long pref = 0 , ans = LLONG_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            long long prev = (minPref.contains(nums[i]) ? minPref[nums[i]] : LLONG_MAX);
            if(prev > pref)
                minPref[nums[i]] = pref; // after updating minPref , prefixSum was updated.
            pref += nums[i];
            int t1 = nums[i] + k , t2 = nums[i] - k;
            if(minPref.contains(t1))
                ans = max(ans , pref - minPref[t1]);
            if(minPref.contains(t2))
                ans = max(ans , pref - minPref[t2]);
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};

/*
Almost like a sliding window. Solved problems with similar patterns.
If a sum repeats itself , then the subarray in-between has sum = 0.
Same for this problem. 
abs(sub[first] - sub[last]) == k
So, for any ending point "i" , starting point can be nums[i] - k or nums[i] + k.
If any starting point was previously encountered before then the subarray in-between is good, Only thing left to find is the sum of the subarray. To do that efficiently prefix Sum was used. If nums[i] - k(say j'th index) was seen before then ,  subarry = [j .. i] is good. And subarray sum is = pref - minPref[j]
minPref[j] is sum excluding the j'th element (because of the way minPref was updated in the code.) , "pref" is sum including nums[i].
To maximize the sum, If for same number nums[i], minimum prefix sum was recorded.
*/