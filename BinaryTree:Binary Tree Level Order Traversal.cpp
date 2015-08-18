class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root){
            return result;
        }
        
        queue<TreeNode*> queueTree;
        int len;
        
        queueTree.push(root);
        while(queueTree.empty() == false){
            
            vector<int> vi;
            len = queueTree.size();
            
            for(int i = 0;i < len; i++){
                TreeNode * cur = queueTree.front();
                vi.push_back(cur->val);
                if(cur->left){
                    queueTree.push(cur->left);
                }
                if(cur->right){
                    queueTree.push(cur->right);
                }
                queueTree.pop();
            }
            result.push_back(vi);
        }
        return result;
    }
};
