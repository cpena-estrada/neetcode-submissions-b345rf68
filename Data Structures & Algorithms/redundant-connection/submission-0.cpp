class Solution {
public:

    int find(int a, unordered_map<int, int>& parent_tbl) {
        if (parent_tbl[a] == a) { return a; }
        parent_tbl[a] = find(parent_tbl[a], parent_tbl);
        return parent_tbl[a];
    }

    bool unite(int a, int b, unordered_map<int, int>& parent_tbl) {
        int a_parent = find(a, parent_tbl);
        int b_parent = find(b, parent_tbl);

        if (a_parent != b_parent) { 
            parent_tbl[b_parent] = a_parent;
            return true;
        }
        return false; // cycle
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // how many nodes? for n nodes there are n-1 edges.
        // but input already has te extra added edge! 
        int n = edges.size();

        unordered_map<int, int> parent_tbl;
        for (int i = 1; i <= n; i++) { parent_tbl[i] = i; }

        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            if (!unite(a, b, parent_tbl)) { return {a, b}; }
        }
        
        // there should always be an answer, so just a safety
        return {};
    }
};

/*

UNION FIND:

simply unite everything and keep track of edges which make cycles as you go
    if parents are the same

but how to return last one?

*/