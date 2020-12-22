/**************************************
* File Name:         LinkOperate.h
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* File:					���ڽӱ�һϵ�в����ķ�װ
***************************************/

#pragma once
#include "LinkHead.cpp"
#include "Link.cpp"
#include "TreeNode.cpp"
#include "BinaryTree.cpp"

const int MaxDataCount = 20;    //���ͷ�ڵ���
class LinkOperation
{
public:
	LinkHead* DirectGraph;    //�ڽӱ��ͷ���
	int* visited;    //���ʱ�־λ
	int* topo;    //���������־

public:
	//
	///���캯��
	LinkOperation();
	//
	///�����ڽӱ�
	void createDirectLink(BinaryTree, int*, int);
	//
	///������ȱ���
	void DFS(int);
	//
	///�������
	void sortTop(int);
};

