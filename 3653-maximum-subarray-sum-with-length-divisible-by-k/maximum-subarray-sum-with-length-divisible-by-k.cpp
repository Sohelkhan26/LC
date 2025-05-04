class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector <long long> pref = {0};
        for(int &n : nums)
            pref.push_back(pref.back() + n);
        long long ans = LLONG_MIN , n = nums.size();
        for(int s = 0 ; s < k ; s++){
            long long sum = 0;
            for(int i = s ; i + k <= n ; i += k){
                long long subarraySum = pref[i + k] - pref[i];
                sum = max(sum + subarraySum , subarraySum);
                ans = max(ans , sum);
            }
        }
        return ans;
    }
};
/*
This approach is great, Uses Kadane. Kadane algo is used to find maximum sum of a subarry. But in this problem one additional constraint. Length of that subarray should be divisible by k.
This approach starts kadane in range [0..k - 1] because remainder is in this range. Every other subarray will fall in this remainder.
Prefix sum used to calculate subarray sum in O(1). One padding is used.
So, instead of writing pref[i + k - 1] - pref[i - 1] and checking for valid i
pref[i + k] - pref[i] is written. Bigger K less time.
*/