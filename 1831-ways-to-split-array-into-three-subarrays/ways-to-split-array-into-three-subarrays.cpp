class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size() , ans = 0 , mod = 1e9 + 7;
        vector<int> pref = {nums[0]};
        for(int i = 1 ; i < n ; i++)
            pref.push_back(pref.back() + nums[i]);
        // for(int i = 0 ; i < n - 2 ; i++){
        //     int left = pref[i];
        //     int minMid = 2 * left , maxMid = (pref.back() - left) / 2;
        //     int mn = lower_bound(pref.begin() + i + 1 , pref.end() , minMid) - pref.begin();
        //     int mx = upper_bound(pref.begin() + i + 1 , pref.begin() + n - 1 , maxMid + left) - pref.begin();
        //     ans = (ans + max(--mx - mn + 1 , 0)) % mod;
        // }
        // return ans;
        for(int i = 0 ; i < n - 2 ; i++){
            int left = pref[i];
            int low = i + 1 , high = n - 2 , mid , mn = -1 , mx = -1;
            while(low <= high){
                mid = low + (high - low) / 2;
                if(pref[mid] - pref[i] >= left)
                    mn = mid , high = mid - 1;
                else low = mid + 1;
            }
            if(mn == -1)continue;
            low = mn , high = n - 2;
            while(low <= high){
                mid = low + (high - low) / 2;
                int midSum = pref[mid] - pref[i];
                int rightSum = pref.back() - pref[mid];
                if(rightSum >= midSum)
                    mx = mid , low = mid + 1;
                else high = mid - 1;
            }
            if(mx == -1)continue;
            ans = (ans + max(mx - mn + 1 , 0)) % mod;
        }
        return ans;
    }
};