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
	void getTreeHigh_TreeRootNode();//以便省略传递参数
	//
	void outTreeLeaf(TreeNode*);
	void outTreeLeaf_TreeRootNode();
	//
	void inordeTree(TreeNode*);//中根（序）遍历
	void inordeTree_TreeRootNode();
	//
	TreeNode* TreeClone(TreeNode*);//未完成实验二
	void TreeClonde_TreeRootNode_V(TreeNode*);
	//
	TreeNode* get_TreeFind_parnet(TreeNode*, TreeNode*);
	//
	TreeNode* TreeFind(TreeNode*, int);
	void TreeFind_TreeRootNode(int);
	//
	void DeleteTreeNode(TreeNode*, int);
	void DeleteTreeNode_TreeRootNode(int);
	//
	int getARandNumberBetweenZeroAndMaxData();

};