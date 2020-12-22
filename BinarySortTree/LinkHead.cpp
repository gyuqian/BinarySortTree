/**************************************
* File Name:         LinkHead.cpp
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* File:					邻接表头节点，类的实现
***************************************/
#include "LinkHead.h"
#include "iostream"

using namespace std;

/**************************************
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* Func:					构造函数，用于初始化
*                          邻接表头节点
***************************************/
LinkHead::LinkHead()
{
	vexData = 0;    //初始化表头
	firarc = NULL;    //初始化表头链域
}