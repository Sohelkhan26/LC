class Solution {
public:
    bool prime(int n){
        for(int i = 2 ; i <= sqrt(n) ; i++)
            if(n % i == 0)
                return false;
        return true;
    }
    int smallestValue(int n) {
        int prevN = -1;
        while(prevN != n){
            prevN = n;
            int sumOfPrimes = 0;
            for(int i = 2 ; i < n ; i++)
                while(n % i == 0){
                    n /= i;
                    sumOfPrimes += i;
                }
            if(n != 1)
                sumOfPrimes += n;
            n = sumOfPrimes;
        }
        return n;
    }
};