class Solution {
public:
    string smallestString(string s) {
        int i = 0 , n = s.size();
        while(i < n and s[i] == 'a')
            i++;
        if(i == n)
            s[n - 1] = 'z';
        while(i < n and s[i] != 'a')
            --s[i++];
        return s;
    }
};

/*
All char except 'a' is made lexicograpically smaller by the operation. So earliest biggest substring with no 'a' is candidate.
If all is 'a' turn the last char to 'z' because we must perform one operation.
*/