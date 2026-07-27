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
    void preorder(TreeNode* n, vector<int> &v) {
        if (n == NULL) {
            v.push_back(10000);
        } else {
            v.push_back(n->val);
            preorder(n->left, v);
            preorder(n->right, v);
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> vp, vq;
        preorder(p, vp);
        preorder(q, vq);
        return vp == vq;
    }
};