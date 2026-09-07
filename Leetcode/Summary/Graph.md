# Graph

## Basic concepts

V: vertex

E: edge

undirected graph:  
1--2--3  

directed graph:  
1->2->3 

indegree

outdegree

Adjacency Matrix:  
[0,1,2,3],  
[4,5,6,7],  
[8,9,10,11],  
[12,13,14,15]  

Adjacency List:  
[0]->1->2  
[1]  
[2]->3  
[3]->1  


## Comparison

#### DFS vs BFS

| Scenario | DFS | BFS|
|--|--|--|
| Storage | `Call Stack`(default), memory is very small(usually **1~8 MB**) | queue in `Heap`(usually a few **GB**)
| Advantage | Code brevity | Safety | 
| Time Complexity | O(V + E), (if **2D array**, O($V^2$)) | O(V + E), (if **2D array**, O($V^2$)) | 
| Space Complexity | O(H), H is deepth | O(W), W is wid width |
| Routine | write recursion function dfs() | matain a queue |
| Golden Rule | Mininum/Shortest/Earliest/Least | Enumerate/Find all/Explore entire component | 

#### Matrix vs List

| Scenario | Matrix | List|
|--|--|--|
| Edge Count | Dense graph($E \approx V^2 $) | Sparse graph(E << $V^2$) |

**The Golden Rule**: Never reach for a matrix unless the problem explicitly restricts numCourses <= 100 or the graph is inherently complete.
