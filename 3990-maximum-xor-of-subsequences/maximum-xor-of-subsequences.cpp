class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int> setBits(32); 
        for(int n : nums){
            while(n != 0){
                int MSB = 31 - __builtin_clz(n);
                if(setBits[MSB] == 0){
                    setBits[MSB] = n;
                    break;
                }
                else n ^= setBits[MSB];
            }
        }
        int ans = 0;
        for(int i = 31 ; i >= 0 ; i--)
            if((setBits[i] xor ans) > ans)
                ans ^= setBits[i];
        return ans;
    }
};

/*
pick two subseq , allowed to overlap , can be empty , preserving original order of elements
return max possible xor of two subseq
overlapping will reduce overall xor value
order don't matter
ultimately pick a subseq whose xor is max
to maximize xor of some arbitrary sequence,
first choice is to set MSB to 1. if any number has a set bit at pos 'i' we can set that bit in the 'ans'
But we can't take same number twice. 1 ^ 1 = 0
This problem is solved by an advanced tecnique. xor basis maybe
But think of as blackbox.
for each bit position we have to choose a number that will have a set bit in that position and also will not interfere with future set bits(i.e will have 0 in those bit positions)
So, for each bit position(start from right to left to ensure MSB is set first) we will store a number. If for a bit position, a number is already stored, we will xor with that number (eliminate common set bits that would have nullified the current&|previous set MSB) and find a new number, for that new number find set MSB and repeat the process.
This way we can ensure one bit position don't mess with others.
*/