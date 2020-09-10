# Data structures and algorithms for interviews

This repository contains C++ implementations of general algorithms and data structures.

*For a quick revision checkout the readme files for each topic.*

## Contents

1. **Algorithm analysis**
	* Solving recurrences
		* Iteration Method
		* Substitution Method
		* Recurrence Tree Method
		* Master Method
	* Amortized Analysis
2. **Searching, Sorting and Order Statistics** [Readme](2.%20Searching,%20Sorting%20and%20Order%20Statistics/Readme.md)
	1. Searching
		* [Linear Search](2.%20Searching,%20Sorting%20and%20Order%20Statistics/linearSearch.cpp)
		* [Binary Search](2.%20Searching,%20Sorting%20and%20Order%20Statistics/binarySearch.cpp)
		* [Ternary Search](2.%20Searching,%20Sorting%20and%20Order%20Statistics/ternarySearch.cpp)
		* [Exponential Search](2.%20Searching,%20Sorting%20and%20Order%20Statistics/exponentialSearch.cpp)
		* [Interpolation Search](2.%20Searching,%20Sorting%20and%20Order%20Statistics/interpolationSearch.cpp)
		* [Jump Search](2.%20Searching,%20Sorting%20and%20Order%20Statistics/jumpSearch.cpp)
	2. Sorting
		* [Insertion Sort](2.%20Searching,%20Sorting%20and%20Order%20Statistics/insertionSort.cpp)
		* [Selection Sort](2.%20Searching,%20Sorting%20and%20Order%20Statistics/selectionSort.cpp)
		* [Bubble Sort](2.%20Searching,%20Sorting%20and%20Order%20Statistics/bubbleSort.cpp)
		* Bucket Sort
		* [Merge Sort](2.%20Searching,%20Sorting%20and%20Order%20Statistics/mergeSort.cpp)
		* Heap Sort
		* [Quick Sort](2.%20Searching,%20Sorting%20and%20Order%20Statistics/quickSort.cpp)
		* Counting Sort
		* Radix Sort
	3. Order Statistics
		* [Minimum and maximum](2.%20Searching,%20Sorting%20and%20Order%20Statistics/randomizedSelect.cpp)
3. **Algorithmic Paradigms**
	1. Complete Search
		* [N-queen](3.%20Algorithmic%20Paradigms/Complete%20Search/NQueen.cpp)
	2. Divide and Conquer
		* Strassen's algorithm for matrix multiplication
	3. Dynamic programming
		* [0-1 Knapsack](3.%20Algorithmic%20Paradigms/Dynamic%20Programming/01Knapsack.cpp)
		* [Coin change](3.%20Algorithmic%20Paradigms/Complete%20Search/NQueen.cpp)
		* [1D Range Sum Query](3.%20Algorithmic%20Paradigms/Complete%20Search/1DRangeSum.cpp)
		* [Longest Increasing Subsequence](3.%20Algorithmic%20Paradigms/Complete%20Search/LIS.cpp)
		* [Longest Common Subsequence](3.%20Algorithmic%20Paradigms/Complete%20Search/LCS.cpp)
		* [Matrix Chain Multiplication](3.%20Algorithmic%20Paradigms/Complete%20Search/MCM.cpp)
		* [Optimal Binary Search Tree](3.%20Algorithmic%20Paradigms/Complete%20Search/OBST.cpp)
		* [Binomial Coefficient](3.%20Algorithmic%20Paradigms/Complete%20Search/binomialCoefficient.cpp)
		* [Ways to add upto an integer](3.%20Algorithmic%20Paradigms/Complete%20Search/howDoYouAdd.cpp)
		* Number of paths in a dag
		* Knuth optimization
		* Convex hull optimizations
		* RMQ (sparse table a.k.a 2^k-jumps)
		* Bitonic cycle
		* Log partitioning (loop over most restricted)
		* 3^n set cover
		* DP over intervals
		* DP over subsets
		* DP over probabilities
		* DP over trees
	4. Greedy algorithm
		* Task Scheduling
		* Max contiguous subvector sum
		* Invariants
		* Huffman encoding
		* Matroid
		* Activity Selection
		* Fractional Knapsack
4. **Trees**
	* Binary Tree
	* Binary Search Tree
	* AVL Trees
	* Red-Black Trees
	* Treap
	* Splay Tree
	* N-ary Tree
	* Trie
	* Suffix Tree
	* Huffman Tree
	* Heap
	* B+, B- Tree
	* Merkle Tree
	* Segment Tree 
	* Fenwick Tree (Binary Indexed Tree)
	* [Square Root Decomposition](4.%20Trees/squareRootDecomposition.cpp)
