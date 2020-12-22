/**************************************
* File Name:         Link.h
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* File:					邻接表节点
***************************************/

#pragma once
class Link
{
	//
	///以下为公有数据，不受保护
	//
public:
	int adjvex;    //邻接域
	int data;    //数据域
	Link* next;    //链域

	//
	///以下为公有函数，不受保护
	//
public:
	//构造函数
	Link();   
};