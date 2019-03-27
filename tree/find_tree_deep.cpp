输入一棵二叉树的根结点，求该树的深度。
     所谓的深度，指的就是从根结点到叶结点依次经过的结点(含根，叶结点)形成树的一条路径，最长路径的长度为树的深度。
     表面上好像需要遍历整棵树，以便知道那部分的结点最多，但实际上根本就不需要这样做。
     如果一棵树只有一个结点，它的深度为1，如果结点只有左子树而没有右子树，那么树的深度应该是其左子树的深度加1，
     同样如果结点只有右子树而没有左子树，那么树的深度应该是其右子树的深度加1.如果既有左子树又有右子树，那么该树
     的深度就是其左右子树深度的较大值加1。

int TreeDepth(BinaryTreeNode* pRoot)
{
    if(pRoot == NULL)
    {
          return 0;
    }

    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);

    return nLeft > nRight ? nLeft + 1 : nRight + 1;
}






template<typename T>  //模板 树中 放 T 类型变量 
struct TreeNode
{
	T _data;
	TreeNode<T>* left;//指向左孩子的指针
	TreeNode<T>* right;//指向右孩子指针
	TreeNode(const T& data = T()):_data(data), left(NULL), right(NULL){
	}
};

// typedef struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//     TreeNode(int x) :
//             val(x), left(NULL), right(NULL) {
//     }
// }TreeNode,*T;

public int deepth(TreeNode root){
        if(root==null)
            return 0;
        return Math.max(deepth(root.left),deepth(root.right))+1;
    }
    
    
