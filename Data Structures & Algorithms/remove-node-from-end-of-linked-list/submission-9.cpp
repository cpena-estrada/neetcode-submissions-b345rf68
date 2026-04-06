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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;

        ListNode * temp = head;
        while (temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int pos_to_delete = nodes.size() - n;

        // if you are deleating head
        if (pos_to_delete == 0) {
            return head->next;
        }

        nodes[pos_to_delete - 1]->next = nodes[pos_to_delete]->next;
        delete(nodes[pos_to_delete]);

        return head;
    }
};

/*

original solution:

        ListNode * temp = head;
        ListNode * node_bef = head;
        ListNode * exterminator;

        int count = 0;

        if(head == nullptr){
            return head;
        }//else if(head->next == nullptr){
           // return nullptr;
        //}

        while(temp != nullptr){
            count++;
            temp = temp->next;
        }

        //had to dig for this one!
        if(count-n == 0){
            return head->next;
        }
        
        //get to node before the node you want to remove
        for(int i=1; i < (count-n); i++){
            node_bef = node_bef->next;
        }

        exterminator = node_bef->next;
        node_bef->next = node_bef->next->next;
        delete exterminator; 
        exterminator = nullptr;
        
        return head;
*/