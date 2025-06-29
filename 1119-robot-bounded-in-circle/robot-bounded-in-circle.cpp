class Solution {
public:
    bool isRobotBounded(string s) {
        int dir[5] = {0 , 1 , 0 , -1 , 0} , x = 0 , y = 0 , i = 0;
        for(char &c : s){
            if(c == 'G')
                x += dir[i] , y += dir[i + 1];
            else if(c == 'R')
                i++ , i %= 4;
            else
                i--;
            if(i < 0)
                i = 3;
        }
        return (x == 0 and y == 0) or i > 0;
    }
};

/*
Such an amazing problem. But rating is quite low. 
Think of G..G as vector , and L/R as changing the direction of the vector.
If the vector change direction once, Because of never-ending sequence of instructions, the vector will meet at it's starting index.
Simulate for something simple like : GGR
complex instruction GGRGGLGGLGG will only complicate the shape of the area created by vector. But it will get back at start
*/