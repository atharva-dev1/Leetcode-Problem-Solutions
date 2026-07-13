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
int count = 0 ;
    int countNodes(TreeNode* root) {       // Aprroach 1
        return countNode(root);
        return count;
    }
    // void Inorder(TreeNode * root){
    //     if (root == NULL)
    //     return;
    //         Inorder(root ->left);
    //         count++;
    //         Inorder(root -> right);
    //     }

    int countNode(TreeNode *root){     //approach 2 
        if(root == NULL)
        return 0;

        int left = countNode(root-> left);
        int right = countNode(root -> right);
        return 1 + left + right;
    }


};