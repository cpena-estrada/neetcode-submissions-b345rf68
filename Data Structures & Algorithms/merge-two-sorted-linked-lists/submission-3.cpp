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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; 
        ListNode * temp = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
            //  temp = temp->next; could just have it out here 

        }

        if (list1 == nullptr) {
            temp->next = list2;
        }
        else {
            temp->next = list1;
        }
        
        return dummy.next;
    }
};


/*

if you wanna have 3 if checks for <, >, and ==
ADVANCE THE LIST<#> ALWAYS

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {            // case 1: l1 smaller
            tail->next = list1;
            list1 = list1->next;
        } else if (list1->val > list2->val) {     // case 2: l2 smaller
            tail->next = list2;
            list2 = list2->next;
        } else {                                  // case 3: equal values
            // Append list1 first for stability (could do both here if you wanted)
            tail->next = list1;
            list1 = list1->next;
        }
        tail = tail->next;
    }

    // hook the remainder
    tail->next = (list1 ? list1 : list2);
    return dummy.next;
}

*/
