链接：https://www.nowcoder.com/questionTerminal/536c0199151245f897da2c5390930657
来源：牛客网

<方法1>

      首先我们想到的是二叉树中序遍历后的结果是有序的，根据这个结果，我们可以中序遍历二叉树，并把遍历结果存放在一个数组里面，然后判断这个数组大小是否是有序数组，如果是有序数组，则是二叉查找树，否则就不是。

       这个方法的时间复杂度是O(N)，但是空间复杂度比较高，需要浪费O（N）的存储空间。

<方法2>

      其实在<方法1>的基础上，我们可以在中序遍历的同时，比较大小，每次记录下上次遍历过的元素的值，如果当前元素的值大于上次遍历元素的值，则接着遍历，否则返回false，因为这个记录是一个址传递，所以需要用到引用形参进行传递。

     这个方法的时间复杂度与<方法1>的时间复杂度相同，只是空间复杂度只需要一个元素O(1)。
     
 
class Checker {
public:
    bool checkBST(TreeNode* root) {
        // write code here
        int min=INT_MIN;
        return method1(root,min);
    }
    bool method1(TreeNode* root,int &last)
    {
        if(root==NULL)
            return true;
        if(!method1(root->left,last))
            return false;
        if(root->val<last)
            return false;
        last=root->val;
        if(!method1(root->right,last))
            return false;
        return true;
    }
};
链接：https://www.nowcoder.com/questionTerminal/536c0199151245f897da2c5390930657
来源：牛客网

<方法3>

      可以根据二叉查找树的定义来判断，二叉树的定义，所有左子树的节点小于根节点，
      所有右子树的节点大于根节点，并且左右子树也是二叉查找树。所以在递归的过程中，
      我们只需要传递两个参数（当前根节点对应的二叉树的所有节点的最大值和最小值），
      同时不断的更新这两个参数，如果当前节点的值不在这两个数范围中，则直接返回false，否则接着递归便可。
      链接：https://www.nowcoder.com/questionTerminal/536c0199151245f897da2c5390930657
来源：牛客网

class Checker {
public:
    bool checkBST(TreeNode* root) {
        // write code here
        return method2(root,INT_MIN,INT_MAX);
    }
    bool method2(TreeNode* root,int min,int max)
    {
        if(root==NULL)
            return true;
        if(root->val<min||root->val>max)
            return false;
        return method2(root->left,min,root->val)&&method2(root->right,root->val,max);
 
    }
};
      
      
