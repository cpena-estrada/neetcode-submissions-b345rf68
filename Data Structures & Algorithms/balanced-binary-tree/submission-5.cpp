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

    int dfs(TreeNode* root) {
        if (!root) { return 0; }

        int left = dfs(root->left);
        int right = dfs(root->right);

        // check if its is height balanced
        int difference = abs(left - right);
        if (difference > 1) { balanced = false; }

        // propagate height back up. would return >= 0
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;
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


original idea
    int dfs(TreeNode* root) {
        if (!root) { return 0; }

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == -1 || right == -1 ) { return -1; } // this is why we have this check. to actually return -1 and not a height

        // check if its is height balanced
        int difference = abs(left - right);
        if (difference > 1) { return -1; } // this would make either left or right = -1

        // propagate height back up. would return >= 0
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if (dfs(root) == -1) {
            return false;
        }
        return true;
    }

*/
