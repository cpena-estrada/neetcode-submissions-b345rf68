class Solution {
public:
    // pass in the point in points, hardcode the origin 0,0
    double euclidean(double x, double y) {
        int sum = 0;
        sum += (0-x) * (0-x);
        sum += (0-y) * (0-y);
        return sqrt(sum);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;

        // comparator for heap. make it compare by .first of pairs
        auto cmp = [](const auto& a, const auto& b) {
            return a.first < b.first;
        };

        priority_queue<
            pair<double, vector<int>>, /* dist, [point, point] */
            vector<pair<double, vector<int>>>,
            decltype(cmp)
            > max_heap(cmp); // pass in the comparator to constructor
        
        // push distances and corresponding points
        for (const auto& point : points) {
            double dist = euclidean(point[0], point[1]);
            max_heap.push(make_pair(dist, point));
        }

        while (max_heap.size() > k && !max_heap.empty()) {
            if (max_heap.size() > k) { max_heap.pop(); }
        }

        // go over all elements in heap, append lists to res. heap is of size k
        for (int i = 0; i < k; ++i) {
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return res;
    }
};

/*
opposite of kth largest element in stream,
use a max heap of size k to maintain the k shortest distances

stil use {distance, point} idea. make heap compare by distance. 
if comapring pairs, it defualts by first, then second. 
we need a comparator/lambda to prevent comparison of point vector

heap lesson:

priority_queue<T, vector<T>, Compare> pq;

The heap keeps the element x “above” y if Compare(x, y) returns false.
    In other words:
        - if your comparator says "a has less priority than b", it returns true.


    AKA JUST THIS (opposite from lambda vectors):
    - Max-heap (largest first)	return a < b;
    - Min-heap (smallest first)	return a > b;

max heap example:

    auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.first < b.first;   // max-heap: larger first stays on top
    };

priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

example min heap:

    auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.first > b.first;   // smaller first stays on top
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);








original ideas

min heap of pairs or tuples where we have the point as a vec and the dist to origin like:
    [0,2], distance

instead, iter over points, calc distances, and push to heap
maintain a has map of distaces to points like
    2.2 -> [[points], [points]]
*/