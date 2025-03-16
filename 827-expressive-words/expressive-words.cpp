class Solution {
public:
    vector <pair<char,int>> compress(string s){
        int cnt = 1 , n = s.size();
        vector <pair<char,int>> S;
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] == s[i - 1])
                cnt++;
            else{
                S.push_back({s[i - 1] , cnt});
                cnt = 1;
            }
        }
        S.push_back({s[n - 1] , cnt});
        return S;
    }
    vector <pair<char,int>> a;
    bool solve(string c){
        auto b = compress(c);
        if(a.size() != b.size())
            return false;
        for(int i = 0 ; i < a.size() ; i++){
            if(a[i].first != b[i].first)
                return false;
            else if(a[i].second < 3 and a[i].second != b[i].second)
                return false;
            else if(a[i].second < b[i].second)
                return false;
        }
        return true;
    }
    int expressiveWords(string s, vector<string>& words) {
        a = compress(s);
        for(auto it : a)
            cout << it.first << ' ' << it.second << endl;
        int ans = 0;
        for(string c : words)
            ans += solve(c);
        return ans;
    }
};