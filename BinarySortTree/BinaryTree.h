#include"TreeNode.cpp"
class BinaryTree
{
	//
	//��������
	//
public:
	TreeNode* TreeNode1;
	//BinaryTree* Tree;
	int MaxData;
	int DataCount;
	int numberNodeCount;
	int* rootdata;
	int high;

public:
	//
	BinaryTree();
	//
	void GetMaxDataAndDataCount(int, int);
	//
	void GetMaxDataAndDataCountFromKeyboard();
	//
	void getRandRootData_creetTree();
	//
	TreeNode* insertNode(TreeNode*, int);
	//
	void getTreeHigh(TreeNode*, int&);
	void getTreeHigh_TreeNode1();
	//
	void outTreeLeaf(TreeNode*);
	void outTreeLeaf_TreeNode1();
	//
	void inordeTree(TreeNode*);
	void inordeTree_TreeNode1();
	//
	int getSomeRandNumberBetweenZeroAndMaxData();

};