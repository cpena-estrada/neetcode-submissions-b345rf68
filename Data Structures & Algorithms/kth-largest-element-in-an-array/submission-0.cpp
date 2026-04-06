class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //priority_queue<int, vector<int>, greater<int>> max_heap;
        priority_queue<int, vector<int>, greater<int>> max_heap;

        for (const auto& num : nums) { max_heap.push(num);}

        while (!max_heap.empty() && max_heap.size() > k) { max_heap.pop(); }

        return max_heap.top();
    }
};


/*

kth largest element -> min heap size k 

*/