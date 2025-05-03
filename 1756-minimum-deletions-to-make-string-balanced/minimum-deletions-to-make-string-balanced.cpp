class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size() , a = 0 , b = 0 , ans = n;
        vector <int> aCount(n) , bCount(n);
        for(int i = 0 ; i < n ; i++){
            bCount[i] = b;
            b += (s[i] == 'b');
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            aCount[i] = a;
            ans = min(ans , aCount[i] + bCount[i]);
            a += (s[i] == 'a');
        }
        return ans;
    }
};

/*
Del char from s such that no be occurs before a in s.
Choose a optimal dividing point such that all left 'b' and all right 'a' is deleted.
Above approach is not typical suffix and prefix array.
bCount[i] refers count(b in range[0..i - 1]) index i is not included, meaning if the last char is b, it is not saved in bCount.
*/