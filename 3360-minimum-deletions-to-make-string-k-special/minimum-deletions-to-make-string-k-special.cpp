class Solution {
public:
    int minimumDeletions(string word, int k) {
        int ans = INT_MAX;
        vector <int> count(26);
        for(char &c : word)
            count[c - 'a']++;
        for(int mn : count){
            int curr = 0; // find out total char deletion required to make mn as smallest frequency
            for(int i : count){
                if(i < mn) // delete all so rule don't apply(no trace of it in string "word")
                    curr += i;
                else if(i > (mn + k)) // for minimum value 'mn' all other freq should be in the range [mn , mn + k]
                    curr += (i - mn - k);
            }
            ans = min(ans , curr);
        }
        return ans;
    }
};

/*
Greedy solution. As we can't add characters It's obvious that maximum frequency should be deleted such that difference between maximum and minimum frequency <= k.
So, For each character frequency 'mn' we fix it as the minimum frequency, so, every other character should be in the range [mn , mn + k], if any character is < mn , then it will definately create a difference > k , with the maximum frequency. So, if a frequency is < 'mn' it should be deleted so that the rule don't apply to it(no trace of it in string "word"). And if a 'i' frequency is > (mn + k) then, i - (mn + k) should be deleted.
*/