#include"TreeNode.cpp"
class BinaryTree
{
	//
	//��������
	//
public:
	TreeNode* TreeRootNode;
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
	void GetMaxDataFromKeyBoard();
	void GetDataCountFromKeyBoard();
	//
	void getRandRootData_creetTree();//��ȡdatacount�������
	//
	TreeNode* insertNode(TreeNode*, int);//������������ڵ�
	//
	void getTreeHigh(TreeNode*, int&);//��ȡ����
	void getTreeHigh_TreeRootNode();//�Ա�ʡ�Դ��ݲ���
	//
	void outTreeLeaf(TreeNode*);
	void outTreeLeaf_TreeRootNode();
	//
	void inordeTree(TreeNode*);//�и����򣩱���
	void inordeTree_TreeRootNode();
	//
	TreeNode* TreeClone(TreeNode*);//δ���ʵ���
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