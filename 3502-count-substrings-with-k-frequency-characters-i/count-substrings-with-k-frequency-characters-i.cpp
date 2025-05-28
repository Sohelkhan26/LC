class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size() , ans = 0;
        vector<int> count(26);
        auto valid = [&](){
            for(int &i : count)
                if(i >= k)
                    return true;
            return false;
        };
        for(int left = 0 , right = 0 ; right < n ; right++){
            count[s[right] - 'a']++;
            while(valid()){
                ans += (n - right);
                count[s[left++] - 'a']--;
            }
        }
        return ans;
    }
};