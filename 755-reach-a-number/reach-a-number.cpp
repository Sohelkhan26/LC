class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = 0 , sum = 0;
        while(true){
            sum += ++n;
            int delta = sum - target;
            if(delta >= 0 and delta % 2 == 0)
                return n;
        }
        return -1;
    }
};

/*
Arithmetic sum problem.
What's the smallest number n such that sum([1..n]) == target.
Have to flip signs to negative of some numbers depending on the target.
If target < 0, we can solve it for abs(target).
Because if target < 0 problem is: smallest n i.e sum of negative numbers == target and flip some signs to positive to achieve target.
So,
If sum([1..n]) == target , answer is n
Important observation is flipping a number "x" to negative decreases sum by 2 * x
So, if we can't achieve sum([1..n]) == target we have to find a sum([1..n]) such that 
sum([1..n]) - target == even.
*/