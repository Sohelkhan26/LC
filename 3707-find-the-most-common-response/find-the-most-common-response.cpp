class Solution {
public:
    int maxCount = 0;
    string ans;
    struct node{
        unordered_map <char,node*> child;
        int end;
        node() : end(0){}
    };
    node* root;
    void add(const string &s){
        node* curr = root;
        for(const char &c : s){
            if(curr -> child[c] == nullptr)
                curr -> child[c] = new node();
            curr = curr -> child[c];
        }
        curr -> end++;
        if(curr -> end > maxCount)
            ans = s , maxCount = curr -> end;
        else if(curr -> end == maxCount)
            ans = min(ans , s);
    }
    string findCommonResponse(vector<vector<string>>& responses) {
        root = new node();
        for(auto &r : responses){
            set <string> st(r.begin() , r.end());
            for(const string &s : st)
                add(s);
        }
        return ans;
    }
};