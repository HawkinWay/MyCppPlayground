# Graph

## Basic concepts

V: vertex

E: edge

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
| Edge Count | Sparse graph(E << $V^2$) | Dense graph($E \approx V^2 $)| 

