# Binary Tree

- Full Binary Tree
- Compelete Binary Tree
- Binary Search Tree (BST)
    - Balanced Binary Search Tree
        - AVL Tree (strong balanced)
        - Red-black Tree (weak balanced)
- Heap
- Huffman Tree

---

## Red-black Tree

- less number of rotations when insert/delete
- the longest path <= 2 * the shortest path

Five core features:

1. Every node is red or black.
2. The root node must be black.
3. All leaf nodes(NIL) must be black.
4. If a node is red, its two childs must be black. (Two nodes cannot be adjacent)
5. Starting from any node to all its descendant NIL leaf nodes, the number of black nodes on the path is the same.

*NIL: empty dummy node, not normal nullptr pointer*

|Dimension|Red-black Tree|AVL Tree|
|--|--|--|
|Blanced condition|The height difference between left and right subtrees <= 1| The logest path <= 2 * the shortes path|
|Insert rotation|Possibly multiple times|2 times at most|
|Delete rotation|Possibly multiple times|3 times at most|
|Find efficiency|O(logn)|O(logn)|
|Write overhead|High|Low|
|Scenario|Read more, write less|Balanced read and write|
