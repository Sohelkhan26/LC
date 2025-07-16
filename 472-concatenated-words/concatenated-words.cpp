class Solution {
public:
    struct Node {
        bool isEnd = false;
        Node* child[26] = {};
    }* root = new Node();

    // Resuable dp array
    bool dp[31];

    // Insert word into trie
    void add(string& s) {
        Node* curr = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!curr->child[idx])
                curr->child[idx] = new Node();
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }

    // For a word, update dp for all possible break points
    void updateDp(Node* node, string& word, int start) {
        for (int i = start; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            node = node->child[idx];
            if (!node)
                break;
            if (node->isEnd) {
                dp[i + 1] = true;
            }
        }
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Sort by length
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        vector<string> ans;
        for (string& word : words) {
            if (word.empty())
                continue;
            // Reset DP for this word
            memset(dp, false, sizeof(bool) * (word.size() + 1));
            dp[0] = true;
            // Update DP via trie
            for (int i = 0; i < word.size(); ++i) {
                if (dp[i]) {
                    updateDp(root, word, i);
                    if (dp[word.size()]) {
                        ans.push_back(word);
                        break;
                    }
                }
            }
            // Add current word to trie for future words
            add(word);
        }
        return ans;
    }
};