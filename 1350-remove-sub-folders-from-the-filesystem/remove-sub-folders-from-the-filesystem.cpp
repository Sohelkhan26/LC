class Solution {
public:
    struct node{
        unordered_map <char,node*> child;
        bool end; 
    };
    node *root;
    bool isSubFolder(string s){
        node *curr = root;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            if(c == '/' and curr -> end) // there was a previous folder that ended here
// and this string "s" has suffix folder name, so "s" is a subfolder
                return true;
            if(curr -> child[c] == nullptr)
                curr -> child[c] = new node();
            curr = curr -> child[c];
        }
        curr -> end = true;
        return false; // didn't return earlier so it's new folder
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin() , folder.end()); // sort for processing lexicographically
        root = new node();
        vector <string> ans;
        for(string &s : folder)
            if(not isSubFolder(s))
                ans.push_back(s);
        return ans;
    }
};

/*
string "t" is a subfolder of string "s" if "s" is a prefix of string "t".
Used trie for better time complexity.
*/