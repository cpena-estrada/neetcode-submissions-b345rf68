class Solution {
public:

    int find(int a, unordered_map<int, int>& parent_tbl) {
        if (parent_tbl[a] == a) { return a; }
        parent_tbl[a] = find(parent_tbl[a], parent_tbl); // path compression
        return parent_tbl[a];
    }

    bool unite(int a, int b, unordered_map<int, int>& parent_tbl, int& counter) {
        int a_parent = find(a, parent_tbl);
        int b_parent = find(b, parent_tbl);

        if (a_parent != b_parent) { // make parent/root of b be a_parent_root
            parent_tbl[b_parent] = a_parent;
            counter--;
            return true; 
        }
        return false; // cycle detected
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // initialize parent table
        unordered_map<int, int> parent_tbl;
        for (int i = 0; i < n; i++) { parent_tbl[i] = i; }

        int component_counter = n;

        for (const auto& edge : edges) { 
            int u = edge[0], v = edge[1];
            if (!unite(u, v, parent_tbl, component_counter)) { return false; }
        }

        // united all nodes, check if they are all connected (1 single component)
        if (component_counter == 1) { return true; }

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


DFS (Cycle detection):

class Solution {
    unordered_map<int, vector<int>> adj_list;
    unordered_set<int> visited; // use as number of components (path)
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

UNION FIND:

cycle detection: when running union, if they share the same parent, return false right away

fully connected: there should be a single component.
                 either keep a num_componenets variable initially equal to the number of nodes to decrement each time we union,
                  or simple iterate over the parrent array/map and count how many component's parent is equal to itself.



*/
