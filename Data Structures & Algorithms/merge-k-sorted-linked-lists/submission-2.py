import heapq
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        h = [] # min heap of (value, tiebreaker, node)
        unique_key = 0
        tail = ListNode()
        dummy = tail

        for head_node in lists:
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

extract top and pop

append to reuslt linked list

advance popped node,

if not null
    increment the key and push onto heap


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
