class Solution {
public:
    int countStudents(vector<int>& stud , vector<int>& sand) {
        queue <int> q(stud.begin() , stud.end());
        reverse(sand.begin() , sand.end());
        while(not q.empty()){
            bool eat = false;
            for(int i = 0 ; i < q.size() ; i++){
                if(q.front() == sand.back())
                    sand.pop_back() , q.pop() , eat = true;
                else{
                    int t = q.front(); q.pop();
                    q.push(t);
                }
            }
            if(not eat)
                return q.size();
        }
        return 0;
    }
};

/*
Simulate the process, at least one student should eat from a given queue otherwise infinite loop thus anyone else won't be able to eat.
*/