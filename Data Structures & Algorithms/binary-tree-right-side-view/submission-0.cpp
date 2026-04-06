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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) { return {}; }
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            vector<int> level_vec;
            for (int i = 0; i < level_size; ++i) {
                auto node = q.front();
                q.pop(); // pops front so you have to push right first

                level_vec.push_back({node->val});

                if (node->left) { q.push(node->left); } 
                if (node->right) { q.push(node->right); }
            }
            res.push_back(level_vec[level_vec.size() - 1]); // push last elemtn
        }
        return res;
    }
};

/*
[3,2]           [2,3]
[7,6,5,4]       [4,5,6,7]

bfs it

append q.back() to result vec (or push .front() if you push right first)



        1
       / 
      2
       \
        3
*/