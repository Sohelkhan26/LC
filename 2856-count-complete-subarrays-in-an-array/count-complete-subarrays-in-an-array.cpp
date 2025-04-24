class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map <int,int> freq;
        int n = nums.size() , distinct = set <int> (nums.begin() , nums.end()).size() , ans = 0;
        for(int left = 0 , right = 0 ; right < n ; right++){
            freq[nums[right]]++;
            while(freq.size() == distinct){
                ans += (n - right);
                if(--freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }
        }
        return ans;
    }
};

/*
Read problem description very carefully. Count subarray that have same number of distinct elements as the "whole" array not the remaining array.
Whenever we find a valid subarray, adding more element won't make the subarray unvalid. So we get "n - right" valid subarray. Now time to shrink the window. We get "n - right" valid subarray while shrinking the window, if it has same distinct element count as the whole array.
*/