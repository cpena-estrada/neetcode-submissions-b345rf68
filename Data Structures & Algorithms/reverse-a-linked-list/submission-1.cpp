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

    //.         0    - >    0      ->   0 
    //         curr        next
    //   prev
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = nullptr;
        ListNode * curr = head;
        ListNode * next = nullptr;

        if(curr == nullptr){
            return nullptr;
        }else{
            while(curr != nullptr){
                next = curr->next; 
                curr->next = prev; 
                prev = curr;
                curr = next;
            }
        }

        return prev;
        
    }
};
