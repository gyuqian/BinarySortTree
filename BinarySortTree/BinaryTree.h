/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					��һ�ö����������ķ�װ
************************************************/

#pragma once
#include"TreeNode.h"

class BinaryTree
{
	//
	//��������
	//
public:
	TreeNode* TreeRootNode;    //���������ڵ�ָ��

	int high;    //�洢����
	int MaxData;    //�ڵ����ֵ
	int DataCount;    //�ڵ���
    int* rootdata;
	//
	//����Ϊ����ʹ�ñ�����������
	//
	//BinaryTree* Tree;
	//int numberNodeCount;    //���ڵ���� û�õ�
	
	
	//
	//���к���
	//
public:
	//
	//���캯������ʼ������
	BinaryTree();
	//
	void GetMaxDataAndDataCount(int, int);
	//
	void GetMaxDataAndDataCountFromKeyboard();
	void GetMaxDataFromKeyBoard();
	void GetDataCountFromKeyBoard();
	//
	//��ȡ��������У�ͬʱ���ɶ���������
	void getRandRootData_creetTree();
	//
    //��������������ڵ�
	TreeNode* insertNode(TreeNode*, int);
	//
	//��ȡ������������
	void getTreeHigh(TreeNode*, int&);
    //��ȡ�����еĶ�����������
	void getTreeHigh_TreeRootNode();
	//
	void outTreeLeaf(TreeNode*);
	void outTreeLeaf_TreeRootNode();
	//
	//�и����򣩱���
	void inordeTree(TreeNode*);
	void inordeTree_TreeRootNode();
	//
	TreeNode* TreeClone(TreeNode*);
	void TreeClonde_paste(TreeNode*);
	//
	TreeNode* get_TreeNode_parnet(TreeNode*, TreeNode*);
	//
	TreeNode* TreeFind(TreeNode*, int);
	void TreeFind_TreeRootNode(int);
	//
	void DeleteTreeNode(TreeNode*, int);
	void DeleteTreeNode_TreeRootNode(int);
	//
	int getARandNumberBetweenZeroAndMaxData();
};