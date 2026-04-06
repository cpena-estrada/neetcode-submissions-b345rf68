class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //priority_queue<int, vector<int>, greater<int>> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (const auto& num : nums) { min_heap.push(num);}

        while (!min_heap.empty() && min_heap.size() > k) { min_heap.pop(); }

        return min_heap.top();
    }
};


/*

kth largest element -> min heap size k 

*/