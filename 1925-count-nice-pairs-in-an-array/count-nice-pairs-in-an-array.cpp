class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int ans = 0 ,  mod = 1e9 + 7;
        unordered_map <int,int> count;
        auto rev = [](int a) -> int{
            int ans = 0;
            while(a){
                ans = ans * 10 + a % 10;
                a /= 10;
            }
            return ans;
        };
        for(int i : nums)
            ans = (ans + count[i - rev(i)]++) % mod;
        return ans;
    }
};