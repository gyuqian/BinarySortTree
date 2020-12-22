/**************************************
* File Name:         LinkOperate.h
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* File:					对邻接表一系列操作的封装
***************************************/

#pragma once
#include "LinkHead.cpp"
#include "Link.cpp"
#include "TreeNode.cpp"
#include "BinaryTree.cpp"

const int MaxDataCount = 20;    //最大头节点数
class LinkOperation
{
public:
	LinkHead* DirectGraph;    //邻接表表头结点
	int* visited;    //访问标志位
	int* topo;    //拓扑输出标志

public:
	//
	///构造函数
	LinkOperation();
	//
	///创建邻接表
	void createDirectLink(BinaryTree, int*, int);
	//
	///深度优先遍历
	void DFS(int);
	//
	///拓扑输出
	void sortTop(int);
};

