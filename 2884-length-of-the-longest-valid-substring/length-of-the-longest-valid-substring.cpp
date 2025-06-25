class Solution {
public:
    struct Node{
        Node* child[26] = {};
        bool end = false;
    };
    Node* root;
    void add(string &s){
        Node* curr = root;
        for(char &c : s){
            if(curr -> child[c - 'a'] == nullptr)
                curr -> child[c - 'a'] = new Node();
            curr = curr -> child[c - 'a'];
        }
        curr -> end = true;
    }
    bool search(string &word , int i , int j){
        Node* curr = root;
        for( ; i <= j ; i++){
            int idx = word[i] - 'a';
            if(curr -> child[idx] == nullptr)
                return false;
            curr = curr -> child[idx];
            if(curr -> end)
                return true;
        }
        return false;
    }
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int ans = 0 , n = word.size();
        root = new Node();
        for(string &s : forbidden)
            add(s);
        for(int right = n - 1 , left = n - 1 ; left >= 0 ; left--){
            while(left <= right and search(word , left , min(left + 10 , right)))
                right--;
            ans = max(ans , right - left + 1);
        }
        return ans;
    }
};

/*
string is valid if none of it's substring appear in forbidden array.
Return length of longest valid substring of word(could be the whole string)

Trie needed for forbidden array.
whole substring need to be present in forbidden array, not prefix(check isEnd in trie node)
If word[i..j] is present in array, have to start from j + 1
Does it give DP feel?

Couldn't solve it on my own.
Use a trie to track forbidden words.
loop from end, if substring[i..j] is valid, we check if substring[i - 1..j] is valid too.

Because as left goes from n-1 → 0:

We can re-use the current valid window (right)

Only shrink right if a forbidden word is found starting at left

This allows us to maintain the longest valid window ending at right and starting at left
*/