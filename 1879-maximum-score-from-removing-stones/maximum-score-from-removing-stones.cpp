class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if(a > b)
            return maximumScore(b , a , c);
        if(b > c)
            return maximumScore(a , c , b);
        if(a + b <= c) // pair with biggest pile first. So, both a and b pile can be paired with c
            return a + b;
        return c + (a + b - c) / 2; // c < a + b , from c pile pair with a and then b pile one by one such that after c == 0 , abs(a - b) <= 1 then we can make (a + b) / 2 pairs.
    }
};

/*
Order matters. If stone is removed from smallest piles first, stone can remain in bigger piles.
Optimal is to remove stones from bigger piles.
If there were two piles , then smaller pile would have been the answer.
Turn smaller two piles into one, and make pair with the bigger pile.
1st pile = a + b
2nd pile = c
if 1st pile < 2nd pile, 1st pile is the answer.
if 2nd pile < 1st pile , then 2nd pile is answer. There is a but:
1st pile consist of 2 inner pile. So, match c with pile a and b such that abs(a - b) <= 1, then we can get additional (a + b - c) / 2 pairs. 
*/