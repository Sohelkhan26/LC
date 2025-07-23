class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector <bool> prime(n + 1 , true);
        prime[0] = prime[1] = false;
        for(int i = 2 ; i < n ; i++){
            if(prime[i]){
                for(long long j = 1LL * i * i ; j < n ; j += i)
                    prime[j] = false;
            }
        }

        long long a = 0 , b = 0;
        for(int i = 0 ; i < n ; i++)
            prime[i] ? a += nums[i] : b += nums[i];
        return abs(a - b);
    }
};