class Node:
    def __init__(self, key: int = 0, val: int = 0):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.kv_store = {} # dict[int, Node]
        self.capacity = capacity

        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head


    def get(self, key: int) -> int:
        if key not in self.kv_store:
            return -1

        # move it to the front
        self.detach(self.kv_store[key])
        self.add_to_head(self.kv_store[key])
        return self.kv_store[key].val

    def put(self, key: int, value: int) -> None:

        if key in self.kv_store:
            node = self.kv_store[key]
            node.val = value
            self.detach(node)
            self.add_to_head(node)
            return

        # not in there 
        node = Node(key, value)
        self.kv_store[key] = node
        self.add_to_head(node)
        
        if len(self.kv_store) > self.capacity:
            # pop the last one
            lru = self.tail.prev
            self.detach(lru)
            del self.kv_store[lru.key]

    def detach(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        
    def add_to_head(self, node):
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node

        
"""
fixed capacity

get returns value for key and moves to the front


dict int node with val 

get and put move to used 



"""