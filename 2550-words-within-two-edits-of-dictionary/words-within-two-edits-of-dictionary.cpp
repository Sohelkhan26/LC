class Solution {
public:
    struct node{
        node *child[26];
    };
    node* root;
    void add(string &s){
        node* curr = root;
        for(char &c : s){
            int i = c - 'a';
            if(curr -> child[i] == nullptr)
                curr -> child[i] = new node();
            curr = curr -> child[i];
        }
    }
    bool ok(string &s , int change , node* curr , int i){
        if(change < 0 or i == s.size())
            return change >= 0;
        bool ans = false;
        for(char c = 'a' ; c <= 'z' ; c++)
            if(curr -> child[c - 'a'])
                ans |= ok(s , change - (c != s[i]) , curr -> child[c - 'a'] , i + 1);
        return ans;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        root = new node();
        for(string &s : dictionary)
            add(s);
        vector <string> ans;
        for(string &s : queries)
            if(ok(s , 2 , root , 0))
                ans.push_back(s);
        return ans;
    }
};