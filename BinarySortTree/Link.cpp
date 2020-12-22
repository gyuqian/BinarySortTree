/**************************************
* File Name:         Link.cpp
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* File:					邻接表节点，类实现
***************************************/

#pragma once
#include "Link.h"
#include <iostream>

/**************************************
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* Func:					构造函数，用于初始化
*                          邻接表节点
***************************************/
inline Link::Link()
{
	adjvex = 0;    //初始化邻接域
	data = 0;    //初始化数据域
	next = NULL;    //初始化链域
}