class Solution {
public:
    int longestWPI(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        vector <int> pref = {nums[0] > 8 ? 1 : -1};
        for(int i = 1 ; i < n ; i++)
            pref.push_back(pref.back() + (nums[i] > 8 ? 1 : -1)); 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(pref[j] - (i > 0 ? pref[i - 1] : 0) > 0)
                    ans = max(ans , j - i + 1);
            }
        } 
        return ans;
    }
};
/*
Interval is consecutive days?
elements >= 9 -> 1
others, -> -1?
find len of longest subarray such that sum of subarray >= 1? Kadene? if subarray sum < 0 discard? Or sliding window? shrink when sum <= 0
Sliding window seems too easy, right?
Yeah, typical one don't work.
Kadene won't work too. Prefix sum sliding window maybe?
Prefix sum with two loops should pass?
Indeed passed cause of low constraints. But barely. 2.2 seconds
*/