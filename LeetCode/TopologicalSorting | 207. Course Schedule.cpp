no vis array in kahns algo

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> incoming(numCourses);

        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int l = prerequisites[i][0];
            int r = prerequisites[i][1];

            incoming[l]++;
            adj[r].push_back(l);
        }


        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (incoming[i] == 0) q.push(i); 
        }

        //vector<int> vis(numCourses, 0);
        int cnt = 0;
        while (!q.empty()) {
            int idx = q.front(); q.pop();
            cnt++;
             
            for (auto neigh : adj[idx]) {
               // vis[neigh] = 1;  <----- we dont need it in kahn's we push only when incoming edge is exactly 0 (one time event for any node)
                incoming[neigh]--;

                if (incoming[neigh] == 0) q.push(neigh);   <------- if no node have incoming edge 0 we will exit implying early exit (cycle) or completely processed 
            }

        }

        return cnt == numCourses;  <-------- imp kahns property
    }
};



What nodes can we safely place first?

Answer:
Nodes with no incoming edges.

Why?

Because nothing depends on them.
They are independent starting points.

That is the key observation.

===========================

How is cycle detected ?

Not with vis.
Cycle is detected by:
processed_count != numCourses


Why?
Because in a cycle:
Every node in cycle has in-degree ≥ 1
So none of them ever enter queue

So they never get processed
Queue becomes empty early.

Remaining nodes = cycle.

Important distinction

DFS topological sort → needs vis and recursion stack.
Kahn BFS → does NOT need vis.

Different invariants.
