class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size() , m = workers.size() , ans = -1;
        int low = 0 , high = min(n , m) , mid;
        sort(tasks.begin() , tasks.end());
        sort(workers.rbegin() , workers.rend());
        auto canDo = [&](int mid , int pills , int strength) -> bool{ // pick the first easiest tasks until mid
            multiset <int> st(workers.begin() , workers.begin() + mid); // mid log mid
            for(int i = mid - 1 ; i >= 0 ; i--){ // mid log mid
                auto w = prev(st.end());
                if(*w >= tasks[i]) 
                    st.erase(w); // erase don't accept backward iterator i.e : st.rbegin()
                else if(*w < tasks[i]){ // strongest worker can't do highest task, give pill to weakest worker
                    if(pills <= 0)
                        return false;
                    auto weak = st.lower_bound(tasks[i] - strength);
                    if(weak != st.end())
                        pills-- , st.erase(weak);
                    else return false; // no worker will be able to do work even after pill
                }
            }
            return true;
        };
        while(low <= high){  // N log N , N = min(m , n)
            mid = low + (high - low) / 2;
            if(canDo(mid , pills , strength))
                ans = mid , low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }
};

/*
Combination + Greedy. Straight up saw solution from a video.
Greedily try to do easiest tasks with strongest workers. But if they can't do that,
Pick best suitable worker to give pill to i.e : after pill, that workers strength will barely cross tasks[i]
user lower_bound to do that.
*/