class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0 , ans = INT_MIN;
        int n = nums.size();
        for(int left = 0 , right = 0 ; right < n ; right++){
            sum += nums[right];
            if(right - left + 1 > k)
                sum -= nums[left++];
            if(right - left + 1 == k)
                ans = max(ans , sum);
        }
        return ans / (k * 1.0);
    }
};