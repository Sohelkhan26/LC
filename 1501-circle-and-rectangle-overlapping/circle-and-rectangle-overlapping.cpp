class Solution {
public:
    bool checkOverlap(int r , int xC , int yC , int x1, int y1, int x2, int y2) {
        auto inside = [&](int x , int y){
            return (x - xC) * (x - xC) + (y - yC) * (y - yC) <= r * r;
        };
        if(x1 <= xC and xC <= x2 and y1 <= yC and yC <= y2) // circle inside rectangle
            return true;
        for(int x = x1 ; x <= x2 ; x++) // check horizontal border
            if(inside(x , y1) or inside(x , y2))
                return true;
        for(int y = y1 ; y <= y2 ; y++) // check vertial border
            if(inside(x1 , y) or inside(x2 , y))
                return true;
        return false;
    }
};

/*
A circle and axis algined rectangle is given. Find if they intersect.
Rectangle is parallel to x & y axis.
Equation of circle centered at a , b and radius r
(x - a) * (x - a) + (y - b) * (y - b) == r * r
If a point (x`,y`) will be inside the circle if LHS <= r * r
*/