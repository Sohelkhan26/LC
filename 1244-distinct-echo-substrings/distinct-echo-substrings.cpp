class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set <int> ans;
        auto hash = [&](int left , int right){
            long long base = 109 , mod = 1e9 + 9 , Hash = 0;
            for(int i = left ; i < right ; i++)
                Hash = (Hash * base + (text[i] - 'a' + 1)) % mod;
            return Hash;
        };
        int n = text.size();
        for(int len = 1 ; len <= n / 2 ; len++){
            int count = 0;
            for(int left = 0 , right = len ; left + len < n ; left++ , right++){
                count = (text[left] == text[right] ? count + 1 : 0);
                if(count == len){
                    ans.insert(hash(left , left + len));
                    count--; // not count = 0, think for aaaa
                }
            }
        }
        // for(const string &s : ans)
        //     cout << s << endl;
        return ans.size();
    }
};