//Dijkstras algo (weighted and andirected)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // min heap for our bfs. distance to node : the node
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<>> min_heap;
        unordered_set<int> visited; 

        // build adjacency list u : (v, w)
        unordered_map<int, vector<pair<int, int>>> adj_list;
         for (const auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj_list[u].push_back({v, w});
        }

        
        // push source node
        min_heap.push({0, k});

        int dist = 0; // aka your time
        while(!min_heap.empty()) {
            auto [weight1, node1] = min_heap.top(); // top and pop
            min_heap.pop();

            if (visited.count(node1)) { continue; }; // skip if visited

            visited.insert(node1); // mark as visited
            dist = weight1; // keep track of distance each iter. will always be the min distance thanks to min_heap

            // explore neighbors if any
            if (adj_list.count(node1)) {
                for (const auto& [node2, weight2] : adj_list[node1]) { // MAKE SURE ORDER MATCHES
                    // push neighbors and total distance onto heap
                    min_heap.push({weight1 + weight2, node2});
                }
            }
        }

        if (visited.size() == n) {
            return dist;
        } else {
            return -1;
        }
    }
};

/*

minimum time it takes to reach all nodes
    aka the shortest path as weight represents time



used structured bindings/unpacking instead^:

        for (const auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj_list[u].push_back({v, w});
        }

// + 1 since nodes are 1 indexed (distances[0] unused)
vector<int> distances(n + 1, 1e9);
*/