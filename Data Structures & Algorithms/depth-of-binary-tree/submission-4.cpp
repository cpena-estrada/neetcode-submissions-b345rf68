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

        int left = maxDepth(root->left); //ask left for its height
        int right = maxDepth(root->right); // " right " "    "

        return 1 + max(left, right); // pick the larger height, add 1 to count the current node as a height
    }
};


/*

solution:

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