class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        return maxDepth(root) != -1;
    }
    
    int maxDepth(TreeNode *root){
        if(!root){
            return 0;
        }
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if(left == -1 || right == -1 || abs(right - left) > 1){
            return -1;
        }
        return max(left,right) + 1;
    }
};
