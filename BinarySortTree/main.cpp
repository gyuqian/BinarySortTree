#include "BinaryTree.cpp"
#include <iostream>

using namespace std;

int main(void)
{
    BinaryTree Tree1;
    BinaryTree Tree1_Clone;

    Tree1.GetMaxDataAndDataCount(16,85);
    //Tree1.GetMaxDataAndDataCountFromKeyboard();
    Tree1.getRandRootData_creetTree();
    Tree1.getTreeHigh_TreeRootNode();
    Tree1.outTreeLeaf_TreeRootNode();
    Tree1.inordeTree_TreeRootNode();

    int to_delete;
    cin >> to_delete;
    Tree1.DeleteTreeNode_TreeRootNode(to_delete);
    Tree1.inordeTree_TreeRootNode();
    //int to_find;
    //cin >> to_find;
    //Tree1.TreeFind_TreeNode(to_find);
    //

    //Tree1_Clone.TreeClonde_TreeNode1_V(Tree1.TreeNode1);
    //Tree1_Clone.inordeTree_TreeNode1();
    return 0;
}