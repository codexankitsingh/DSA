#include <bits/stdc++.h>
using namespace std;

// Function to calculate subtree sizes using DFS
void calculateSubtreeSizes(int node, int parent, vector<vector<int>>& tree, vector<int>& subtreeSizes) {
    subtreeSizes[node] = 1;  // Each node is part of its own subtree
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            calculateSubtreeSizes(neighbor, node, tree, subtreeSizes);
            subtreeSizes[node] += subtreeSizes[neighbor];
        }
    }
}

vector<int> subtreeQueries(int n, vector<pair<int, int>>& edges, vector<pair<int, int>>& queries) {
    // Step 1: Build the tree using adjacency list
    vector<vector<int>> tree(n + 1);
    for (auto& edge : edges) {
        tree[edge.first].push_back(edge.second);
        tree[edge.second].push_back(edge.first);
    }

    vector<int> results;

    // Step 2: Process each query
    for (auto& query : queries) {
        int x = query.first, k = query.second;

        // Step 3: Calculate subtree sizes with x as the root
        vector<int> subtreeSizes(n + 1, 0);
        calculateSubtreeSizes(x, -1, tree, subtreeSizes);

        // Step 4: Collect subtree sizes and sort
        vector<int> sizes;
        for (int i = 1; i <= n; ++i) {
            if (i != x) {
                sizes.push_back(subtreeSizes[i]);
            }
        }
        sizes.push_back(subtreeSizes[x]);  // Include the root's subtree
        sort(sizes.begin(), sizes.end());

        // Step 5: Find the k-th smallest subtree size
        results.push_back(sizes[k - 1]);
    }

    return results;
}

int main() {
    // Input example
    int n; // Number of vertices
    cin >> n;

    vector<pair<int, int>> edges; 
    for (int i = 0; i < n - 1; i++) { // A tree with n nodes has n-1 edges
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int q; // Number of queries
    cin >> q;

    vector<pair<int, int>> queries; 
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }

    // Solve the problem
    vector<int> results = subtreeQueries(n, edges, queries);

    // Output results
    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}
