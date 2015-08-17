
//Traverse
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> prePath;
        traverse(root,prePath);
        return prePath;
    }
    void traverse(TreeNode* root,vector<int> &prePath){
        if(root == NULL){
            return;
        }
        
        prePath.push_back(root->val);
        traverse(root->left,prePath);
        traverse(root->right,prePath);
    }
};

//
