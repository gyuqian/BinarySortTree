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
	int numberNodeCount;//���ڵ���� û�õ�
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
	void getRandRootData_creetTree();//��ȡdatacount�������
	//
	TreeNode* insertNode(TreeNode*, int);//������������ڵ�
	//
	void getTreeHigh(TreeNode*, int&);//��ȡ����
	void getTreeHigh_TreeNode1();//�Ա�ʡ�Դ��ݲ���
	//
	void outTreeLeaf(TreeNode*);
	void outTreeLeaf_TreeNode1();
	//
	void inordeTree(TreeNode*);//�и����򣩱���
	void inordeTree_TreeNode1();
	//
	TreeNode* TreeClone(TreeNode*);//δ���ʵ���
	void TreeClonde_TreeNode1_V(TreeNode*);
	//
	void TreeFind(TreeNode*, int);
	void TreeFind_TreeNode(int);
	//
	void DeleteTreeNode();
	void DeleteTreeNode_TreeNode1();
	//
	int getSomeRandNumberBetweenZeroAndMaxData();

};