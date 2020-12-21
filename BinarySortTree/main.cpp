#include "BinaryTree.cpp"
#include <iostream>

using namespace std;

int main(void)
{
    srand((unsigned)time(NULL));
    BinaryTree Tree1;
    BinaryTree Tree1_Clone;

   // Tree1.GetMaxDataAndDataCount(15,75);
    Tree1.GetMaxDataAndDataCountFromKeyboard();    //生成随机的随机数列
    Tree1.getRandRootData_creetTree();
    Tree1.getTreeHigh_TreeNode1();                 //求树高
    Tree1.outTreeLeaf_TreeNode1();                 //求叶子
    Tree1.inordeTree_TreeNode1();                  //输出二叉排序树
    //

   Tree1_Clone.TreeClonde_TreeNode1_V(Tree1.TreeNode1);
  //  Tree1_Clone.inordeTree_TreeNode1();
    return 0;
}