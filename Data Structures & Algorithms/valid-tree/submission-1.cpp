class Solution {
    unordered_map<int, vector<int>> adj_list;
    unordered_set<int> visited; // use as number of components
public:

    bool dfs(int node, int parent) {
        // if this node has been seen, its a cycle
        if (visited.count(node)) { return false; }

        visited.insert(node);
        for (const auto& neigh : adj_list[node]) {
            if (neigh == parent) { continue; } // dont explore because ping pong. just a mutual connection, not a cycle
            
            if (!dfs(neigh, node)) { return false; }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) { return false; }

        // build adj_list
        for (int i = 0; i < n; i++) { adj_list[i] = {}; }
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }

        if(!dfs(0, -1)) { return false; }

        if (visited.size() == n) { return true; } // visited should have n different nodes
        return false;
    }
};

/*
undirected

valid tree cannot have loops
must be connected 


         0 -- 3
        / \
       1   2
      /
     4

node | neighbors
 0      [1,2,3]
 1      [0,4]
 2      [0]
 3      [0]
 4      [1]


UNION FIND:

if num of components is not 1, it it aint valid 



*/
