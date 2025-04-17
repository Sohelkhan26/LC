class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        vector <vector<int>> ans;
        int n = first.size() , m = second.size() , i = 0 , j = 0;
        while(i < n and j < m){
            int s1 = first[i][0] , e1 = first[i][1];
            int s2 = second[j][0] , e2 = second[j][1];
            if(e1 < s2)
                i++;
            else if(e2 < s1)
                j++;
            else{
                ans.push_back({max(s1 , s2) , min(e1 , e2)});
                if(e1 < e2)
                    i++;
                else j++;
            }
        }
        return ans;
    }
};