class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size() , ans = INT_MAX;
        deque <int> d;
        vector <long long> pref(n);
        for(int right = 0 ; right < n ; right++){
            pref[right] = (right == 0 ? nums[right] : pref[right - 1] + nums[right]);
            if(pref[right] >= k)
                ans = min(ans , right + 1);
            while(not d.empty() and pref[right] - pref[d.front()] >= k){
                ans = min(ans , right - d.front());
                d.pop_front();
            }
            while(not d.empty() and pref[right] <= pref[d.back()])
                d.pop_back();
            d.push_back(right);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};