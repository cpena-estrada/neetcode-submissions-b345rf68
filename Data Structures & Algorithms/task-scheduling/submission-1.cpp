class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> max_heap; // freq of task left, time task can be done
        queue<pair<int,int>> q;
        unordered_map<char, int> letter_freq;
        int time = 0;

        // letter : frequency
        for (const auto& c : tasks) {
            if (letter_freq.count(c)) {
                letter_freq[c]++;
            } else {
                letter_freq[c] = 1;
            }
        }

        // heap of the frequencies
        for (const auto& pair : letter_freq) { 
            if (pair.second > 0) {
                max_heap.push(pair.second);
            }
        }

        while(!max_heap.empty() || !q.empty()) {
            time++; // cycle happens no matter what

            if (!max_heap.empty()) { 
                int count = max_heap.top(); 
                max_heap.pop();

                count--;
                if (count > 0) {
                    q.push({count, time + n}); //if repeated task not done, push to q to know when we can process
                }
            }

            if(!q.empty() && q.front().second == time) { 
                max_heap.push(q.front().first); // push the num of tasks
                q.pop();
            }
        }
        return time;
    }
};

/*

A - Z

while(!max_heap.empty() ) {
    freq = top
    pop heap
    freq--;
    time++

    if (freq == 0)
        continue
    
    q.push({freq, time + n})

    // check if q.front() can be processed:
    if (!q.empty() && q.front().second == time)
        max_heap.push(q.front.first) // push the num of tasks
        q.pop()
}

while (!q.empty()) {
    if (q.front().second == time) {
        q.front().first--
    }

    if (q.front().first--) {
        q.pop
    }
    time++;
}

3 1 1

pop 3       time  = 1

3 - > 2

not zero so move onto q
q: {3, 1+3 = 4} 

1

pop 1       time = 2
1 - > 0


pop 1   time = 3
1 - > 0 

*/