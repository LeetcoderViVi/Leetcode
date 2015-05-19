//Note: Don't forget the input maybe NULL
class Solution {
public:
	void add(int &sum,int num,TreeNode * node)
	{
		num = num*10 + node->val;
		if(node->left==NULL&&node->right==NULL)
			sum += num;
		if(node->left!=NULL)
			add(sum,num,node->left);
		if(node->right!=NULL)
			add(sum,num,node->right);
	}
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
          return 0;
        int sum=0,num=0;
		add(sum,num,root);
		return sum;
    }
};
