class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector <pair<string,string>> letterLogs;
        vector <string> digitLogs , ans;
        for(string &s : logs){
            int i = s.find(' ');
            if(isalpha(s[i + 1]))
                letterLogs.push_back({s.substr(0 , i) , s.substr(i + 1)});
            else digitLogs.push_back(s);
        }
        sort(letterLogs.begin() , letterLogs.end() , [&](auto a , auto b){
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        for(auto &[id , content] : letterLogs)
            ans.push_back(id + " " + content);
        for(auto &s : digitLogs)
            ans.push_back(s);
        return ans;
    }
};
/*
At first seemed so hard. But idea is quite simple.
digit-logs should maintain their original ordering. So, we don't need to sort them at all.
Just sort the letter-logs. Seperate their identifiers and content, and if their contents are same, sort by identifiers.
*/