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
    bool hasCycle(ListNode* head) {
        //p1 take 1 step and p2 takes two step 
        //if at one point, p1 == p2

        ListNode * p1 = head;
        ListNode * p2 = head;

        if(head->next == nullptr){
            return false;
        }

        while(p1 != nullptr && p2 != nullptr){
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1 == p2){
                return true;
            }
        }
        return false;

    }
};
