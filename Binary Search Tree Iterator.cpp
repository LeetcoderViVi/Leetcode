class BSTIterator {
private:
    stack<TreeNode*> stackBST;
    TreeNode* cur;
public:
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur || !stackBST.empty(); 
    }

    /** @return the next smallest number */
    int next() {
        while(cur){
            stackBST.push(cur);
            cur = cur->left;
        }
        
        cur = stackBST.top();
        stackBST.pop();
        TreeNode* node = cur;
        cur = cur->right;
        
        return node->val;
    }
};
