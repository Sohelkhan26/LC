class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin() , s1.end());
        sort(s2.begin() , s2.end());
        auto check = [&](string a , string b){
            for(int i = 0 ; i < a.size() ; i++)
                if(a[i] < b[i])
                    return false;
            return true;
        };
        return check(s1 , s2) or check(s2 , s1);
    }
};