import heapq
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class NodeWrapper:
    def __init__(self, node, tie):
        self.node = node
        self.tie = tie

    """
    __lt__ is the method Python calls when it evaluates a < b.

    we are comparing NodeWrapper objects, specifically,
    we want to compare the node.val attribute 

    ex:
    w1 = NodeWrapper(node1)
    w2 = NodeWrapper(node2)

    w1 < w2 

    translates to 
    w1.__lt__(w2)    
    """
    def __lt__(self, other):
        if self.node.val != other.node.val: # comapre by .val
            return self.node.val < other.node.val
        return self.tie < other.tie # compare by tie breaker


class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        h = [] # heap of NodeWrapper objects!
        tie = 0 # unique incremental key for tiebrakers
        tail = ListNode()
        dummy = tail

        for head_node in lists:
            if head_node:
                heapq.heappush(h, NodeWrapper(head_node, tie))
                tie += 1
            
        while h:
            wrap = h[0]
            heapq.heappop(h)

            node = wrap.node # actually extracted the node. is out min thank to our wrapper __lt__

            tail.next = node
            tail = tail.next

            node = node.next

            if node:
                tie += 1
                heapq.heappush(h, NodeWrapper(node, tie))

        return dummy.next
            




"""
min heap of nodes

push head of each list

my mind wants to push a node, and have a custom comparator that compares nodes by their value

i mean i can also just push tuples if (value, node)
but what if there is a tie and then it compares by the second element? this would be an error no, since there is no defualt behavior for nodes

two options:
    - stick tuples but have second element be an alwyas incrementing key
        - always has a tiebreaker
    - write a custom comparator, aka a wrapper

WITH A COMPARATOR:

got you so dunder are always there for any class. the thing is that in this problem, we are given the ListNode  class and we are unable to modify it. so we make a wrapper, where one of the members is a ListNode, and deifne the __lt__ method for < comparisons, which min_heap uses

so we make a min_heap of wrappers, not of ListNode. we jsut extract the ListNode to do ourt work/logic

=========================================================

TUPLE WITH INCREMENT KEY APPROACH:

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        h = [] # min heap of (value, tiebreaker, node)
        unique_key = 0
        tail = ListNode()
        dummy = tail

        for head_node in lists:
            if head_node:
                heapq.heappush(h, (head_node.val, unique_key, head_node))
                unique_key += 1
        
        while h:
            val, key, node = h[0]
            heapq.heappop(h)

            tail.next = node
            tail = tail.next

            node = node.next

            if node:
                unique_key += 1
                heapq.heappush(h, (node.val, unique_key, node))
            
        return dummy.next


=========================================================
merging two lists at a time (BRUTE FORCE)

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        
        if not lists: return None
        if len(lists) == 1: return lists[0]

        # at least two linked lists

        head = lists[0]

        for list_ in lists[1:]:
           head = self.merge(head, list_)

        return head

    def merge(self, l1, l2):
        tail = ListNode()
        dummy = tail
        while l1 and l2:
            if l1.val < l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            
            tail = tail.next
        
        if l1:
            tail.next = l1
        else:
            tail.next = l2

        return dummy.next
"""
