class Solution {
public:
    int maximumLength(string s) {
        int n = s.size() , low = 1 , high = n , mid , ans = -1;
        auto valid = [&](int len){
            unordered_map <char,int> count;
            char last = '%';
            int l = 1; 
            for(char &c : s){
                l = (c == last) ? l + 1 : 1;
                last = c;
                if(l >= len) // in case of aaaaa , len = 3, count will still increase for every a after "aaa".
                    count[c]++;
            }
            for(auto &[c , cnt] : count)
                if(cnt >= 3)
                    return true;
            return false;
        };
        while(low <= high){ // binary search over the max len
            mid = low + (high - low) / 2;
            if(valid(mid)) // check if any string with max len occurs at least 3 times.
                ans = mid , low = mid + 1; // occurs, so try to increase max len.
            else high = mid - 1; // no such string found , decrease max len.
        }
        return ans;
    }
};