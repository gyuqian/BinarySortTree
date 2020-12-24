/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					对一棵二叉树操作的封装
************************************************/

#pragma once
#include"TreeNode.h"

class BinaryTree
{
	//
	//公有数据
	//
public:
	TreeNode* TreeRootNode;    //二叉树根节点指针

	int high;    //存储树高
	int MaxData;    //节点最大值
	int DataCount;    //节点数
    int* rootdata;
	//
	//以下为测试使用变量，已弃用
	//
	//BinaryTree* Tree;
	//int numberNodeCount;    //根节点计数 没用到
	
	
	//
	//公有函数
	//
public:
	//
	//构造函数，初始化对象
	BinaryTree();
	//
	void GetMaxDataAndDataCount(int, int);
	//
	void GetMaxDataAndDataCountFromKeyboard();
	void GetMaxDataFromKeyBoard();
	void GetDataCountFromKeyBoard();
	//
	//获取随机数数列，同时生成二叉排序树
	void getRandRootData_creetTree();
	//
    //二叉排序树插入节点
	TreeNode* insertNode(TreeNode*, int);
	//
	//获取二叉排序树高
	void getTreeHigh(TreeNode*, int&);
    //获取对象中的二叉排序数高
	void getTreeHigh_TreeRootNode();
	//
	void outTreeLeaf(TreeNode*);
	void outTreeLeaf_TreeRootNode();
	//
	//中根（序）遍历
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