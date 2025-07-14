class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mod = 1e9 + 7 , n = complexity.size() , ans = 1;
        for(int i = 1 ; i < n ; i++){
            ans = (1ll * ans * i) % mod;
            if(complexity[i] <= complexity[0])
                return 0;
        }
        return ans;
    }
};

/*
It's a trick question. Don't think of it like a graph problem to clear i'th computer we should come from j'th comuter such that j < i and complexity[j] < complexity[i].
To open i'th computer we have must have an earlier j'th computer whose complexity is less than i'th computer.
I thought if 1,14,3
if 14 is unlocked we can't then unlock 3 because 14 > 3
But we can unlock 3 cause we have 1 , we don't have to follow 14 -> 3
we can go from earlier computer too. 1 -> 3

Oh, main observation is, if i'th computer's complexity is less than 0'th computer complexity, then we can't unlock that, in that case ans = 0
The problem requires valid permutation to unlock all computers.
*/