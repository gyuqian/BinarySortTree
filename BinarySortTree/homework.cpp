/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					��һϵ���������ķ�װ
************************************************/

#pragma once
#include "homework.h"
#include <iostream>

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* Func:					��װ����һ��ʵ�֣�
*							1.�Ӽ��̶�ȡ�������ݣ��ֱ���Ϊ
*							���ڵ����ͽڵ����ֵ
*							2.�������ڵ�����������У�ÿ��
*                          ������Ĵ�С��λ��0�����ֵ֮�䣬
*                          ͬʱ�����ɵ�������������������
*                          �洢��������������
*                          3.��ȡ���ɵĶ������ĸ߶Ȳ������
*                          ��Ļ
*                          4.��������������Ҷ�ӽڵ㵽��Ļ
*                          5.�������������
*Input:                  �Ӽ�������
*Output:               �������Ļ
************************************************/
inline void homework::homework1()
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
* Last-modified:		2020/12/18
* Func:					��װ���������ڷ�װ����һ�Ļ�����
*                          ʵ�֣�
*							1.���������������ɶ���������
*							2.ʹ�ü����������ݣ�ѡ��Ҫ���ҵĶ�
*                          ����
*                          3.ʹ�ü���������Ҫ���ҵ����������
*                          ���ҽ��
*                          4.ʹ�ü���������Ҫɾ�������������
*                          ɾ�����ݺ�Ķ�������
* Input:                 �Ӽ������룺
*                          which_tree_to_find��ѡ��Ҫ�������ı�־
*                          to_find��Ҫ���ҵ���ֵ
*                          to_delete��Ҫɾ������ֵ
*Output:               �������Ļ
************************************************/
inline void homework::homework2()
{
	//��¡Դ������
	TreeClone.TreeClonde_paste(Tree.TreeRootNode);

	//���Ҷ�����
	int which_tree_to_find;
	which_tree_to_find = 0;    //��ʼ�����ұ�־λ

	int to_find;
	cout << "Please Input a Number to Choose a Tree��" << endl
		<< "Enter 1 to Seach Source Binary Tree" << endl
		<< "Enter 2 to Seach The Copy Of Source Tree" << endl
		<< "Press Enter to confirm!" << endl;
	cin >> which_tree_to_find;
	if (which_tree_to_find == 1)    //����Դ������
	{
		cout << "Please Input a Number to Find, Press Enter to confirm!" << endl;
	    cin >> to_find;
		Tree.TreeFind_TreeRootNode(to_find);
	}
	else if (which_tree_to_find == 2)    //���Ҷ���������
	{
		cout << "Please Input a Number to Find, Press Enter to confirm!" << endl;
		cin >> to_find;
		TreeClone.TreeFind_TreeRootNode(to_find);
	}

	//ɾ��������
	int to_delete;
	cout << "Please Input a Number to Delete, Press Enter to confirm!" << endl;
	cin >> to_delete;

	TreeClone.DeleteTreeNode_TreeRootNode(to_delete);
	TreeClone.inordeTree_TreeRootNode();
}