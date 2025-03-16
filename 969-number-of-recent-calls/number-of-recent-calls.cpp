class RecentCounter {
public:
    map <int,int> mp;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        mp[t]++;
        int low = t - 3000 , calls = 0;
        for(auto it : mp)
            if(it.first >= low and it.first <= t)
                calls++;
        return calls;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */