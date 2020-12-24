/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					��һϵ�������ڽӱ�����ķ�װ
************************************************/

#pragma once
#include "homework.h"
#include "getAn_int_input.h"
#include <iostream>

using namespace std;

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
void homework::homework1()
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
* Last-modified:		2020/12/22
* Func:					��װ���������ڷ�װ����һ�Ļ�����
*                          ʵ�֣�
*							1.���������������ɶ���������
*							2.ʹ�ü����������ݣ�ѡ��Ҫ���ҵĶ�
*                          ����
*                          3.ʹ�ü���������Ҫ���ҵ����������
*                          ���ҽ��
*                          4.ʹ�ü���������Ҫɾ�������������
*                          ɾ�����ݺ�Ķ�������
*                          5.����Դ��������������ͼ�ڽӱ�
*                          6.���5�������ڽӱ�����˽ṹ
* Input:                 �Ӽ������룺
*                          to_delete��Ҫɾ������ֵ
*Output:               �������Ļ
* Functional Dependency:
*                          �ڸú����е������º�����
*                          ChooseATree
************************************************/
void homework::homework2()
{
	//��¡Դ������
	TreeClone.TreeClonde_paste(Tree.TreeRootNode);

	ChooseATree();

	//ɾ��������
	int to_delete;
	cout << "Please Input a Number to Delete, Press Enter to confirm!" << endl;
	cin >> to_delete;

	TreeClone.DeleteTreeNode_TreeRootNode(to_delete);
	TreeClone.inordeTree_TreeRootNode();
	//Tree.inordeTree_TreeRootNode();

	cout << "Creat Link..." << endl;
	LinkOperation1.createDirectLink(Tree, Tree.rootdata, Tree.DataCount);
	cout << "Adjacency Table" << endl;
	LinkOperation1.PrintDirectLink(Tree.DataCount);
	cout << "Topological Sort" << endl;
	LinkOperation1.sortTop(Tree.DataCount);
}

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/20
* Func:					1.ʹ�ü����������ݣ�ѡ��Ҫ���ҵĶ�
*                          ����
*                          2..ʹ�ü���������Ҫ���ҵ����������
*                          ���ҽ��
* Input:                 �Ӽ������룺
*                          which_tree_to_find��ѡ��Ҫ�������ı�־
*                          to_find��Ҫ���ҵ���ֵ
*Output:               �������Ļ
* Functional Dependency:
*                          �ú����е��������º�����
*                          GetAintNumFromKeyBoard
************************************************/
void homework::ChooseATree()
{
	//���Ҷ�����
	int which_tree_to_find;
	which_tree_to_find = 0;    //��ʼ�����ұ�־λ

	int to_find;
	cout << "Please Input a Number to Choose a Tree��" << endl
		<< "Enter 1 to Seach Source Binary Tree" << endl
		<< "Enter 2 to Seach The Copy Of Source Tree" << endl
		<< "Press Enter to confirm!" << endl;
    GetAintNumFromKeyBoard(which_tree_to_find);
	if (which_tree_to_find == 1)    //����Դ������
	{
		cout << "Please Input a Number to Find, Press Enter to confirm!" << endl;
		GetAintNumFromKeyBoard(to_find);
		Tree.TreeFind_TreeRootNode(to_find);
	}
	else if (which_tree_to_find == 2)    //���Ҷ���������
	{
		cout << "Please Input a Number to Find, Press Enter to confirm!" << endl;
		GetAintNumFromKeyBoard(to_find);
		TreeClone.TreeFind_TreeRootNode(to_find);
	}
	else
	{
		ChooseATree();
	}
}

/***********************************************
* Auther:				gyuqian
* Data:					2020/12/20
* Last-modified:		2020/12/22
* Func:					�Ӽ�������һ����������
* Input:                 �Ӽ�������
*Output:                N/A
************************************************/
//void homework::GetAintNumFromKeyBoard(int &getNum)
//{
//	cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
//	cin >> getNum;
//
//	if (cin.fail() == 1)
//	{
//		cin.clear();
//		cout << "Please Input A Integer Number" << endl;
//		GetAintNumFromKeyBoard(getNum);
//	}
//}