from collections import defaultdict

class TimeMap:

    def __init__(self):
        self.kv_store: dict[str, list[tuple[str, int]]] = defaultdict(list)        

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.kv_store[key].append((value, timestamp))

        # # if you didnt have default dict:
        # if key in kv_store:
        #     kv_store.append((value, timestamp))
        # else:
        #     kv_store[key] = [(value, timestamp)]

    def get(self, key: str, timestamp: int) -> str:

        # check if key exists or list for thst key is empty 
        if key not in self.kv_store or not self.kv_store[key]:
            return ''
        

        # # most recent values thats <= given timestamp
        # for val, tmp in list(reversed(self.kv_store[key])): # do i need the list() here? is is that only when i do zip()
        #     if tmp <= timestamp:
        #         return val

        # binary search it instead
        val = ''
        left, right = 0, len(self.kv_store[key]) - 1
        while left <= right:
            mid = (left + right) // 2
            
            if self.kv_store[key][mid][1] <= timestamp:
                val = self.kv_store[key][mid][0]
                left = mid + 1
            else:
                right = mid - 1

        return val


        
"""

key -> [value, timestamp]


"""