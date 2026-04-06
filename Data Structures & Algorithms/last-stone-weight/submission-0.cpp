class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap(stones.begin(), stones.end());

        while (!max_heap.empty()) {
            if (max_heap.size() == 1) {return max_heap.top(); } // dont want to pop whats not there

            int x = max_heap.top(); max_heap.pop(); // top and pop
            int y = max_heap.top(); max_heap.pop();

            if (x == y) { continue; }

            int greater = max(x,y);
            int smaller = min(x,y);

            int new_stone = greater - smaller;
            max_heap.push(new_stone);
        }
        
        return 0; // only gets here if it didnt return in the loop
    }
};


/*
nah fuck you and your stone weight 



*/