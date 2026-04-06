/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode  result;
        ListNode * dummy = &result;
        int carry = 0;

        // traverse over both lists. if one list has more numbers than the other, make the value of ther be 0

        while (l1 || l2) {
            int x = l1 != nullptr ? l1->val : 0;    // int x, y;
            int y = l2 != nullptr ? l2->val : 0;    // if (l1 == nullptr) {
                                                    //     x = 0;
                                                    // } else {
                                                    //     x = l1->val;
                                                    // }

                                                    // if (l2 == nullptr) {
                                                    //     y = 0;
                                                    // } else {
                                                    //     y = l2->val;
                                                    // }

            int sum = x + y;
            sum += carry;
            int digit = 0;

            // reset carry
            carry = 0;
            if (sum >= 10) {
                digit = sum % 10; // 8 //remainder of 10 going into 18
                carry = sum / 10; // 1 //how many times does 10 go into 18
            }
            else {
                digit = sum;
            }

            ListNode * res = new ListNode(digit);
            dummy->next = res;

            //advance pointers
            dummy = dummy->next;
            if (l1) { l1 = l1->next; } // only advance if they are not null
            if (l2) { l2 = l2->next; }
        }

        if (carry > 0) {
            ListNode* res = new ListNode(carry);
            dummy->next = res;
        }

        return result.next;
    }
};

/*

ListNode  result;
ListNode * dummy = &result;
int carry = 0;

traverse over both lists

while l1 and l2

    sum = l1.val + l2.val
    sum += carry

    // reset carry
    carry = 0;
    if (sum >= 10) {
        int first = sum / 10;
        int carry = sum % 10;
    }
    else {
        first = sum;
    }

    ListNode * res(first) = new ListNode;
    dummy->next = res;

    //advance pointers
    dummy = dummy->next;
    l1 = l1->next;
    l3 = l2->next;

*/