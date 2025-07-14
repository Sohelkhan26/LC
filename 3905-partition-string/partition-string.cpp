class Solution {
public:
    struct Node{
        Node* child[26] = {};
        bool isEnd = false;
    }*root , *curr;
    vector<string> partitionString(string s) {
        root = new Node(); curr = root;
        string sub;
        vector<string> ans;
        for(char &c : s){
            sub.push_back(c);
            int i = c - 'a';
            if(curr -> child[i] == nullptr){
                curr -> child[i] = new Node();
                ans.push_back(move(sub));
                curr = root;
                continue;
            }
            curr = curr -> child[i];
        }
        return ans;
    }
};