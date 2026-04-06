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

    int dfs(TreeNode * root, int val) {
        if (!root) { return 0; }

        // greatest num seen at this level/node so far
        int greatest = max(val, root->val);
        
        int left = dfs(root->left, greatest);
        int right = dfs(root->right, greatest);

        // check if its good (if root->val > greatest)
        if (root->val >= greatest) {
            return 1 + (left + right);
        }
        else {
            return left + right;
        }
    }

    int goodNodes(TreeNode* root) {
        if (!root) { return 0; }
        int val = root->val;
        return dfs(root, val);
    }
};

/*

the value at root is the greatest value seen at beggining of traversal. 
update greatest value accordingly as you traverse

            2
          /   \
         1     1       
        /      /\
       3      1  5


2   call 3
3   call left null
retrun 
3 call right null
return 

cur node is > greatest so far
    return 1 + max(0,0)

back at 1
call right null
return 0        left is 1 and right is 0
1 is not > greatet so far so doint count that level (no + 1)


*/