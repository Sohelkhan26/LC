class Solution {
public:
    struct Node{
        bool isEnd = false;
        Node* child[26] = {};
        int index = -1;
        vector<int> palindromes;
    } *root , *curr;

    bool palindrome(string &s , int i , int j){
        while(i <= j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
 
    void add(string &s , int idx){
        curr = root;
        for(int i = s.size() - 1 ; i >= 0 ; i--){ // we are inserting reverse of words i.e: suffixes of words
            if(palindrome(s , 0 , i)) // prefix is palindrome
                curr -> palindromes.push_back(idx);
            int j = s[i] - 'a';
            if(curr -> child[j] == nullptr)
                curr -> child[j] = new Node();
            curr = curr -> child[j];
        }
        curr -> index = idx; // end of word
        curr -> palindromes.push_back(idx);
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new Node();
        vector<vector<int>> ans;
        int n = words.size();
        for(int i = 0 ; i < n ; i++)
            add(words[i] , i);
        for(int i = 0 ; i < n ; i++){
            curr = root;
            int m = words[i].size();
/*This for loops finds palindrome that have words[i] as prefix and some other word as suffix and there are some characters left in words[i] even after matching with some other word. words[i] is bigger. i.e: words[i] = llss other word = lls */
            for(int j = 0 ; j < m and curr ; j++){ // for each words traverse from front
                if(curr -> index != -1 and curr -> index != i and palindrome(words[i] , j , m - 1))
                    ans.push_back({i , curr -> index}); // we found words[i][0..j] to some other words suffix
                curr = curr -> child[words[i][j] - 'a']; // and rest of words[i] is palindrome too.
            }
            if(curr == nullptr)
                continue;
            for(int j : curr -> palindromes) // if whole words[i] matches with some other words suffix and that other word is still bigger. Now if rest of that other word is palindrome too, we found another valid pair. i.e: words[i] = lls other word = llsss
                if(i != j)
                    ans.push_back({i , j});
        }
        return ans;
    }
};

/*
Am i overcomplicating things or this problem is harder than most?
bidirectional pairs are not always possible.
abc -> ba but not ba -> abc
But sssll -> lls and lls -> sssll
How to distinguish between the two?
I think Trie is needed. Or hashing?
And to make things even more complicated input can contains empty strings.
As if things were not complicated enough.
abcd -> dcba 
dcba -> abcd
*/