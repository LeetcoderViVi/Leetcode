
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

//non-traverse
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //valid
        vector<int> result;
        if(root == NULL){
            return result;
        }
        
        //non-traverse
        stack<TreeNode*> stackTree;
        stackTree.push(root);
        while(stackTree.empty() == false){
            TreeNode *cur = stackTree.top();
            stackTree.pop();
            result.push_back(cur->val);
            if(cur->right){
                stackTree.push(cur->right);
            }
            if(cur->left){
                stackTree.push(cur->left);
            }
        }
        
        return result;
    }
};
