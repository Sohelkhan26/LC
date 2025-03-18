class Solution {
public:
    string maskPII(string s) {
        int i = s.find('@');
        if(i == -1){
            string ans;
            for(char c : s)
                if(isdigit(c))
                    ans.push_back(c);
            int n = ans.size();
            s = n == 13 ? "+***-" : n == 12 ? "+**-" : n == 11 ? "+*-" : "";
            s.append("***-***-" + ans.substr(n - 4));
            return s;
        }else{
            transform(s.begin() , s.end() , s.begin() , ::tolower);
            return string(1 , s[0]) + "*****" + s.substr(i - 1);
        }
        return s;
    }
};