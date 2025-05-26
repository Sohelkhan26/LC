class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size(), ans = 0;
        for (int i = 0; i + m < n ; i++) {  
            int k = 0;
            for (int j = i + 1; j <= i + m; j++)
                if((nums[j] > nums[j - 1] ? 1 : nums[j] == nums[j - 1] ? 0 : -1) == pattern[k])
                    k++;
                else break;
            ans += (k == m);
        }
        return ans;
    }
};
