/**************************************
* File Name:         SeqStack.cpp
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* File:					定义一个栈用于存储
*                          没有前驱的顶点，初始化
***************************************/
#include "SeqStack.h"
#include "iostream"

/**************************************
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* Func:					构造函数，用于初始化
*                          堆栈
***************************************/
inline SeqStack::SeqStack()
{
	data = NULL;
	top = -1;
}