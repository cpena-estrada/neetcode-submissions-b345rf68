#include <queue>

class KthLargest {
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
};

/*

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



*/