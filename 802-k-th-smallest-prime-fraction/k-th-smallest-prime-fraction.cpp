class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double low = 0 , high = 1 , mid;
        vector <int> ans;
        while(low <= high){
            mid = (low + high) / 2;
            double maxFraction = 0;
            int n = arr.size() , j = 1 , smaller = 0; // no need to reset j. because if arr[i] / arr[j] >= mid , then arr[i + 1] / arr[j] will also be greater than mid because of sorted nature. So, even arr[j] ensures >=, so no point reducing arr[j] to arr[j -> (0 -> j -1)]
            for(int i = 0 ; i < n - 1 ; i++){
                while(j < n and arr[i] >= mid * arr[j])
                    j++;
                smaller += (n - j);
                if(j == n)
                    break;
                double fraction = (arr[i] * 1.0) / arr[j];
                if(fraction > maxFraction)
                    ans = {arr[i] , arr[j]} , maxFraction = fraction;
            }
            if(smaller == k)
                return ans;
            if(smaller > k)
                high = mid;
            else low = mid;
        }
        return ans;
    }
};
/*
Comparatively harder problem.
Some facts are given: arr contains unique prime numbers and sorted in ascending order.
Can we use these facts to our advantage?
As all n -> arr are prime, __gcd(denominator , numerator) == 1 i.e: no common divisor and always fraction < 1
arr sorted, so for fraction from left to right will get smaller and smaller.
Binary search over the desired kth smallest number and keep count of fractions smaller than mid value. 
One problem, we have to return the denominator and numerator , not the fraction itself.
So keep track of the largest fraction. Now, why is this maximum fraction significant? In a sorted array of unique numbers, the fractions increase gradually as we move left to right. If we've encountered k or more fractions smaller than or equal to this maximum fraction, then this maximum fraction is the kth smallest fraction.
maxFraction should be calculated for each mid.
if there count(smallerFraction < mid) > k reduce mid so that count decreases(high = mid)
*/