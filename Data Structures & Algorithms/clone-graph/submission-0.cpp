/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> mp; // <old, new>
public:

    Node* dfs(Node* node) {
        // if copy already made
        if (mp.count(node)) { return mp[node]; }

        // make a copy
        Node* clone = new Node;
        clone->val = node->val;

        // record it
        mp[node] = clone;

        for (const auto& neighbor : node->neighbors) {
            Node* nghbr_copy = dfs(neighbor); // make copy of neighbor and append to adj list
            clone->neighbors.push_back(nghbr_copy);
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (!node) { return node; } // empty graph case        
        return dfs(node);
    }
};

/*

pass in a node
    - check if copy already made

    - make a copy of the node 

    - iterate over original nodes neighbors
        - call dfs to make a copy and push back that copy to clone nodes adj list

*/