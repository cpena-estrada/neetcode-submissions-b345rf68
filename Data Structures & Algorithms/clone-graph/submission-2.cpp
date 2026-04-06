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
    unordered_map<Node*, Node*> mp; // <old, new> serves as visited
public:

    Node* bfs(Node* source_node) {
        queue<Node*> q;
        q.push(source_node);
    
        Node* source_clone = new Node(source_node->val); // clone it
        mp[source_node] = source_clone; // keep track / mark visited so you dont duplicate clones

        while (!q.empty()) {
            //Node* 
            auto curr_node = q.front(); 
            q.pop();

            for (const auto& neighbor : curr_node->neighbors) {
                if (!mp.count(neighbor)) { // if neighbor node not yet cloned, clone it
                                                            // equivalent to these two lines:
                    mp[neighbor] = new Node(neighbor->val); // Node* clone = new Node(neighbor->val);
                                                            // mp[neighbor] = clone;
                    q.push(neighbor);
                }
                mp[curr_node]->neighbors.push_back(mp[neighbor]);
            }
        }
        return source_clone;
    }

    Node* cloneGraph(Node* node) {
        if (!node) { return node; } // empty graph case        
        return bfs(node);
    }
};

/*

pass in a node
    - check if copy already made

    - make a copy of the node 

    - iterate over original nodes neighbors
        - call dfs to make a copy and push back that copy to clone nodes adj list


DFS:

private:
    unordered_map<Node*, Node*> mp; // <old, new>
public:

    Node* dfs(Node* node) {
        // if copy already made
        if (mp.count(node)) { return mp[node]; }

        // make a copy
        Node* clone = new Node; // Node* clone = new Node(node->value);
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

BFS: my messy solution

private:
    unordered_map<Node*, Node*> mp; // <old, new> serves as visited
public:

    Node* bfs(Node* source_node) {
        queue<Node*> q;
        q.push(source_node);
    
        Node* source_clone = new Node(source_node->val); // clone it
        mp[source_node] = source_clone; // keep track / mark visited so you dont duplicate clones

        while (!q.empty()) {
            //Node* 
            auto curr_node = q.front(); 
            q.pop();

            for (const auto& neighbor : curr_node->neighbors) {
                if (mp.count(neighbor)) { // if a clone for this neighbor node alred made, append clone to currents adj list
                    mp[curr_node]->neighbors.push_back(mp[neighbor]);
                } else { // neighbor not cloned yet
                    Node* clone = new Node(neighbor->val);
                    mp[neighbor] = clone;
                    mp[curr_node]->neighbors.push_back(clone);
                    q.push(neighbor); // actual neighbor, not clone
                }
            }
        }
*/