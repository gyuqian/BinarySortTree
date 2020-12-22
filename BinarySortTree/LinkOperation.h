#pragma once
#include "LinkHead.cpp"
#include "Link.cpp"
#include "TreeNode.cpp"
#include "BinaryTree.cpp"

const int MaxDataCount = 20;
class LinkOperation
{
public:
	LinkHead* DirectGraph;
	int* visited;
	int* topo;

public:
	LinkOperation();
	//
	void createDirectLink(BinaryTree, int*, int);
	//
	void DFS(int);
	//
	void sortTop(int);
};

