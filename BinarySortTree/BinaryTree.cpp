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
    TreeRootNode = NULL;
    high = 0;
}

inline int BinaryTree::getSomeRandNumberBetweenZeroAndMaxData()
{
    return rand() % MaxData;
}

inline void BinaryTree::getRandRootData_creetTree()
{
    int i;
    int randnumber;

    cout << "������У�" << endl;
    for (i = 0; i < DataCount; i++)
    {
        randnumber= getSomeRandNumberBetweenZeroAndMaxData();
        TreeNode* TreeNodeReturn;
        TreeNodeReturn = TreeFind(TreeRootNode, randnumber);
        while (TreeNodeReturn != NULL)
        {
            randnumber = getSomeRandNumberBetweenZeroAndMaxData();
            TreeNodeReturn = TreeFind(TreeRootNode, randnumber);
        }
        cout << randnumber << " ";
        TreeRootNode = insertNode(TreeRootNode, randnumber);
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
    /*cout << "Please input \"DataCount\"(0<DataCount<=20) and \"MaxData\"(50<=MaxData<=100)" << ":" << endl;
    cin >> DataCount >> MaxData;
    if (DataCount < 0 || DataCount>20 || MaxData < 50 || MaxData>100)
    {
        cout << "Error Input" << endl;
        GetMaxDataAndDataCountFromKeyboard();
    }*/
    GetDataCountFromKeyBoard();
    GetMaxDataFromKeyBoard();
}

inline void BinaryTree::GetDataCountFromKeyBoard()
{
    cout << "Please input \"DataCount\"(0<DataCount<=20)" << endl;
    
    cin >> DataCount;
    if (cin.fail()==1)
    {
        cout << "Error Input" << endl;
        cin.sync();
        cin.clear();
        cin.ignore();
        GetDataCountFromKeyBoard();
    }
    if (DataCount <0 || DataCount > 20)
    {
        cout << "Error Input" << endl;
        GetDataCountFromKeyBoard();
    }
}

inline void BinaryTree::GetMaxDataFromKeyBoard()
{
    cout << "Please input \"MaxData\"(50<=MaxData<=100)" << endl;
    cin >> MaxData;
    if (cin.fail() == 1)
    {
        cout << "Error Input" << endl;
        cin.sync();
        cin.clear();
        cin.ignore();
        GetMaxDataFromKeyBoard();
    }
    if (MaxData < 50 || MaxData>100)
    {
        cout << "Error Input" << endl;
        GetMaxDataFromKeyBoard();
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
    }     //����������
    else
    {
        TreeNodeinsert->right = insertNode(TreeNodeinsert->right, a);
    }     //����������
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
        getTreeHigh(Tree->left, lhigh);  //���������߶�
        getTreeHigh(Tree->right, rhigh);  //���������߶�
        if (lhigh >= rhigh)
            high = lhigh + 1;
        else
            high = rhigh + 1;
    }
}

inline void BinaryTree::getTreeHigh_TreeNode1()
{
    getTreeHigh(TreeRootNode, high);
    cout << "���ߣ�" << high << endl;
}

inline void BinaryTree::outTreeLeaf(TreeNode* Tree)
{
    if (Tree == NULL)
        return;
    else if (Tree->left == NULL && Tree->right == NULL)
        //������������ͬʱΪ�գ���ΪҶ��
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
    cout << "Ҷ�ӣ�" << endl;
    outTreeLeaf(TreeRootNode);
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
    TreeRootNode = TreeClone(rootNode);
}

inline TreeNode* BinaryTree::TreeFind(TreeNode* TreeNodefound, int to_find)
{
    if (TreeNodefound == NULL)
    {
        return TreeNodefound;
    }
    else
    {
        if (TreeNodefound->getRoot() == to_find)
        {
            return TreeNodefound;
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
    TreeNode* TreeNodereturn;
    TreeNodereturn = new TreeNode;
    TreeNodereturn=TreeFind(TreeRootNode, to_find);
    if (TreeNodereturn == NULL)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << "��ַ��" << TreeNodereturn << "ֵ��" << TreeNodereturn->getRoot() << endl;
    }
}

inline void BinaryTree::inordeTree_TreeNode1()
{
    cout << "������������" << endl;
    inordeTree(TreeRootNode);
    cout << endl;
}

inline void BinaryTree::DeleteTreeNode()
{

}
inline void BinaryTree::DeleteTreeNode_TreeNode1()
{

}