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
    bool dfs(TreeNode* curr, int left, int right) {
        if (!curr) { return true; }

        if ( !(left < curr->val && curr->val < right) ) {
            return false;
        }

        return dfs(curr->left, left, curr->val) && dfs(curr->right, curr->val, right);
    }
public:

    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX); //bounds
    }
};


/* 
-infinity < root_val < infinity
-infinity < 3 < 5
5 < 7 < infinity
5 < 4 < 7 ERRR kaboom
7 < 8 < infinity

            5
           / \
          3   7
             /\
            4  8
*/
