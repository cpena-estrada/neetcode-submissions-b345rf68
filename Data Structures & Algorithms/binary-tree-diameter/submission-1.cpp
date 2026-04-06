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
    int max_diameter = 0;

    // check left height + right height at each node and update global variable

    int dfs(TreeNode* root) {
        if (!root) { return 0; }

        int left = dfs(root->left);
        int right = dfs(root->right);

        int local_diameter = left + right;
        max_diameter = max(max_diameter, local_diameter);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // call function tha does dfs and modifies the global var
        // just return max diameter
        dfs(root);
        return max_diameter;
    }
};

/* 
the longest path between any two nodes can be in a subtree and not root

        1
       / 
      2
     / \
    3   6
   /     \
  4       7
           \
            8
Longest path from root: 1 → 2 → 6 → 7 → 8 → length = 4 edges
But the actual diameter: 4 → 3 → 2 → 6 → 7 → 8 → length = 5 edges

*/