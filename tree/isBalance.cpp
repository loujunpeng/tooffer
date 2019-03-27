如果二叉树的每个节点的左子树和右子树的深度不大于1，它就是平衡二叉树。
先写一个求深度的函数，再对每一个节点判断，看该节点的左子树的深度和右子树的深度的差是否大于1。


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Balance {
public:
    int treedeepth(TreeNode* root){
        if(root==NULL) return 0;
        if(treedeepth(root->left)>treedeepth(root->right))
           return treedeepth(root->left)+1;
        else return treedeepth(root->right)+1;
       // //// return max(treedeepth(root->left),treedeepth(root->right))+1;
    }
    bool isBalance(TreeNode* root) {
        // write code here
        if(root==NULL) return true;
        if(abs(treedeepth(root->left)-treedeepth(root->right))>1)
            return false;
        else //再对每一个节点判断  因为存在 ||，两个链表公用一个根节点 的情况。。
            return isBalance(root->left)&isBalance(root->right);
    }
};
