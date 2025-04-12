class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        int n = s.size() , t = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] >= '1' and s[i] <= '9'){
                if(i + 2 < n and s[i + 2] == '#')
                    t = (s[i] - '0') * 10 + (s[i + 1] - '0') , i += 2;
                else
                    t = s[i] - '0';
            }
            t--;
            ans.push_back(t + 'a');
        }
        return ans;;
    }
};