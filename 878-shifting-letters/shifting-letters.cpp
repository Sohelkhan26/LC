class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i = s.size() - 1 , prev = 0 ; i >= 0 ; prev %= 26 , i--)
            s[i] = ((s[i] - 'a') + (prev += shifts[i])) % 26 + 'a';
        return s;
    }
};