#include"TreeNode.cpp"
class BinaryTree
{
	//
	//公有数据
	//
public:
	TreeNode* TreeRootNode;
	//BinaryTree* Tree;
	int MaxData;
	int DataCount;
	int numberNodeCount;//根节点计数 没用到
	int* rootdata;
	int high;

public:
	//
	BinaryTree();
	//
	void GetMaxDataAndDataCount(int, int);
	//
	void GetMaxDataAndDataCountFromKeyboard();
	void GetMaxDataFromKeyBoard();
	void GetDataCountFromKeyBoard();
	//
	void getRandRootData_creetTree();//获取datacount个随机数
	//
	TreeNode* insertNode(TreeNode*, int);//创建函数插入节点
	//
	void getTreeHigh(TreeNode*, int&);//获取树高
	void getTreeHigh_TreeNode1();//以便省略传递参数
	//
	void outTreeLeaf(TreeNode*);
	void outTreeLeaf_TreeNode1();
	//
	void inordeTree(TreeNode*);//中根（序）遍历
	void inordeTree_TreeNode1();
	//
	TreeNode* TreeClone(TreeNode*);//未完成实验二
	void TreeClonde_TreeNode1_V(TreeNode*);
	//
	TreeNode* TreeFind(TreeNode*, int);
	void TreeFind_TreeNode(int);
	//
	void DeleteTreeNode();
	void DeleteTreeNode_TreeNode1();
	//
	int getSomeRandNumberBetweenZeroAndMaxData();

};