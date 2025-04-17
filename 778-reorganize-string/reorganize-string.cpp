class Solution {
public:
    string reorganizeString(string s) {
        unordered_map <char,int> freq;
        int n = s.size() , i = 0;
        for(char &c : s)
            if(++freq[c] > (n + 1) / 2)
                return "";
        vector <pair<int,char>> v;
        for(auto &it : freq)
            v.push_back({it.second , it.first});
        sort(v.rbegin() , v.rend());
        for(auto &[cnt , c] : v){
            while(cnt-- > 0){
                s[i] = c;
                i = (i + 2 < n ? i + 2 : 1);
            }
        }
        return s;
    }
};