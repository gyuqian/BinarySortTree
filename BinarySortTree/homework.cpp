/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					对一系列树、邻接表操作的封装
************************************************/

#pragma once
#include "homework.h"
#include "getAn_int_input.h"
#include <iostream>

using namespace std;

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* Func:					封装操作一，实现：
*							1.从键盘读取两个数据，分别作为
*							最大节点数和节点最大值
*							2.生成最大节点数个随机数列，每个
*                          随机数的大小都位于0和最大值之间，
*                          同时将生成的随机数列输出，并将其
*                          存储到二叉排列数中
*                          3.获取生成的二叉树的高度并输出到
*                          屏幕
*                          4.输出生成随机数的叶子节点到屏幕
*                          5.输出二叉排序树
*Input:                  从键盘输入
*Output:               输出到屏幕
************************************************/
void homework::homework1()
{
    Tree.GetMaxDataAndDataCountFromKeyboard();
	Tree.getRandRootData_creetTree();
	Tree.getTreeHigh_TreeRootNode();
	Tree.outTreeLeaf_TreeRootNode();
	Tree.inordeTree_TreeRootNode();
}

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/22
* Func:					封装操作二，在封装操作一的基础上
*                          实现：
*							1.拷贝二叉树，生成二叉树副本
*							2.使用键盘输入数据，选择要查找的二
*                          叉树
*                          3.使用键盘输入想要查找的数，并输出
*                          查找结果
*                          4.使用键盘输入想要删除的数，并输出
*                          删除数据后的二叉排列
*                          5.基于源二叉树创建有向图邻接表
*                          6.输出5创建的邻接表的拓扑结构
* Input:                 从键盘输入：
*                          to_delete：要删除的数值
*Output:               输出到屏幕
* Functional Dependency:
*                          在该函数中调用如下函数：
*                          ChooseATree
************************************************/
void homework::homework2()
{
	//克隆源二叉树
	TreeClone.TreeClonde_paste(Tree.TreeRootNode);

	ChooseATree();

	//删除二叉树
	int to_delete;
	cout << "Please Input a Number to Delete, Press Enter to confirm!" << endl;
	cin >> to_delete;

	TreeClone.DeleteTreeNode_TreeRootNode(to_delete);
	TreeClone.inordeTree_TreeRootNode();
	//Tree.inordeTree_TreeRootNode();

	cout << "Creat Link..." << endl;
	LinkOperation1.createDirectLink(Tree, Tree.rootdata, Tree.DataCount);
	cout << "Adjacency Table" << endl;
	LinkOperation1.PrintDirectLink(Tree.DataCount);
	cout << "Topological Sort" << endl;
	LinkOperation1.sortTop(Tree.DataCount);
}

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/20
* Func:					1.使用键盘输入数据，选择要查找的二
*                          叉树
*                          2..使用键盘输入想要查找的数，并输出
*                          查找结果
* Input:                 从键盘输入：
*                          which_tree_to_find：选择要查找数的标志
*                          to_find：要查找的数值
*Output:               输出到屏幕
* Functional Dependency:
*                          该函数中调用了如下函数：
*                          GetAintNumFromKeyBoard
************************************************/
void homework::ChooseATree()
{
	//查找二叉树
	int which_tree_to_find;
	which_tree_to_find = 0;    //初始化查找标志位

	int to_find;
	cout << "Please Input a Number to Choose a Tree：" << endl
		<< "Enter 1 to Seach Source Binary Tree" << endl
		<< "Enter 2 to Seach The Copy Of Source Tree" << endl
		<< "Press Enter to confirm!" << endl;
    GetAintNumFromKeyBoard(which_tree_to_find);
	if (which_tree_to_find == 1)    //查找源二叉树
	{
		cout << "Please Input a Number to Find, Press Enter to confirm!" << endl;
		GetAintNumFromKeyBoard(to_find);
		Tree.TreeFind_TreeRootNode(to_find);
	}
	else if (which_tree_to_find == 2)    //查找二叉树副本
	{
		cout << "Please Input a Number to Find, Press Enter to confirm!" << endl;
		GetAintNumFromKeyBoard(to_find);
		TreeClone.TreeFind_TreeRootNode(to_find);
	}
	else
	{
		ChooseATree();
	}
}

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/20
* Last-modified:		2020/12/22
* Func:					从键盘输入一个整型数据
* Input:                 从键盘输入
*Output:                N/A
************************************************/
//void homework::GetAintNumFromKeyBoard(int &getNum)
//{
//	cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
//	cin >> getNum;
//
//	if (cin.fail() == 1)
//	{
//		cin.clear();
//		cout << "Please Input A Integer Number" << endl;
//		GetAintNumFromKeyBoard(getNum);
//	}
//}