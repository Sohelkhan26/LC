class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        long long total = accumulate(tasks.begin() , tasks.end() , 0LL , [&](long long sum , auto &a){
            return sum + a[0];
        });
        long long low = total , high = 1e13 , mid , ans = -1;
        sort(tasks.begin() , tasks.end() , [&](auto &a , auto &b){
            return abs(a[1] - a[0]) > abs(b[1] - b[0]); // Main trick. There is no way to minimze total energy needed. At least sum(actual) energy is needed that's for sure. But at least minimum[i] is required to start the i'th task. Sorting by descending min[i] don't work. I think this is intuitive but I saw some hint. Which ever tasks needs bigger starting initial energy compared to others is the meaning of this sort i guess?.
        });
        while(low <= high){
            mid = low + (high - low) / 2;
            bool ok = true;
            long long energy = mid;
            for(auto &t : tasks){
                if(t[1] > energy){
                    ok = false;
                    break;
                }
                energy -= t[0];
            }
            if(ok)
                ans = mid , high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};