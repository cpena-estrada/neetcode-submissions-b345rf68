/* 

function to calculate manhattan distance given 2 points
                    point a          point b                
double calc_dist(vector<int> &i, vector<int> &j) { //pass by reference
    return ( abs(i[0] - j[0]) + abs(i[1] - j[1]) );
} 

// build parent table
    -since i represents node ids we can do easy vector way
    -iterating over edges and appending each node to a id ; id map


*/

class Solution {
public:

    int find_root(int id, vector<int> &parent) {
        if (parent[id] == id) return id;
        parent[id] = find_root(parent[id], parent);
        return parent[id];
    }

    void unite_roots(int a, int b, vector<int> &parent) {
        int a_root = find_root(a, parent);
        int b_root = find_root(b, parent);

        if (a_root != b_root) {
            parent[b_root] = a_root; //parent[a_root];
        }
    }
    
    int calc_dist(vector<int> &i, vector<int> &j) { //pass by reference
        return ( abs(i[0] - j[0]) + abs(i[1] - j[1]) );
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n_nodes = points.size();
        vector<tuple<int, int, int>> edges;
        vector<int> parent(n_nodes);
        int total_cost = 0;
        //vector<tuple<int, int, int>> mst_edges;

        for (int i = 0; i < n_nodes - 1; ++i) {
            for (int j = i+1; j < n_nodes; ++j) {
                int dist = calc_dist(points[i], points[j]);
                edges.push_back(make_tuple(i, j, dist));
            }
        }

        // for(const auto& edge : edges) {
        //     cout << get<0>(edge) << get<1>(edge) << get<2>(edge) << "\n";
        // }

        for (int i = 0; i < n_nodes; ++i) {
            parent[i] = i;
        }

        // for (const auto& i : parent) {
        //     cout << i << "\n";
        // }
        
        //kruskals needs egdes in smalles order first (increasing)
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
            return get<2>(a) < get<2>(b);
        });

        // for(const auto& edge : edges) {
        //     cout << get<0>(edge) << get<1>(edge) << get<2>(edge) << "\n";
        // }

        // Start Kruskal's 

        int edges_used = 0;

        for (const auto& edge : edges) {
            int a = get<0>(edge);
            int b = get<1>(edge);
            int dist = get<2>(edge);
            int a_root = find_root(a, parent);
            int b_root = find_root(b, parent);

            if (a_root == b_root) {
                continue; //skip in same component/cycle
            }

            unite_roots(a, b, parent);
            total_cost += dist;
            //mst_edges.push_back(edge);
            edges_used++;
            
            if (edges_used == n_nodes - 1) {
                break;
            }
        }
        return total_cost;
    }
};
