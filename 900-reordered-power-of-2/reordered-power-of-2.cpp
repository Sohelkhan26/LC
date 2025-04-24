class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto counter = [&](int a){
            long long ans = 0;
            while(a){
                ans += pow(2 , a % 10);
                a /= 10;
            }
            return ans;
        };
        long long ans = counter(n);
        for(int i = 0 ; i < 32 ; i++)
            if(counter(1 << i) == ans)
                return true;
        return false;
    }
};

/*
Clever way to solve the problem. Taken from lee.
Observation is, order of digits don't matter in a number only the multiset of digits matter. multiset means multiple occurance of same digit.
So, we can sort "n" and compare with every power of 2 numbers.
Or we find out a efficient and clever hashing technique to do the same job.
counter creates a hash value based on every digit regardless of their order, every hash
value is unique. Two different numbers "a" and "b" will have same hash value only if they have same digits.
*/