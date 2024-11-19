class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0 , windowSum = 0;
        int n = nums.size();
        unordered_map <int,int> freq;
        for(int i = 0 ; i < n ; i++){
            windowSum += nums[i];
            freq[nums[i]]++;
            if(i >= k - 1){
                if(freq.size() == k)
                    ans = max(ans , windowSum);
                windowSum -= nums[i - (k - 1)];
                if(--freq[nums[i - (k - 1)]] == 0)
                    freq.erase(nums[i - (k - 1)]);
            }
        }
        return ans;
    }
};