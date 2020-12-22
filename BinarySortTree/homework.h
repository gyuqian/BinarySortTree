/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					对一系列树操作的封装，
*							本文件不单独使用
************************************************/

#pragma once
#include "BinaryTree.h"
#include "LinkOperation.h"

class homework
{
	//
	//公有数据
	//
public:
	BinaryTree Tree;    //源树
	BinaryTree TreeClone;    //克隆源树
	LinkOperation LinkOpretion1;
	//
	//公有函数
	//
public:
	//homework();
	//操作一
	void homework1();
	//操作二
	void homework2();
	//
	void ChooseATree();
	//
	/*void GetAintNumFromKeyBoard(int &);*/
};