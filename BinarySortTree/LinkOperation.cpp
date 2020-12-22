/**************************************
* File Name:         LinkOperate.cpp
* Auther:				gyuqian
* Data:					2020/12/22
* Last-modified:		2020/12/22
* File:					对邻接表一系列操作的封装
***************************************/
#include "LinkOperation.h"
#include "SeqStack.cpp"
#include "iostream"

using namespace std;


inline LinkOperation::LinkOperation()
{
	DirectGraph = NULL;

    topo = NULL;
    visited = new int[MaxDataCount];

    int i;
    for (i = 0; i < MaxDataCount; i++)
    {
        visited[i] = 0;
    }
}

inline void LinkOperation::createDirectLink(BinaryTree Tree, int* TreeRootNode,int size_array)
{
	DirectGraph = new LinkHead[size_array];

    //创建邻接表头节点
    int i;
    for (i=0 ; i < size_array; i++)
    {
        DirectGraph[i].vexData = TreeRootNode[i];
        DirectGraph[i].firarc = NULL;
    }

    Link* tempLink = NULL;
    for (int i = 0; i < size_array; i++)
    {
        TreeNode* searchReturn;
        searchReturn = Tree.TreeFind(Tree.TreeRootNode, TreeRootNode[i]);

        if (searchReturn->left != NULL)
        {
            tempLink = new Link;
            tempLink->data = searchReturn->left->root;

            int j;
            for (j = 0; j < size_array; j++)
            {
                if (TreeRootNode[j] == tempLink->data)
                    tempLink->adjvex = j;
            }
            tempLink->next = DirectGraph[i].firarc;//头插法建立链表
            DirectGraph[i].firarc = tempLink;
        }    //End if (searchReturn->left != NULL)
        if (searchReturn->right != NULL)
        {
            tempLink = new Link;
            tempLink->data = searchReturn->right->root;
            for (int j = 0; j < size_array; j++)
            {
                if (TreeRootNode[j] == tempLink->data)
                    tempLink->adjvex = j;
            }
            tempLink->next = DirectGraph[i].firarc;//头插法建立链表
            DirectGraph[i].firarc = tempLink;
        }    //End if (searchReturn->right != NULL)
    }    //End for (int i = 0; i < size_array; i++)
}

inline void LinkOperation::DFS(int i)
{
    //访问第i个顶点
    cout << DirectGraph[i].firarc->data;
    visited[i] = 1;
    Link* visittemp;
    visittemp = DirectGraph[i].firarc;
    while (visittemp)
    {
        int w = visittemp->adjvex;
        if (visited[w] == 0)
        {
            DFS(w);
        }
        visittemp = visittemp->next;//指向下一个边节点
    }
}

inline void LinkOperation::sortTop(int size_array)
{
    topo = new int[size_array];
    int i;
    int j;
    int k;
    int m;
    m = 0;

    Link* p=NULL;
    int* d = new int[size_array];
    SeqStack s;
    s.data = new int[MaxDataCount];
    s.top = -1;

    for (i = 0; i < size_array; i++)
    {
        d[i] = 0;
        topo[i] = -1;
    }
    //计算每个顶点的入度
    for (i = 0; i < size_array; i++)
    {
        p = DirectGraph[i].firarc;
        while (p != NULL)
        {
            j = p->adjvex;
            d[j]++;
            p = p->next;
        }
    }

    for (i = 0; i < size_array; i++)
    {//记录入度为0的顶点，将其入栈
        if (d[i] == 0)
        {
            s.top++;
            s.data[s.top] = i;
        }
    }

    while (s.top != -1)
    {
        int i = s.data[s.top];//出栈，并将该顶点引出的所有有向边删除，即将其邻接顶点的入度-1
        --s.top;
        topo[m] = i;
        m++;
        p = DirectGraph[i].firarc;
        while (p != NULL)
        {
            k = p->adjvex;
            --d[k];
            if (d[k] == 0)
            {
                s.top++;//入栈
                s.data[s.top] = k;
            }
            p = p->next;
        }
    }
    if (m < size_array)
        cout << "没有回路";
    for (i = 0; i < size_array; i++)
    {
        cout << DirectGraph[topo[i]].vexData<<" ";
    }
    delete[] d;
}