5. **Graph theory**
	* Traversals
		* [Depth first search](5.%20Graph%20Theory/Traversal/dfs.cpp)
		* [Breadth first search](5.%20Graph%20Theory/Traversal/bfs.cpp)
		* [Flood-Fill (DFS)](5.%20Graph%20Theory/Traversal/floodFill.cpp)
		* [Forest-Fire (BFS)](5.%20Graph%20Theory/Traversal/forestFire.cpp)
	* Topological Sort
		* [Using modified DFS/BSF](5.%20Graph%20Theory/Topological%20Sort/topological.cpp)
		* [Kahn algorithm](5.%20Graph%20Theory/Topological%20Sort/kahn.cpp)
	* [Articulation points and bridges (Undiredted graphs)](5.%20Graph%20Theory/Connectivity/articulationPointsAndBridges.cpp)
	* Strongly connected components (Directed graphs)
		* Tarajan algorithm
		* Kosaraju algorithm
	* Vertex coloring
		* Bipartite graphs (=> trees)
		* 3^n (special case of set cover)
	* Edge coloring
		* Trees
	* [Union-Find Disjoint Sets](5.%20Graph%20Theory/Union%20Find%20Disjoint%20Sets/UFDS.cpp)
	* Minimum spanning tree (Undirected Graphs)
		* [Kruskal algorithm](5.%20Graph%20Theory/Spanning%20Tree/kruskal.cpp)
		* [Prim algorithm](5.%20Graph%20Theory/Spanning%20Tree/prim.cpp)
		* Boruvka algorithm
		* Steiner Tree
		* Bernard Chazelle
	* Minimum spanning tree (Arborescence/ Directed Graphs)
		* Chu–Liu/Edmonds algorithm.
	* Shortest paths
		* [Bellman-Ford algorithm](5.%20Graph%20Theory/Shortest%20Paths/bellmanFord.cpp)
		* SPFA (Shortest Path Faster Algorithm)
		* [Dijkstra  algorithm](5.%20Graph%20Theory/Shortest%20Paths/dijkstra.cpp)
		* A* algorithm
		* [Floyd-Warshall algorithm](5.%20Graph%20Theory/Shortest%20Paths/floydWarshall.cpp)
		* Johnson algorithm
	* Paths and circuits
		* Eulerian path
		* Hamiltonian path
		* De Bruijn sequences
		* Knight's tour
	* Network flows and cuts
		* Ford-Fulkerson algorithm
		* Augmenting paths
		* Edmonds-Karp
	* Matching
		* Maximal matching, general graphs
		* Bipartite matching
	* Min-cost max flow
	* Shortest cycle
	* Konig's theorem and vertex cover
	* Lovasz toggle
	* Matrix tree theorem
	* Hopcroft-Karp
	* Hall's marriage theorem
	* Graphical sequences
	* Min. path cover
	* Cut vertices, cut-edges and biconnected components
	* Diameter and centroid
	* K'th shortest path
	* 2-SAT
	* Dynamic graphs (extra book-keeping)
6. **Math**
	1. Combinatorics
		* Computation of binomial coefficients
		* Pigeon-hole principle
		* Inclusion/exclusion
		* Catalan number
		* Pick's theorem
	2. Number theory
		* Integer parts
		* Divisibility
		* Euclidean algorithm
		* Modular arithmetic
			* Modular multiplication
			* Modular inverses
			* Modular exponentiation by squaring
		* Chinese remainder theorem
		* Fermat's little theorem
		* Euler's theorem
		* Phi function
		* Frobenius number
		* Quadratic reciprocity
		* Pollard-Rho
		* Miller-Rabin
		* Hensel lifting
		* Vieta root jumping
	3. Game theory
		* Combinatorial games
		* Game trees
		* Mini-max
		* Nim
		* Games on graphs
		* Games on graphs with loops
		* Grundy numbers
		* Bipartite games without repetition
		* General games without repetition
		* Alpha-beta pruning
	4. Numerical methods
		* Numeric integration
		* Newton's method
		* Root-finding with binary/ternary search
		* Golden section search
	5. Matrices
		* Gaussian elimination
		* Exponentiation by squaring
7. **Geometry**
	* Coordinates and vectors
		* Cross product
		* Scalar product
	* Convex hull
	* Polygon cut
	* Closest pair
	* Coordinate-compression
	* Quadtrees
	* KD-trees
	* All segment-segment intersection
8. **Strings**
	* Knuth-Morris-Pratt
	* Rabin Karp
	* Tries
	* Rolling polynomial hashes
	* Suffix array
	* Suffix tree
	* Aho-Corasick
	* Manacher's algorithm
	* Letter position lists
9. **Others**
	* Combinatorial search
		* Meet in the middle
		* Brute-force with pruning
		* Best-first (A*)
		* Bidirectional search
		* Iterative deepening DFS / A*
		* MiniMax
	* Sweeping
		* Discretization (convert to events and sweep)
		* Angle sweeping
		* Line sweeping
		* Discrete second derivatives
	* Data structures related
		* LCA (2^k-jumps in trees in general)
		* Pull/push-technique on trees
		* Heavy-light decomposition
		* Centroid decomposition
		* Lazy propagation
		* Self-balancing trees
		* Convex hull trick (wcipeg.com/wiki/Convex_hull_trick)
		* Monotone queues / monotone stacks / sliding queues
		* Sliding queue using 2 stacks
		* Persistent segment tree
	* Travelling salseman
	* Sliding window
	* 2 pointers
	* Fast & slow pointers
	* Merge interval
	* Cyclic Sort
	* 2 Heaps
	* K-way merge
	* Minimax
	* Line sweep
	* Rolling Hash
	* Reservoir sampling
	* Rejection sampling
	* Scan Line
	* Matrix fast exponentiation
	* Repeated squaring
	* Euler's Theorem
	* Fermat's Little theorem
	* Shunting yard algorithm: expression parsing
