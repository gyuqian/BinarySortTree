/**************************************
* File Name:         LinkHead.h
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* File:					邻接表头节点
***************************************/
#pragma once
#include "Link.cpp"
class LinkHead
{
	//
	///
public:
	int vexData;    //表头数据
	Link* firarc;    //表头链域

public:
	//
	///构造函数
	LinkHead();
};

