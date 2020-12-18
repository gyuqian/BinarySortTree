/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					声明二叉链表节点，
*							及对节点数据的操作
************************************************/
#pragma once

class TreeNode
{
	//
	//公有数据
	//
public:
	//
	//根
	int root;
	//左节点
	TreeNode* left;
	//右节点
	TreeNode* right;

	//
	//公有函数
	//
public:
	//
	//构造函数
	TreeNode();

	//改变节点数值
	void changeRoot(int);
	//获取节点数值
	int getRoot();
};

