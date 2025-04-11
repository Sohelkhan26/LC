class Solution {
public:
    int mod = 1e9 + 7;
    int fact(int n){
        long long ans = 1;
        for(int i = 2 ; i <= n ; i++)
            ans = (ans * i) % mod;
        return ans;
    }
    int numPrimeArrangements(int n) {
        auto prime = [&](int n){
            for(int i = 2 ; i * i <= n ; i++)
                if(n % i == 0)
                    return false;
            return true;
        };
        int a = 0 , b = 0;
        for(int i = 2 ; i <= n ; i++)
            if(prime(i))
                a++;
        b = n - a;
        return (1ll * fact(a) * fact(b)) % mod;
    }
};

/*
valid permutation should have prime numbers in their original places. They can be placed among the prime number themselves. And non-prime numbers can be passed around themselves exclusively. prime number and non-prime numbers can't swap places.
So, for prime numbers, if there are "a" primes, then for the first place choice = a , 2nd place = a - 1 , 3rd place = a - 2, multiply them togather and thats a!. Same for non-primes.
*/