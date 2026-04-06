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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) { return {}; }

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int level_size = q.size();
            vector<int> level_vec;

            for (int i = 0; i < level_size; ++i) {
                auto node = q.front();
                q.pop();
                
                level_vec.push_back(node->val);

                if (node->left) { q.push(node->left); }
                if (node->right) { q.push(node->right); }
            }
            res.push_back(level_vec);
        }
        return res;
    }
};

/*

bfs for level order

make a list to append to result

[1]

[3,2]

*/