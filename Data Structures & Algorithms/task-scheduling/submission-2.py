from collections import defaultdict, deque
import heapq

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freqs = defaultdict(int) # str -> int
        h = [] # max heap of ( -freq, task_id) negative freq! for max heap
        q = deque() # queue of ( -freq, time it can be executed, task_id)
        time = 0

        # === build freq map and populate heap with -freq to behave as max heap ===
        for task in tasks:
            freqs[task] += 1

        for tid, freq, in freqs.items():
            heapq.heappush(h, (-freq, tid)) # can initially all be executed at time 0

        # === while there are tasks to execute ===
        while h or q:
            # if anything in cooldown can be executed now
            if q and q[0][1] <= time:
                freq, exec_time, tid = q[0] # freq is alr negative, dont negate it again
                q.popleft() # pop
                heapq.heappush(h, (freq, tid))

            if h:
                freq, tid = h[0]
                heapq.heappop(h)
                freq += 1 # "decrese" freq as it will be "executed". + 1 because freq is negatove
                if freq < 0: # freq is negative so < 0 instead of > 0
                    time_to_execute = time + n + 1 # inclusive 
                    q.append((freq, time_to_execute, tid)) # append to queue (our cooldown) 

            time += 1
        
        return time       

"""
idea:
execute greatest frequency first

Each time unit:
	1.	If something in cooldown becomes ready now, move it from q back to heap
	2.	If heap has tasks, pop most frequent, execute once, and if it still has remaining count, put it into cooldown with ready time t + n + 1
	3.	Otherwise, you’re idling
	4.	Increment time

A-Z


abca idle a 6

a idle a idle a b c 7 

max heap (frequency, taskid)

- each iteration is a cycle

while h:

    can you do queue:
        do it and continue
    
    top and pop

    if top task can be done:
        do it
        if there are tasks left
        append it to a queue
        
        a queue because time increases, so it will have shape t, t+1, t+2
        can pop at front, calc next time, and append it to queue

3, A

2, A -> curr_cylce + n, A

dry run ex1:
2x
2y

do x

queue = [(3, x)]





"""