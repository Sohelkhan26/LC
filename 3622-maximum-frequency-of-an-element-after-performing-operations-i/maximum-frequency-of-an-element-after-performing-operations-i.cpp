class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int op) {
        int ans = 1 , n = nums.size();
        unordered_map <int,int> freq;
        for(int &i : nums)
            freq[i]++;
        sort(nums.begin() , nums.end());
        for(int i = nums[0] ; i <= nums.back() ; i++){
            int left = lower_bound(nums.begin() , nums.end() , i - k) - nums.begin();
            int right = prev(upper_bound(nums.begin() , nums.end() , i + k)) - nums.begin(); // upper_bound returns pointer to number > target. So, previous pointer value <= i + k
            ans = max(ans , freq[i] + min(right - left + 1 - freq[i] , op)); // right - left + 1 numbers can be transformed into i. subtract freq[i] to avoid double counting.
        }
        return ans;
    }
};

/*
can add [-k , +k] to any number n times.(once per number)
return max freq achieveable.
what number should i choose to add? range is big, so can't call solve function for every choice(no dp).
greedy? try to tranform current number to target number?
what if it is not possible?
every number 'i' can be in range [i - k , i + k].
For two numbers, i, j if the range intersect, they can be made equal. But can perform this operation at most n times.
They don't have to be consecutive. Sort? Then sliding window?
Or, fix a interval, count numbers that lie in that range, regardless of operation? 

We can either increase freq of an existing number, or make a new number. Making a new number will take at least 1 extra operation. 
But converting still we have to try for numbers [min , max] of nums.
case for nums = [1 , 4 , 7] , k = 2
No number can be transformed into another number present in the array.
But, we can make 1 to 3 and 4 to 3 and max freq would be 2.
So, for every number 'i' count how many numbers in nums can be transformed into that 'i' by adding [- k , +k]
*/