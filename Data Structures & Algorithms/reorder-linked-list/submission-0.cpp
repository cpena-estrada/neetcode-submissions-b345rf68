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
    void reorderList(ListNode* head) {
        // find the middle of the list
        ListNode * fast = head;
        ListNode * slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) { // this stops when slow is somewhere near the middle
            fast = fast->next->next;
            slow = slow->next;
        }

        // cout << fast->val << "\n"; //6
        // cout << slow->val;         //4

        // slow is now at middle of the list. lets condire it the endning of the first list
        ListNode * middle = slow;
        // therefore slow->next is the beggining of the second half

        // reverse the second half
        ListNode * prev = nullptr;
        ListNode * curr = middle->next;
        ListNode * next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // prev is no the beggining of the reversed second half of the list

        // the gotcha
        middle->next = nullptr;  // isolate the first half (make the end of the first half point to null)
        
        ListNode * first = head;
        ListNode * second = prev;

        // merge alternitavely
        while (first != nullptr && second != nullptr) {
            ListNode* tmp1 = first->next;   // save next of first
            ListNode* tmp2 = second->next;  // save next of second

            first->next  = second;          // link first -> second
            second->next = tmp1;            // link second -> next of first

            first  = tmp1;                  // advance first
            second = tmp2;                  // advance second
        }
        
    }
};
