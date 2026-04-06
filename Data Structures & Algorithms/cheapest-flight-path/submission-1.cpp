class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using t = tuple<int, int, int>; // cost, node, # of stops
        priority_queue<t, vector<t>, greater<>> min_heap;
        unordered_set<int> visited;
        unordered_map<int, vector<pair<int, int>>> adj_list; // dst, cost

        // build adjacency list
        for (const auto& flight : flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            adj_list[u].push_back({v, w});
        }

        min_heap.emplace(0, src, 0); // cost, node, # of stops

        while (!min_heap.empty()) {
            auto [cost1, node1, num_stops] = min_heap.top(); 
            min_heap.pop();
        
            // k + 1 because 1 edge travelled equals 0 stops (read below)
            if (node1 == dst && num_stops <= k + 1) { return cost1; }

            // push neighbors if any
            if (adj_list.count(node1)) {
                for (const auto& [node2, cost2] : adj_list[node1]) {
                    min_heap.emplace(cost1 + cost2, node2, num_stops + 1);
                }
            }
        }

        // not reachable
        return -1;
    }
};

/*

start at cost 0, src, 0 stops:
    (0, 0, 0)

at 1:
    (200 + 100, 2, 1)
    (200 + 300, 3, 1)

at 2: 
    (300 + 100, 3, 2)
    (200 + 300, 3, 1)

at 3:
    3 == src but 2 stops instead of 1. 

    (200 + 300, 3, 1)

at the 3 pushed from node 1:
    3 == src and # stops <= k
    
why a list of candidates of costs that finish within k stops isnt needed:

the if statement within the heap only accept the fisrt instace of reaching dst within k stops.
since it is a mean heap ordered by distance, the frisst return will be the answer


wihin K stop meaning:

stop is an intermediate aiport (nor countiung src and dst)
flight (edge) is a hop between airports

                edges (flights)  stops(intermediate noded)
src → dst               1                    0
src → A → dst           2                    1
src → A → B → dst       3                    2

so if i flight uses e edges, it has e-1 stops


or you could have a stops varible that increments at each airport

just have a line that handles a direct flight from src
    If v == dst, stops stays as-is



original idea:
the bfs will finish no matter what

extract node

if visited continue

mark as visited
if its the destination, append to a list the cost and the # of stop(s) you are at

(so maybe the heap could include <distance, node, # of stop which incremets by 1 on each level of the dfs>)

explore and push any neigbors onto heap. keep track of cost and # of stops

an after bfs is over, iterate over list you built and extract the min cost with # of stops <=k

*/