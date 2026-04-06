#include <queue>

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this-> k = k;
        for (const auto& num : nums) {
            min_heap.push(num);
        }
        //while (min_heap.size() > k) { min_heap.pop(); }
    }
    
    int add(int val) {
        min_heap.push(val);
        while (min_heap.size() > k) { min_heap.pop(); }
        return min_heap.top(); // this would be the kth largest because its a min heap (aka largest at bottom, smallest on top.)
                               // smallest being the kth largest 
    }
};

/*

trick. build a min heap of size k. while it exceeds size k, pop.
    - this pops the smallest element
    - at the end, it leaves you with the k largest largest elements


1, 2, 3, 3

add 3 and return 3rd largest

1, 2, 3, 3, 3

if you want a min heap, use the template:

priority_queue<int, vector<int>, greater<int>> pq;
pq.push(10);
pq.push(5);
pq.push(20);

cout << pq.top() << "\n"; // 5 (smallest element)

breakdown:

priority_queue<
    Type,                 // what you store (e.g. int)
    Container (vector),   // where elements are stored
    Comparator            // how to order them
>

my solution:

private:
    priority_queue<int> heap; // max heap by default
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        priority_queue<int> heap(nums.begin(), nums.end());
        
        this->heap = heap;
        this->k = k;
    }
    
    int add(int val) {
        heap.push(val);

        priority_queue<int> copy = heap;
        for (int i = 0; i < k - 1; ++i) { // because k is 1 indexed (first, second) and i is 0 indexed
            copy.pop();
        }
        return copy.top();
    }


*/