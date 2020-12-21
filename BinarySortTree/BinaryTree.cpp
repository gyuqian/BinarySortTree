#include "BinaryTree.h"
#include "Link.cpp"
#include "iostream"

using namespace std;

inline BinaryTree::BinaryTree()
{
    numberNodeCount = 0;
    DataCount = 0;
    MaxData = 0;
    rootdata = NULL;
    TreeNode1 = NULL;
    high = 0;
}

inline int BinaryTree::getSomeRandNumberBetweenZeroAndMaxData()
{
    
    return rand() % MaxData;
}

inline void BinaryTree::getRandRootData_creetTree()
{
    int i,j;
   // int randnumber;
    int a[100];

    cout << "随机序列：" << endl;
    for (i = 0; i < DataCount; i++)
    {
        a[i]= getSomeRandNumberBetweenZeroAndMaxData();

        //randnumber= getSomeRandNumberBetweenZeroAndMaxData();
        for (j = 0; j < i; j++)
        {
            while(a[i]==a[j])
                a[i]= getSomeRandNumberBetweenZeroAndMaxData();

        }
        cout<<a[i]<<",";
       // cout << randnumber << ", ";
           TreeNode1 = insertNode(TreeNode1, a[i]);
    }
    cout << endl;
}

inline void BinaryTree::GetMaxDataAndDataCount(int data, int max)
{
    DataCount = data;
    MaxData = max;
}

inline void BinaryTree::GetMaxDataAndDataCountFromKeyboard()
{
    cout << "Please input \"DataCount\"(10<DataCount<=20)" <<endl;
    cin >> DataCount;
        cout<<"MaxData\"(50<=MaxData<=100)" << ":" << endl;
        cin>> MaxData;
    if (DataCount < 10 || DataCount>20 || MaxData < 50 || MaxData>100)
    {
        cout << "Error Input" << endl;
        GetMaxDataAndDataCountFromKeyboard();
    }
}

inline TreeNode* BinaryTree::insertNode(TreeNode* TreeNodeinsert, int a)
{
    if (TreeNodeinsert == NULL)
    {
        TreeNodeinsert = new TreeNode;
        TreeNodeinsert->changeRoot(a) ;
    }
    else  if (a < TreeNodeinsert->getRoot())
    {
        TreeNodeinsert->left = insertNode(TreeNodeinsert->left, a);
    }     //插入左子树
    else
    {
        TreeNodeinsert->right = insertNode(TreeNodeinsert->right, a);
    }     //插入右子树
    return TreeNodeinsert;
}

inline void BinaryTree::getTreeHigh(TreeNode* Tree, int& high)
{
    if (Tree == NULL)
    {
        high = 0;
        return;
    }
    else
    {
        int lhigh, rhigh;
        getTreeHigh(Tree->left, lhigh);  //求左子树高度
        getTreeHigh(Tree->right, rhigh);  //求右子树高度
        if (lhigh >= rhigh)
            high = lhigh + 1;
        else
            high = rhigh + 1;
    }
}

inline void BinaryTree::getTreeHigh_TreeNode1()
{
    getTreeHigh(TreeNode1, high);
    cout << "树高：" << high << endl;
}

inline void BinaryTree::outTreeLeaf(TreeNode* Tree)
{
    if (Tree == NULL)
        return;
    else if (Tree->left == NULL && Tree->right == NULL)
        //结点的左右子树同时为空，即为叶子
    {
        cout << Tree->root << " " << endl;
        return;
    }
    else
    {
        outTreeLeaf(Tree->left);
        outTreeLeaf(Tree->right);
    }
}

inline void BinaryTree::outTreeLeaf_TreeNode1()
{
    cout << "叶子：" << endl;
    outTreeLeaf(TreeNode1);
}

inline void	BinaryTree::inordeTree(TreeNode* Tree)
{
    if (Tree != NULL)
    {
        inordeTree(Tree->left);
        cout << Tree->getRoot() << "  ";
        inordeTree(Tree->right);
    }
}

inline TreeNode* BinaryTree::TreeClone(TreeNode* rootNode)
{
    if (rootNode == NULL) {
        return NULL;
    }
    TreeNode* new_node = NULL;
    new_node = new TreeNode;
    new_node->changeRoot(rootNode->root);
    new_node->left = TreeClone(rootNode->left);
    new_node->right = TreeClone(rootNode->right);

    return new_node;
}

inline void BinaryTree::TreeClonde_TreeNode1_V(TreeNode* rootNode)
{
    TreeNode1 = TreeClone(rootNode);
}

inline void BinaryTree::TreeFind(TreeNode* TreeNodefound, int to_find)
{
    if (TreeNodefound == NULL)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        if (TreeNodefound->getRoot() == to_find)
        {
            cout << "Found" << TreeNodefound << endl;
        }
        else if (TreeNodefound->getRoot() > to_find)
        {
            TreeFind(TreeNodefound->left, to_find);
        }
        else
        {
            TreeFind(TreeNodefound->right, to_find);
        }
    }
}

inline void BinaryTree::TreeFind_TreeNode(int to_find)
{
    TreeFind(TreeNode1, to_find);
}

inline void BinaryTree::inordeTree_TreeNode1()
{
    cout << "二叉排序树：" << endl;
    inordeTree(TreeNode1);
}

inline void BinaryTree::DeleteTreeNode()
{

}
inline void BinaryTree::DeleteTreeNode_TreeNode1()
{

}