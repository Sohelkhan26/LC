class Solution {
public:
    int maxDiff(int num) {
        string origin = to_string(num);
        int mx = INT_MIN , mn = INT_MAX;
        for(char o = '0' ; o <= '9' ; o++){
            for(char n = '0' ; n <= '9' ; n++){
                string mod = origin;
                for(char &c : mod)
                    if(c == o)
                        c = n;
                if(mod[0] == '0')continue;
                int val = stoi(mod);
                mx = max(mx , val);
                mn = min(mn , val);
            }
        }
        return mx - mn;
    }
};