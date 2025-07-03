class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int prev[2] = {0 , 0} , prefix = 0 , n = arr.size() , ans = 0 , mod = 1e9 + 7;
        for(int &x : arr){
            prefix += x;
            int rem = prefix % 2;
            if(rem == 1)
                ans++;
            ans = (ans + prev[1 - rem]) % mod;
            prev[rem]++;
        }
        return ans;
    }
};