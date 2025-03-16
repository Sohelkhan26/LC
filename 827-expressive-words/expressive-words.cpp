class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0 , n = s.size();
        for(string w : words){
            bool ok = true;
            int i = 0 , j = 0 , m = w.size();
            while(i < n and j < m){
                int cnt1 = 0 , cnt2 = 0; // Every loop indicates start of new group
                char c = s[i]; // s[i] == w[i] is not neccessary. It not equal, cnt1/2 either will be zero.
                while(s[i] == c) // cnt1 is group length in s.
                    cnt1++ , i++;
                while(w[j] == c)
                    cnt2++ , j++;
                if((cnt1 < 3 and cnt1 != cnt2) or (cnt1 < cnt2)){
                    ok = false;
                    break;
                }
            }
            ans += (ok and j == m and i == n);
        }
        return ans;
    }
};

/*
In every string in words, some characters can be inserted so that size of the group with same character is at least 3.
So, for every character group we have to check if it's count is less than or equal to corresponding group in s(if the group size is greater than 3).
If the group size is less than 3, then group in s and words[i] should be of same count.
*/