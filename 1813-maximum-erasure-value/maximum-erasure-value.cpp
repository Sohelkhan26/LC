class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size() , ans = 0 , window = 0;
        unordered_map <int,int> freq;
        for(int left = 0 , right = 0 ; right < n ; right++){
            freq[nums[right]]++;
            window += nums[right];
            while(freq[nums[right]] > 1){
                window -= nums[left];
                if(--freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }
            ans = max(ans , window);
        }
        return ans;
    }
};