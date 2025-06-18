class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        auto factorize = [&](int n){ // use simple factorization function taken from net
            vector <int> factors;
            for(int d = 2 ; d * d <= n ; d++){
                if(n % d == 0){
                    factors.push_back(d);
                    while(n % d == 0)
                        n /= d;
                }
            }
            if(n > 1)
                factors.push_back(n);
            return factors;
        }; 
        int n = nums.size();
        vector<vector<int>> adj(n);
        vector <int> parent(n , -1); 
        function<int(int)> find = [&](int i){
            if(parent[i] == -1)
                return i;
            return parent[i] = find(parent[i]);
        };
        auto unite = [&](int a , int b){ // no need for path compression
            a = find(a) , b = find(b);
            if(a != b)
                parent[a] = b;
        };
        unordered_map <int,int> seen;
        for(int i = 0 ; i < n ; i++){
            auto factors = factorize(nums[i]);
            for(const int &f : factors)
                if(seen.contains(f))
                    unite(i , seen[f]);
                else 
                    seen[f] = i;
        }
        int root = find(0);
        for(int i = 1 ; i < n ; i++)
            if(find(i) != root)
                return false;
        return true;
    }
};

/*
Since n is too large we can't simulate every pair. This alone will give TLE determining if it's reachable is another matter.
for i < j find if there is a path from i to j
any other nodes can be present in-between the path.
So, if gcd(nums[i] , nums[j]) == 1 if there is another node in array nums[k] that has
gcd(nums[i] , nums[k]) > 1 and gcd(nums[k] , nums[j]) > 1 (this way multiple nodes can be added to the path)
then we can go to j from i. 
So, in summary if two nodes have gcd > 1 they have a edge between them. 
And finally we have to find if the whole arre is a single component or not.
But as told earlier , we can't find GCD for every pair.
If two nodes share same prime factorization they will have a edge. Use this to avoid O(n ^ 2)
*/