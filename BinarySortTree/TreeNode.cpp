/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					二叉节点类声明的具体实现
************************************************/


#pragma once
#include "TreeNode.h"
#include "iostream"


/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* Func:					构造函数，初始化对象
************************************************/
inline TreeNode::TreeNode()
{
	left = NULL;    //初始化左子树指针
	right = NULL;    //初始化右子树指针
	root = -1;    //初始化根
}

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* Func:					改变根节点值
* Input:					noderoot:根节点要被改变的值
* 
* Output:				NO OUTPUT
************************************************/
inline void TreeNode::changeRoot(int noderoot)
{
	root = noderoot;
}

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* Func:					获取根节点值
* Input:					NO INPUT
* Output:				root，返回根节点值
************************************************/
inline int TreeNode::getRoot()
{
	return root;
}