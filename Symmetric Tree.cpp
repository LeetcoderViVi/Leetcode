//Solution: Recursion!

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool checkChildrens(TreeNode* left,TreeNode* right)
    {
        if(left==NULL&&right==NULL)
            return true;
        if(left==NULL||right==NULL)
            return false;
        if(left->val == right->val)
            return checkChildrens(left->right,right->left)&&checkChildrens(left->left,right->right);
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return checkChildrens(root->left,root->right);
    }
};
