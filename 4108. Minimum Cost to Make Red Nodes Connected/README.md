# Minimum Cost

## Problem Overview

Given a tree with `n` nodes, a string `colors` representing the color of each node, and an edge list describing the tree, calculate the minimum cost required based on the distribution of red (`'R'`) and non-red nodes.

The solution uses tree traversal, subtree size calculation, and Dynamic Programming (DP) to determine the maximum possible gain and subtract it from the initial total cost.

## Approach

The solution combines four important techniques:

1. Adjacency List Construction.
2. BFS-like Tree Traversal.
3. Subtree Size Calculation.
4. Tree Dynamic Programming (DP).

### 1. Building the Adjacency List

```cpp
vector<vector<int>> adj(n);

for(auto &e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
}
```

- Create an adjacency list to represent the tree.
- Since the tree is undirected, add both directions for every edge.

### 2. Creating the Traversal Order

```cpp
vector<int> parent(n, -1);
vector<int> order;

order.push_back(0);
parent[0] = 0;
```

Start traversal from node `0`.

- `parent` stores the parent of every node.
- `order` stores the order in which nodes are visited.
- The root is its own parent.

Traverse the tree:

```cpp
for(int i = 0; i < order.size(); i++) {
    int u = order[i];

    for(int v : adj[u]) {
        if(v == parent[u]) continue;

        parent[v] = u;
        order.push_back(v);
    }
}
```

This creates a BFS-like traversal order without explicitly using a queue.

The parent check prevents traversal back to the previous node.

### 3. Calculating Subtree Sizes

```cpp
vector<long long> sub(n, 1);

for(int i = n - 1; i > 0; i--) {
    int u = order[i];
    sub[parent[u]] += sub[u];
}
```

Initially, every node contributes a subtree size of `1` (itself).

Process nodes in reverse traversal order:

- Take the current node.
- Add its subtree size to its parent.
- Continue until all child contributions reach their ancestors.

After this process, `sub[u]` represents the total number of nodes in the subtree rooted at `u`.

### 4. Calculating the Initial Total Cost

```cpp
long long total = 0;

for(int i = 0; i < n; i++) {
    if(colors[i] == 'R') {
        total += sub[i];
    }
}
```

For every red node, add its subtree size to the initial total.

This establishes the starting cost before applying the optimal gain.

### 5. Tree Dynamic Programming

```cpp
vector<long long> dp(n, 0);
long long best = 0;
```

Process nodes in reverse traversal order so that every child's DP value is already calculated before its parent.

```cpp
for(int i = n - 1; i >= 0; i--) {
    int u = order[i];

    long long gain = (colors[u] == 'R' ? sub[u] : -sub[u]);

    for(int v : adj[u]) {
        if(parent[v] == u) {
            gain += max(0LL, dp[v]);
        }
    }

    dp[u] = gain;
    best = max(best, dp[u]);
}
```

**Understanding the transition:**

- If the current node is red, its contribution is positive: `+sub[u]`.
- Otherwise, its contribution is negative: `-sub[u]`.
- For every child, add its DP contribution only if it is positive.
- `max(0LL, dp[v])` allows us to ignore negative contributions.

The DP calculates the maximum gain obtainable from a connected subtree rooted at each node.

`best` stores the maximum gain found across all nodes.

### 6. Final Answer

```cpp
return total - best;
```

Subtract the maximum achievable gain from the initial total cost.

## C++ Concepts Used

- Adjacency lists using 2D vectors.
- Range-based `for` loops.
- Parent tracking in tree traversal.
- Reverse traversal order.
- Subtree size aggregation.
- Tree Dynamic Programming.
- Ternary operator.
- `max(0LL, dp[v])` for ignoring negative contributions.
- `long long` for handling large values.
- `make_tuple()` and `auto` for tuple creation.

## Complexity Analysis

Let `n` represent the number of nodes.

| Operation | Time Complexity |
|---|---|
| Adjacency list construction | O(n) |
| Tree traversal | O(n) |
| Subtree size calculation | O(n) |
| Initial total calculation | O(n) |
| Tree DP | O(n) |

**Overall Time Complexity:** O(n)

**Space Complexity:** O(n)

The adjacency list, parent array, traversal order, subtree array, and DP array each require O(n) space.

## Key Learning

This solution demonstrates an important tree algorithmic pattern:

**Build traversal order → Process in reverse → Calculate subtree information → Apply DP.**

Important concepts learned:

1. How to represent an undirected tree using an adjacency list.
2. How to traverse a tree while maintaining parent relationships.
3. Why reverse traversal order is useful for bottom-up calculations.
4. How to calculate subtree sizes efficiently.
5. How to apply Dynamic Programming on trees.
6. How to combine local contributions from child subtrees using `max(0, dp[v])`.