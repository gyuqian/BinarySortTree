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

public:
	TreeNode();
	void changeRoot(int);
	int getRoot();
};

