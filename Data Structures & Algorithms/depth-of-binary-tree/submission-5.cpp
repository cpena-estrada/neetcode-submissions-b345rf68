/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) { return 0; }

        stack<pair<TreeNode* , int>> stk; // <node, depth>
        int res = 0;

        stk.push({root, 1});

        while (!stk.empty()) {
            // get data at this level
            TreeNode* curr_node = stk.top().first;
            int curr_depth = stk.top().second;
            stk.pop(); // you processed, so pop it
            
            // update result variable
            res = max(res, curr_depth);

            if (curr_node->left) { stk.push({curr_node->left, curr_depth + 1}); }
            if (curr_node->right) { stk.push({curr_node->right, curr_depth + 1}); }
        }
        return res;
    }
};


/*

iterative with a stack:
    this way will end up pushing the leaf nullptr children 
    they wont affect res, as the dont pass the if node check
    they just get popped
    same result, extra space for no reason tho

        if (!root) { return 0; }

        stack<pair<TreeNode*, int>> the_stack; // <node, depth>

        the_stack.push({root, 1});
        int res = 0;

        while (!the_stack.empty()) {
            auto [node, depth] = the_stack.top();
            // TreeNode* node = stack.top().first; //get node 
            // int depth = stack.top().second; // get depth at this node
            the_stack.pop();
            
            if (node) { // if you push right first, left will be on top of stack so its processed first. order doesnt matter tho
                res = max(res, depth); //update best result
                the_stack.push({node->left, depth + 1});
                the_stack.push({node->right, depth + 1});
            }
        }
        return res;

recursive solution:
    
        if (!root) { return 0; }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;



post order (process left, right, finally parent)
think: yo left, whats your height? yo right, wbu? aight now i know my depth


my intuative way:

        if(root==nullptr){
            return 0;
        }

        int left = maxDepth(root->left)+1;
        int right = maxDepth(root->right)+1;

        return max(left, right);

*/