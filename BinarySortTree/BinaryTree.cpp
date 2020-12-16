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
    int i;
    int randnumber;

    cout << "������У�" << endl;
    for (i = 0; i < DataCount; i++)
    {
        randnumber= getSomeRandNumberBetweenZeroAndMaxData();
        cout << randnumber << " ";
            TreeNode1 = insertNode(TreeNode1, randnumber);
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
    cout << "Please input \"Datacount\" and \"MaxData\"" << ":" << endl;
    cin >> DataCount >> MaxData;
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
    getTreeHigh(TreeNode1, high);
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

inline void BinaryTree::inordeTree_TreeNode1()
{
    cout << "������������" << endl;
    inordeTree(TreeNode1);
}