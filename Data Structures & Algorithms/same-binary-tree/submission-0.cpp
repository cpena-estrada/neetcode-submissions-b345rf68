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

    bool balanced = true;

    void dfs(TreeNode* p, TreeNode* q) {
        // structure check #1: if both are empty (either initially or when they reach null)
        if (!p && !q) { return; }
        // structure check #2: if one is null and not the other
        if (!p || !q) { 
            balanced = false; return; 
        }
        // val
        if (p->val != q->val) {
            balanced = false;
            return;
        }

        dfs(p->left, q->left);
        dfs(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p,q);
        return balanced;
    }
};
