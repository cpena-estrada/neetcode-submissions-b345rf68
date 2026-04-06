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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        // it is guaranteed p and q exist in the bst, so loop until found
        while(true) {
            // if p & q are less than current node
            if (p->val < curr->val && q->val < curr->val)  {
                curr = curr->left;
            }
            // if p & q are greater than current node
            else if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            } //p&q are in different side (or one is equal to cur->val)
            else {
                return curr;
            }
        }
        return nullptr;
    }
};

/*

the p & q are in the same side, the current node could not be the LCA
because there is a node below where p and q are in different sides

    so 8 is an ancensor but not the lowest

if p & q are in different side, the current node is the LCA

          8
         /  \
        5   100
      /  \
    3     6
        /  \
       4    7


*/