#pragma once

class TreeNode
{
	//
	//��������
	//
public:
	//
	//��
	int root;
	//��ڵ�
	TreeNode* left;
	//�ҽڵ�
	TreeNode* right;

public:
	TreeNode();
	void changeRoot(int);
	int getRoot();
};

