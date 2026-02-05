class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        int overlapWt = min(rec1[2],rec2[2]) - max(rec1[0], rec2[0]);
        int overlapHt = min(rec1[3],rec2[3]) - max(rec1[1], rec2[1]);

        return (overlapWt > 0) && (overlapHt > 0) ?  true : false;

        
    }
};



think about edges of both rectangles 

the hard part is to able to viz given input collectively


i try to think of horizontal edge ends first then 
(greater of given left ends  and smaller of given right ends)

dono ke left ka competiton and dono ke rigth ka competiton




same for width

