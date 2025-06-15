class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int ans = -1 , n = s.size() , mn = INT_MAX , mx = INT_MIN; 
        for(char c = '0' ; c <= '9' ; c++){
            for(char d = '0' ; d <= '9' ; d++){
                for(char &a : s)
                    if(a == c)
                        a = d;
                if(s[0] == '0'){
                    s = to_string(num);
                    continue;
                }
                mx = max(mx , stoi(s));
                mn = min(mn , stoi(s));
                s = to_string(num);                
            }
        } 
        return mx - mn;
    }
};