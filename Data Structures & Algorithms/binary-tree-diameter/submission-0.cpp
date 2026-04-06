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

private:
    // compute the 
    int dfs(TreeNode* root, int& res) {
        if (!root) { return 0; }

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, (left + right));
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};

/*

diameter of a node n is # of edges on the left + # of edges on the right


this find the depth at each level, not diamter

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) { return 0; }

        int left = 0;
        int right = 0;

        if (root->left != nullptr) { // if root->left        bool expression, if true, aka if not nullptr
            left = diameterOfBinaryTree(root->left) + 1;
        }

        if (root->right != nullptr) {
            right = diameterOfBinaryTree(root->right) + 1;
        }

        int curr_max = max(left, right);

        return max(max_depth, curr_max);
    }

*/
