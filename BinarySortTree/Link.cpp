/**************************************
* File Name:         Link.cpp
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* File:					�ڽӱ�ڵ㣬��ʵ��
***************************************/

#pragma once
#include "Link.h"
#include <iostream>

/**************************************
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* Func:					���캯�������ڳ�ʼ��
*                          �ڽӱ�ڵ�
***************************************/
inline Link::Link()
{
	adjvex = 0;    //��ʼ���ڽ���
	data = 0;    //��ʼ��������
	next = NULL;    //��ʼ������
}