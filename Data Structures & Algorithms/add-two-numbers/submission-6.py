# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res = ListNode()
        dummy = res
        carry = 0

        while l1 or l2 or carry:
            l1_digit = l1.val if l1 else 0
            l2_digit = l2.val if l2 else 0

            sum_ = l1_digit + l2_digit + carry

            if sum_ > 9:
                carry = sum_ // 10
                sum_ = sum_ % 10
            else:
                carry = 0
            
            res.next = ListNode(val=sum_)

            if l1: l1 = l1.next
            if l2: l2 = l2.next
            res = res.next

        return dummy.next


"""
res = ListNode()
carry = 0

while l1 and l2:

    sum = l1.val + l2.val + carry

    if sum > 9:
        carry = sum % 10
        sum = sum / 10
    else:
        carry = 0
    
    res.next = ListNode(val=sum)



"""