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
    // two pass approach
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int counter = 0;

        ListNode * temp = head;
        while (temp) {
            counter++;
            temp = temp->next;
        }

        int pos_to_remove = counter - n; 

        if (pos_to_remove == 0) {
            return head->next;
        }

        temp = head;
        for (int i = 0; i < pos_to_remove - 1; ++i) {
            cout << temp->val << "\n";
            temp = temp->next;
        }

        cout << temp->val << "\n";

        ListNode * eraser = temp->next;
        temp->next = temp->next->next;
        delete eraser;
        // eraser = nullptr
        return head;
    }
};

/* look at posted solution

original chopped solution:

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


with an array:

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
    
two pointer:

    // 1) Dummy node to simplify deletions
    ListNode dummy(0, head);
    ListNode* slow = &dummy;
    ListNode* fast = &dummy;

    // 2) Move fast n+1 steps ahead
    for (int i = 0; i < n + 1; ++i) {
        fast = fast->next;
    }

    // 3) Walk both pointers
    while (fast) {
        slow = slow->next;     this results in slow being before the one we want to deleate
        fast = fast->next;
    }

    // 4) Delete the target node
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete; // good hygiene in C++

    // 5) Return new head
    return dummy.next;

*/