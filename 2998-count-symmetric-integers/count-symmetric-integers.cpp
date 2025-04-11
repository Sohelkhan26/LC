class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low ; i <= high ; i++){
            int digit = 0 , temp = i;
            while(temp > 0)
                temp /= 10 , digit++;
            if(digit % 2)
                continue;
            int sum = 0 , j = i , k = 0;
            for(k = 0 ; j > 0 ; j /= 10 , k++)
                if(k < digit / 2)
                    sum += j % 10;
                else sum -= j % 10;
            ans += (sum == 0);
        }
        return ans;
    }
};