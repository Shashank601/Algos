class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {
        
        int areaA = (ax2 - ax1) * (ay2 - ay1);
        int areaB = (bx2 - bx1) * (by2 - by1);

        int overlapWidth  = min(ax2, bx2) - max(ax1, bx1);
        int overlapHeight = min(ay2, by2) - max(ay1, by1);

        int overlapArea = 0;
        if (overlapWidth > 0 && overlapHeight > 0) {
            overlapArea = overlapWidth * overlapHeight;
        }

        return areaA + areaB - overlapArea;
    }
};


=========================================================================
int overlapWidth  = min(ax2, bx2) - max(ax1, bx1);         <---- can be -ve
int overlapHeight = min(ay2, by2) - max(ay1, by1);         <----- same

even if one is negative consider no overlap

Think of it like two people standing in a line.
    Person A is at positions 2 to 8.
    Person B is at positions 5 to 10.

  2----------------------------8
        5-----------------------------10
    ^ 5                          ^ 8             =  8 - 5 = 3units
                                                    (right - left)
To find where they overlap, you take the 

[larger of the starts (5)] and the 
[smaller of the ends (8)].

8−5=3. They overlap for 3 units.

x------------------y
                            a---------------------b

max x,a = a                    min y,b = y 

y - a < 0 as y < a
width cant be negative; no overlap



If the rectangles don't overlap, these subtractions will result in a negative number.



x
|
|            a                          <-- min x,a
|            |                                             (top - vottom)        **agar** top hi chota hai bottom se then -ve len milegi
y            |                          <-- max y,b
             |
             |
             |
             |
             b

lets say 
 a
 |
 |     
 b    
      c     
      |
      |
      d

c is min for top

b is max for bottom  since b > c

top - bottom is -ve




Finding the Overlap Height
The same logic applies vertically:
    max(ay1, by1): The highest of the two bottom edges (where the overlap starts climbing).
    min(ay2, by2): The lowest of the two top edges (where the overlap hits the ceiling).


If overlapWidth is negative, 
the rectangles are too far apart horizontally 
(one is completely to the left of the other).

If overlapHeight is negative, 
the rectangles are too far apart vertically 
(one is completely above the other).
