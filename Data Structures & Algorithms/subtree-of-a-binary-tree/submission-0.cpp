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

    bool same_tree(TreeNode* p, TreeNode* q) {
        if (!p && !q) { return true; } // both reach null or both empty (same structure)
        if (!p || !q) { return false; } // one is null (different structure)
        
        // values match
        if (p->val != q->val) { // check if they are not equal, so if they are not, it instantly returns
            return false;        // if they are equal, go on and traverse the rest to check 
        }

        return same_tree(p->left, q->left) && same_tree(p->right, q->right); //each call check the cuurent nodes children
    }
    
    bool is_subtree = false; 

    void dfs(TreeNode* root, TreeNode* subRoot) {
        if (!root) { return; }

        if (same_tree(root, subRoot)) { is_subtree = true; }

        dfs(root->left, subRoot);
        dfs(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root, subRoot);
        return is_subtree;
    }
};


/*

// function to check if two trees are the same

// run that function on each node in root

*/