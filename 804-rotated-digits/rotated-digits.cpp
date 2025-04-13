class Solution {
public:
    int rotatedDigits(int n) {
        int good = 0 , mp[] = {0 , 1 , 5 , -1 , -1 , 2 , 9 , -1 , 8 , 6};
        auto valid = [&](int n){
            string t , s = to_string(n);
            for(char &c : s){
                int d = c - '0';
                if(mp[d] == -1)
                    return false;
                t.push_back(mp[d] + '0');
            }
            return s != t;
        };
        for(int i = 1 ; i <= n ; i++)
            good += valid(i);
        return good;
    }
};