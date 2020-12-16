#include "BinaryTree.cpp"
#include <iostream>

using namespace std;

int main(void)
{
    BinaryTree Tree1;
    BinaryTree Tree1_Clone;

    //Tree.GetMaxDataAndDataCount(15,200);
    Tree1.GetMaxDataAndDataCountFromKeyboard();
    Tree1.getRandRootData_creetTree();
    Tree1.getTreeHigh_TreeNode1();
    Tree1.outTreeLeaf_TreeNode1();
    Tree1.inordeTree_TreeNode1();

    Tree1_Clone.TreeClonde_TreeNode1_V(Tree1.TreeNode1);
    Tree1_Clone.inordeTree_TreeNode1();
    return 0;
}