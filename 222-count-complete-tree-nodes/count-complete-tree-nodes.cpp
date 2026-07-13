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
int h = 0 ;
    int countNodes(TreeNode* root) {       // Aprroach 1
        return countNode(root);
       // return count;
    }
    // void Inorder(TreeNode * root){
    //     if (root == NULL)
    //     return;
    //         Inorder(root ->left);
    //         count++;
    //         Inorder(root -> right);
    //     }

    // int countNode(TreeNode *root){          //approach 2 
    //     if(root == NULL)
    //     return 0;

    //     int left = countNode(root-> left);
    //     int right = countNode(root -> right);
    //     return 1 + left + right;
    // }


int countNode(TreeNode *root){          // approach 3
    if (root == NULL) return 0;
    int left_level = 1 , right_level = 1;
    TreeNode *l = root-> left;
    while(l){
        l = l-> left;
        left_level = left_level + 1;
    }
     TreeNode *r = root-> right;
    while(l){
        r = r-> right;
        right_level = right_level + 1;
    }
    if (left_level == right_level)
   return pow(2,right_level)-1;
   return 1 + countNode(root-> left)+  countNode(root-> right);
    
}

};