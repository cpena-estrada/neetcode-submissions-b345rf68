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

    int dfs(TreeNode* root) {
        if (!root) { return 0; }

        int left = dfs(root->left);
        int right = dfs(root->right);

        int difference = abs(left - right);
        if (difference > 1) { return -500; }

        // propagate height back up
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if (dfs(root) < 0) {
            return false;
        }

        return true;
    }
};

/*

get height of each tree/subtree. 
compare if heights different by no more than 1
    - if they differ, return -1


idea assuming dfs returns bool:

        // if (dfs(root)) {
        //     return true;
        // } else {
        //     return false;
        // }

        // return dfs(root) ? true : false;

*/
