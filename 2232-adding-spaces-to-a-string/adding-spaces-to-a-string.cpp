class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        set <int> leave(spaces.begin() , spaces.end());
        string ans;
        for(int i = 0 ; i < s.size() ; i++){
            if(leave.contains(i))
                ans.push_back(' ');
            ans.push_back(s[i]);
        }
        return ans;
    }
};