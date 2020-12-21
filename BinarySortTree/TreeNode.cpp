/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					����ڵ��������ľ���ʵ��
************************************************/


#pragma once
#include "TreeNode.h"
#include "iostream"


/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* Func:					���캯������ʼ������
************************************************/
inline TreeNode::TreeNode()
{
	left = NULL;    //��ʼ��������ָ��
	right = NULL;    //��ʼ��������ָ��
	root = -1;    //��ʼ����
}

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* Func:					�ı���ڵ�ֵ
* Input:					noderoot:���ڵ�Ҫ���ı��ֵ
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
* Func:					��ȡ���ڵ�ֵ
* Input:					NO INPUT
* Output:				root�����ظ��ڵ�ֵ
************************************************/
inline int TreeNode::getRoot()
{
	return root;
}