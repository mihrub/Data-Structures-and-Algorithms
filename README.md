# Data Structures and Algorithms in C++

C++ implementations of core data structures and algorithms with clear code and complexity analysis. Built while studying Computer Science and Engineering at RUET, covering university coursework, lab work, and competitive programming practice.

The repository contains **240+ C++ programs** across 17 topic folders.

## Table of Contents

- [Repository Structure](#repository-structure)
- [Topics Covered](#topics-covered)
- [Getting Started](#getting-started)
- [Code Style](#code-style)
- [Complexity Reference](#complexity-reference)
- [Author](#author)

## Repository Structure

```
Data-Structures-and-Algorithms/
├── Backtracking/            (6 programs)
├── Binary Search Trees/     (3 programs)
├── Binary Trees/            (12 programs)
├── Disjoint Set Union/      (5 programs)
├── Divide and Conquer/      (12 programs)
├── Dynamic Programming/     (27 programs)
├── Graph/                   (38 programs)
├── Greedy/                  (6 programs)
├── Hashing/                 (1 program)
├── Heap/                    (4 programs)
├── Lab Work/                (50 programs)
├── Linked List/             (24 programs)
├── Matrix Multiplication/   (3 programs)
├── Queue/                   (13 programs)
├── Searching/               (5 programs)
├── Sorting/                 (8 programs + analysis notebook)
├── Stack/                   (24 programs)
└── .gitignore
```

## Topics Covered

### Data Structures

| Folder | What's inside |
| --- | --- |
| [Linked List](./Linked%20List) | Singly, doubly, and circular lists; menu-driven programs; Floyd's cycle detection and cycle removal; reverse, sort, merge sort, remove duplicates, remove Nth node, zig-zag arrangement; STL-based versions |
| [Stack](./Stack) | Array, linked list, deque, and vector based stacks; infix to postfix, postfix evaluation, polish notation; valid parentheses, next greater element, stock span, Tower of Hanoi, reverse a stack, backspace string compare |
| [Queue](./Queue) | Linear and circular queues, deque, STL queue; queue using two stacks and stack using two queues; queue reversal, interleave two queues, first non-repeating character, Ackermann function |
| [Binary Trees](./Binary%20Trees) | Tree construction and input, level order traversal, node counting, leaf nodes, outer boundary printing, sum excluding leaf nodes |
| [Binary Search Trees](./Binary%20Search%20Trees) | BST insertion and construction from an array |
| [Heap](./Heap) | Insertion and deletion in min heaps and max heaps |
| [Hashing](./Hashing) | Hash table with separate chaining |
| [Disjoint Set Union](./Disjoint%20Set%20Union) | Find (recursive, iterative, optimized with path compression), union, and cycle detection in undirected graphs |
| [Graph](./Graph) | Adjacency list, adjacency matrix, and edge list representations; BFS and DFS (including on 2D grids); connected components; cycle detection (directed and undirected); Dijkstra (plain and priority queue optimized); Bellman-Ford; Floyd-Warshall; shortest path printing; knight moves and maze problems |

### Algorithms and Paradigms

| Folder | What's inside |
| --- | --- |
| [Sorting](./Sorting) | Bubble, selection, insertion, merge, quick, counting, radix, and bucket sort, plus a notebook and data files for comparing performance |
| [Searching](./Searching) | Linear search, binary search (iterative, recursive, extended), and ternary search |
| [Greedy](./Greedy) | Fractional knapsack, Huffman coding, job sequencing with deadlines, optimal merge pattern, Kruskal's MST, and Prim's MST |
| [Divide and Conquer](./Divide%20and%20Conquer) | Merge sort (2-way, 3-way, and 4-way variants), count inversions, min/max, Quick Hull, and Graham scan |
| [Dynamic Programming](./Dynamic%20Programming) | Fibonacci (top-down and bottom-up), climbing stairs, coin change, knapsack variants (0/1, unbounded), subset sum, LCS, LIS, shortest common supersequence, matrix chain multiplication, longest path, and grid problems |
| [Backtracking](./Backtracking) | N-Queens, Knight's Tour, Rat in a Maze, and graph coloring (decision and optimization versions) |
| [Matrix Multiplication](./Matrix%20Multiplication) | Iterative, divide and conquer, and Strassen's matrix multiplication |

### Coursework

| Folder | What's inside |
| --- | --- |
| [Lab Work](./Lab%20Work) | University lab programs: array operations, searching, sorting, linked lists, stacks and queues, tree traversals, matrix multiplication, and complexity measurement experiments |

## Getting Started

### Prerequisites

- A C++ compiler with C++11 support or later (GCC, Clang, or MSVC)
- Git

### Clone the repository

```bash
git clone https://github.com/mihrub/Data-Structures-and-Algorithms.git
cd Data-Structures-and-Algorithms
```

### Compile and run a program

```bash
g++ -std=c++17 -O2 "Sorting/merge_sort.cpp" -o program
./program
```

On Windows:

```bash
g++ -std=c++17 -O2 "Sorting\merge_sort.cpp" -o program.exe
program.exe
```

Quote paths that contain spaces, such as `"Binary Trees/level_order.cpp"`.

## Code Style

- Each program is self-contained and can be compiled on its own
- Time and space complexity are noted alongside the implementations
- Related variations of the same idea sit together (for example, three versions of Dijkstra or four versions of the knapsack problem) so the trade-offs are easy to compare

## Complexity Reference

Quick reference for the structures and algorithms in this repository.

### Data Structure Operations (average case)

| Structure | Access | Search | Insert | Delete |
| --- | --- | --- | --- | --- |
| Array | O(1) | O(n) | O(n) | O(n) |
| Linked List | O(n) | O(n) | O(1) | O(1) |
| Stack | O(n) | O(n) | O(1) | O(1) |
| Queue | O(n) | O(n) | O(1) | O(1) |
| Hash Table | N/A | O(1) | O(1) | O(1) |
| Binary Search Tree | O(log n) | O(log n) | O(log n) | O(log n) |
| Binary Heap | N/A | O(n) | O(log n) | O(log n) |

BST operations degrade to O(n) in the worst case when the tree becomes skewed. Linked list insert and delete are O(1) once the position is known.

### Sorting Algorithms

| Algorithm | Best | Average | Worst | Space |
| --- | --- | --- | --- | --- |
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | O(k) |
| Radix Sort | O(d(n + k)) | O(d(n + k)) | O(d(n + k)) | O(n + k) |

### Graph Algorithms

| Algorithm | Time Complexity |
| --- | --- |
| BFS / DFS | O(V + E) |
| Dijkstra (binary heap) | O((V + E) log V) |
| Bellman-Ford | O(V · E) |
| Floyd-Warshall | O(V³) |
| Kruskal's MST | O(E log E) |
| Prim's MST (binary heap) | O(E log V) |

## Author

<div align="center">

### Mihrub Aziz Bhuiyan

🎓 Computer Science and Engineering student at **Rajshahi University of Engineering & Technology (RUET)**

💡 Algorithms · Data Structures · Competitive Programming · Problem Solving

🔗 [github.com/mihrub](https://github.com/mihrub)

</div>

---

<div align="center">

⭐ If you find this repository helpful, consider giving it a star! ⭐

*Happy coding!*

</div>