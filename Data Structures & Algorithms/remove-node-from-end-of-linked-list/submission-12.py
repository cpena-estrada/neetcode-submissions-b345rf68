# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head:
            return None

        # figure our len of list
        curr = head
        sz = 0
        while curr:
            curr = curr.next
            sz += 1

        # node to remove
        remove = sz - n
        if remove == 0:
            return head.next

        
        curr = head
        for i in range(remove - 1):
            curr = curr.next

        if curr.next:
            curr.next = curr.next.next

        return head
            