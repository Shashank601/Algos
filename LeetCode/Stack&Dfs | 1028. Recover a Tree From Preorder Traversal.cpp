val *= 10 + (traversal[i] - '0');           and     val = val*10 + (traversal[i] - '0'); 
=> val = val * (10 + (traversal[i]-'0'));           val = (val*10) + (traversal[i] - '0');  
=> wrong way to parse                               right way to parse a num



 
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int i = 0;
        stack<TreeNode*> st;

        while (i < n) {

            int depth = 0; 
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }


            int val = 0;
            while (i < n && isdigit(traversal[i])) {
                val = val*10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);

            while (st.size() > depth) {
                st.pop();
            }

            if (!st.empty()) {
                if (!st.top()->left) {
                    st.top()->left = node;
                } else {
                    st.top()->right = node;
                }
            }
            st.push(node);
        }

        while (st.size() > 1) st.pop();
        return st.top();
    }
};


[dash_cnt][num][dash_cnt][num]...
The first number has no dash → depth 0



The stack logic (while (st.size() > depth) st.pop()) depends on depth being correct.

so parse dashes first then nums



Count dashes → get depth
Read digits → get value

Pop stack until stack.size() == depth → get parent
Attach node to parent (left first, then right)
Push node to stack


the dashes always come before the number they describe.

so wrong way is:

// number first
val = 1
// then look at dashes
depth = ?  <------------ those dashes now belong to the next node (2), not 1.


"1-2--4---8---9--5---10---11-3--6---12---13--7---14---15"
1
  -2
    --4
       ---8
       ---9         
    --5            <--------- once dash dec, we dont need that parent(4) anymore (left subtree is fully explored)
       ---10
       ---11
  -3
    --6
       ---12
       ---13
    --7
       ---14
       ---15


  DASH INCREASE (or same): Keep building DOWN or SIDEWAYS
  Example: --- to --- (same depth, add sibling)
  Example: -- to --- (more dashes, add child)

  DASH DECREASE: ABANDON current subtree, go BACKWARD up the tree
  Example: --- to -- (fewer dashes, current node is DONE, go to parent level)


  In preorder traversal, once we've visited a node:
1. The node itself comes first
2. Then its ENTIRE left subtree  
3. Then its ENTIRE right subtree

KEY INSIGHT: If we've moved PAST a node's right subtree,
             we will NEVER return to that node again!
-------------------------------------------

  Algorithm:
  

Count Dashes: 
It first counts the dashes to determine the depth of the upcoming node.

Parse Value: 
It reads the digits to determine the node's val.

Adjust the Stack: 
This is the clever part. 
If the current stack size is greater than the node`s depth,
  
it means the current node is 
not a child of the node at the top of the stack.
  
It pops the stack until the top of the stack is the actual parent.


  
Attach the Node:
If the parent doesn't have a left child yet, 
this new node becomes the left child.

Otherwise, it becomes the right child.

Push to Stack: The new node is pushed onto the stack because it might be the parent of the next node in the string.

-------------------------------------

  Tree Structure:
                    1 (depth 0)
                   / \
                  2   3
                 / \   / \
                4   5 6   7
               / \ / \ ...
              8 9 10 11

Stack Evolution:

Parse "1" (depth 0):
Stack: [1]
Tree: 1

Parse "2" (depth 1):
Stack: [1, 2]
Tree: 1
      /
     2

Parse "4" (depth 2):
Stack: [1, 2, 4]
Tree: 1
      /
     2
    /
   4

Parse "8" (depth 3):
Stack: [1, 2, 4, 8]
Tree: 1
      /
     2
    /
   4
  /
 8

Parse "9" (depth 3):
Stack still: [1, 2, 4, 9]  ← 8 gets popped, 9 replaces it
Tree: 1
      /
     2
    /
   4
  / \
 8   9

Parse "5" (depth 2):  ← DEPTH DECREASED from 3 to 2
Stack before: [1, 2, 4, 9]
Pop until size = 2: Pop 9, Pop 4
Stack after: [1, 2, 5]

WHY? Because node 4 is COMPLETE!
- Node 4 has both children (8 and 9)
- We're going back up to depth 2
- Node 5 is the RIGHT child of node 2
- We'll NEVER add more children to node 4

Tree: 1
      /
     2
    / \
   4   5   ← 5 is sibling of 4, not child!
  / \
 8   9
------------------------------------

  Preorder GUARANTEES this sequence for any node N:

  N  →  N.left_subtree  →  N.right_subtree  →  (never return to N)
  ↑         ↑                    ↑                      ↑
depth D   depth>D            depth>D              depth≤D

When we see depth decrease from (D+1) to D:
  ✓ We've finished some node's subtree at depth D
  ✓ That node will never be visited again (preorder doesn't backtrack)
  ✓ Safe to remove it from our "active path" (stack)

The stack maintains only nodes that might still get children added.
Once depth decreases below a node, that node is SEALED - no more children!

------------------------------------------

lastly

Given a node N at depth D in preorder traversal:
  
  CONDITION: If the next node in traversal has depth < D+1
  
  CONCLUSION: All descendants of N have been visited
              N is complete and will never be revisited
              
  ACTION: Pop N from the stack (abandon it)
  
  REASON: Preorder visits Root-Left-Right,
          so after Right subtree, we never return to Root
