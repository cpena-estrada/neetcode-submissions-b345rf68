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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {return nullptr; }

        ListNode* res;
        ListNode* temp = res;

        auto cmp = [](const auto& a, const auto& b) { // > min, < max
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_heap(cmp);

        // push heads of lists only if not null
        for (const auto& node : lists) {
            if (node) { min_heap.push(node); }
        }

        while (!min_heap.empty()) {
            ListNode* node = min_heap.top();
            min_heap.pop();

            // add value to result
            temp->next = node; 
            temp = temp->next;

            // advance the list of the node popped
            node = node->next;

            // push only if not null
            if (node) { min_heap.push(node); }
        }
        
        return res->next;
    }
};

/*

MIN HEAP:

push heads of each list

compare by val of node

top and pop smallest one, add it to resul list, advance it, push it

if null, dont even push is

BRUTE FORCE:

join two lists at a time

initialize a result list

function where you pass in result and lists[i]
    merge them. 

    call fuction on each lists[i]


*/