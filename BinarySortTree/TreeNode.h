/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					������������ڵ㣬
*							���Խڵ����ݵĲ���
************************************************/
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

	//
	//���к���
	//
public:
	//
	//���캯��
	TreeNode();

	//�ı�ڵ���ֵ
	void changeRoot(int);
	//��ȡ�ڵ���ֵ
	int getRoot();
};

