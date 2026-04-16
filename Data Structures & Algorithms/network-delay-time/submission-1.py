from collections import defaultdict
import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj_list = defaultdict(list) # 1 - n

        for u, v, dist in times:
            adj_list[u].append((v, dist))

        # min time to reach all nodes
        inf = float('inf')
        distances = [inf] * (n + 1)
        distances[k] = 0

        h = [(0, k)] # (distance, node)
        heapq.heapify(h)

        while h:
            dist, node = heapq.heappop(h)

            # push neighboring nodes onto heap
            for nei, nei_dist in adj_list[node]:
                new_dist = dist + nei_dist
                if new_dist < distances[nei]: # only push if its cheaper
                    heapq.heappush(h, (new_dist, nei))
                    distances[nei] = new_dist

        # print(distances) [inf, 0, 1, 2, 3]
        max_dist = max(distances[1:])
        return max_dist if max_dist < inf else -1

        # adj_list = defaultdict(list)

        # for u, v, w in times:
        #     adj_list[u].append((v, w))

        # visited = set()
        # h = []
        # heapq.heappush(h, (0, k)) # time, node
        # # visited.add(k) not needed

        # while h:
        #     curr_time, node = heapq.heappop(h)

        #     if node in visited:
        #         continue

        #     visited.add(node) # you reached this node with the shortest distance, now mark it visited

        #     if len(visited) == n:
        #         return curr_time
                
        #     for nei, time in adj_list[node]:
        #         if nei not in visited:
        #             heapq.heappush(h, (curr_time + time, nei))
                        
        # return -1

    

"""

THIS IS DJISTRAKSS       no visited set()


adj = defaultdict(list)
        for u, v, w in times:
            adj[u].append((v, w))

        dist = [float('inf')] * (n + 1)
        dist[k] = 0
        heap = [(0, k)]

        while heap:
            cost, u = heapq.heappop(heap)
            if cost > dist[u]:   # stale entry, skip
                continue
            for v, w in adj[u]:
                if cost + w < dist[v]:
                    dist[v] = cost + w
                    heapq.heappush(heap, (dist[v], v))

        max_dist = max(dist[1:])
        return max_dist if max_dist < float('inf') else -1
"""