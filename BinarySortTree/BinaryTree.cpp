/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					��һ�ö����������ķ�װ
*                          ����ʵ��
************************************************/
#pragma once
#include "BinaryTree.h"
#include "iostream"

using namespace std;

/******************************************************
 * Author : gyuqian
 * Date   : 2020/12/16
 * Func   : ���캯������ʼ�����������б����ĳ�ʼֵ
 ******************************************************/
inline BinaryTree::BinaryTree()
{
    DataCount = 0;
    MaxData = 0;
    TreeRootNode = NULL;
    high = 0;
    rootdata = NULL;
    //numberNodeCount = 0;
}

/******************************************************
 * Author   : gyuqian
 * Date      : 2020/12/16
 * Func      : ����һ�����������ֵ��ΧΪ 0~MaxData
 * Input      : Nothing
 * Output    : ����һ�������
 ******************************************************/
inline int BinaryTree::getARandNumberBetweenZeroAndMaxData()
{
    return rand() % MaxData;    //�������������ֵ��Χ0~MaxData
}

/******************************************************
* Author    :gyuqian
* Data       :2020/12/16
* Func       :����������в������
                  ͬʱʹ��������д�������������
* input       :NO INPUT
* output     :NO OUTPUT
*******************************************************/
inline void BinaryTree::getRandRootData_creetTree()
{
    int i;    //����ֲ�ѭ������
    //int* temp_rootdata;    //����������е��ݴ�
    rootdata = new int[DataCount];

    int randnumber;   //������������

    cout << "Random Sequence:" << endl;    //�����ʾ

    //
    //ѭ�����̣�����DataCount��������У�ͬʱ��������������
    //
    for (i = 0; i < DataCount; i++)
    {
        randnumber= getARandNumberBetweenZeroAndMaxData();   //���������
        TreeNode* TreeNodeReturn;    //����ֲ����������ڴ洢������ڶ����������еĲ��ҽ��
        TreeNodeReturn = TreeFind(TreeRootNode, randnumber);    //��ѯ���ɵ�������Ƿ��ڶ�������
        //
        //���ɲ��ظ��������
        while (TreeNodeReturn != NULL)
        {
            randnumber = getARandNumberBetweenZeroAndMaxData();
            TreeNodeReturn = TreeFind(TreeRootNode, randnumber);
        }
        delete TreeNodeReturn;    //�ͷžֲ��������ڴ�

        //��������������
        cout << randnumber << " ";
        //�����ɵ�������д洢
        *(rootdata + i) = randnumber;
        //�����ɵ�������������������
        TreeRootNode = insertNode(TreeRootNode, randnumber);
    }
    cout << endl;
}

/******************************************************
* Author    :gyuqian
* Data       :2020/12/16
* Func       :�����ڱ�����ֵ
* input       :data ���ڸ�ֵDataCount
*               :max ���ڸ�ֵMaxData
* output     :NO OUTPUT
*******************************************************/
inline void BinaryTree::GetMaxDataAndDataCount(int data, int max)
{
    DataCount = data;    //��ֵDataCount
    MaxData = max;    //��ֵMaxData
}

/******************************************************
* Author    :gyuqian
* Data       :2020/12/16
* Func       :�Ӽ��̶�ȡ���ݣ��Ա�����ֵ
* input       :From Keyboard
* output     :NO OUTPUT
*******************************************************/
inline void BinaryTree::GetMaxDataAndDataCountFromKeyboard()
{
    GetDataCountFromKeyBoard();    //��ȡ����������е����ݸ���
    GetMaxDataFromKeyBoard();    //��ȡ��������������ݵ����ֵ

    ///
    //����Ϊ����ʹ�ã�������
    //
    /*cout << "Please input \"DataCount\"(0<DataCount<=20) and \"MaxData\"(50<=MaxData<=100)" << ":" << endl;
    cin >> DataCount >> MaxData;
    if (DataCount < 0 || DataCount>20 || MaxData < 50 || MaxData>100)
    {
        cout << "Error Input" << endl;
        GetMaxDataAndDataCountFromKeyboard();
    }*/
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     �Ӽ��̶�ȡ���ݣ��Ա�����ֵ
* Input:                     From Keyboard
* Output:                   �����ʾ
*******************************************************/
inline void BinaryTree::GetDataCountFromKeyBoard()
{
    cout << "Please input \"DataCount\"(0<DataCount<=20)" << endl;
    
    cin >> DataCount;

    //����������ݽ����жϣ����������Ҫ������������
    if (cin.fail()==1)    //�������룬��־λ�Զ���1
    {
        cout << "Error Input" << endl;
        //cin.sync();    
        cin.clear();    //���ñ�־λ
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');    //������뻺����

        GetDataCountFromKeyBoard();
    }
    if (DataCount <0 || DataCount > 20)    //���������ݵĴ�С�����жϣ����������Ҫ������������
    {
        cout << "Error Input" << endl;

        GetDataCountFromKeyBoard();
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     �Ӽ��̶�ȡ���ݣ��Ա�����ֵ
* Input:                     From Keyboard
* Output:                   �����ʾ
*******************************************************/
inline void BinaryTree::GetMaxDataFromKeyBoard()
{
    cout << "Please input \"MaxData\"(50<=MaxData<=100)" << endl;
    cin >> MaxData;

    //����������ݽ����жϣ����������Ҫ������������
    if (cin.fail() == 1)//�������룬��־λ�Զ���1
    {
        cout << "Error Input" << endl;
        //cin.sync();
        cin.clear();    //���ñ�־λ
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');    //������뻺����

        GetMaxDataFromKeyBoard();
    }
    if (MaxData < 50 || MaxData>100)    //���������ݵĴ�С�����жϣ����������Ҫ������������
    {
        cout << "Error Input" << endl;

        GetMaxDataFromKeyBoard();
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     ��������в����½ڵ�
* Input:                     a��Ҫ���������
*                              TreeNodeinsert����Ҫ�����Ķ�����
* Output:                   ������ɵĶ�����
*******************************************************/
inline TreeNode* BinaryTree::insertNode(TreeNode* TreeNodeinsert, int a)
{
    if (TreeNodeinsert == NULL)    //������Ϊ��
    {
        TreeNodeinsert = new TreeNode;
        TreeNodeinsert->changeRoot(a) ;
    }
    else  if (a < TreeNodeinsert->getRoot())    //����������
    {
        TreeNodeinsert->left = insertNode(TreeNodeinsert->left, a);
    } 
    else    //����������
    {
        TreeNodeinsert->right = insertNode(TreeNodeinsert->right, a);
    } 
    return TreeNodeinsert;

    delete TreeNodeinsert;    //�ͷžֲ��������ڴ�
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     ��ȡ������������
* Input:                     TreeNodeinsert����Ҫ�����Ķ�����
* Output:                   high������
*******************************************************/
inline void BinaryTree::getTreeHigh(TreeNode* Tree, int& high)
{
    if (Tree == NULL)    //����
    {
        high = 0;
        return;
    }
    else
    {
        int lhigh;  //������
        int rhigh;   //������

        getTreeHigh(Tree->left, lhigh);  //���������߶�
        getTreeHigh(Tree->right, rhigh);  //���������߶�
        if (lhigh >= rhigh)
        {
            high = lhigh + 1;
        }
        else
        {
            high = rhigh + 1;
        }   
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     ��ȡ�����ж�����������
* Input:                     �����еĶ�����
* Output:                   ����Ļ�����
*                               high������
*******************************************************/
inline void BinaryTree::getTreeHigh_TreeRootNode()
{
    getTreeHigh(TreeRootNode, high);

    cout << "High��" << endl << high << endl;
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     �����������Ҷ�ӽڵ�
* Input:                     Tree����Ҫ�����Ķ�����
* Output:                   ����Ļ�����
*                               ÿһ��Ҷ�ӽڵ�
*******************************************************/
inline void BinaryTree::outTreeLeaf(TreeNode* Tree)
{
    if (Tree == NULL)    //����
    {
        return;
    }
    else if (Tree->left == NULL && Tree->right == NULL)    //������������ͬʱΪ�գ���ΪҶ��
    {
        cout << Tree->root << " ";
        return;
    }
    else
    {
        outTreeLeaf(Tree->left);    //�����������Ҷ�ӽڵ�
        outTreeLeaf(Tree->right);   //�����������Ҷ�ӽڵ�
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     ��������ж�������Ҷ�ӽڵ�
* Input:                     NO INPUT
*                               ���������еĶ�����
* Output:                   ����Ļ�����
*                               ÿһ��Ҷ�ӽڵ�
*******************************************************/
inline void BinaryTree::outTreeLeaf_TreeRootNode()
{
    cout << "Leaf��" << endl;
    outTreeLeaf(TreeRootNode);
    cout << endl;
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     ���������������������
* Input:                     Tree����Ҫ�����Ķ�����
* Output:                   ����Ļ�����
*                               ����������
*******************************************************/
inline void	BinaryTree::inordeTree(TreeNode* Tree)
{
    if (Tree != NULL)
    {
        inordeTree(Tree->left);    //����������
        cout << Tree->getRoot() << " ";    //����ڵ�ֵ
        inordeTree(Tree->right);    //����������
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     ��������ж�����������������
* Input:                     NO INPUT
*                               ���������еĶ�����
* Output:                   ����Ļ�����
*                               ����������
*******************************************************/
inline void BinaryTree::inordeTree_TreeRootNode()
{
    if (TreeRootNode != NULL)
    {
        cout << "BinarySortTree��" << endl;
        inordeTree(TreeRootNode);
        cout << endl;
    }
    else
    {
        cout << "This Tree Does Not Have A Node!";
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     ��ȸ��ƶ�����
* Input:                     rootNode Ҫ���Ƶ�Դ������
* Output:                   ����������
*******************************************************/
inline TreeNode* BinaryTree::TreeClone(TreeNode* rootNode)
{
    if (rootNode == NULL) //����
    {
        return NULL;
    }
    TreeNode* new_node = NULL;
    new_node = new TreeNode;

    new_node->changeRoot(rootNode->root);
    new_node->left = TreeClone(rootNode->left);    //����������
    new_node->right = TreeClone(rootNode->right);    //����������

    return new_node;
    delete new_node;
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     �ÿ����ķ�ʽ���������еĶ�����
* Input:                     rootNode Ҫ���Ƶ�Դ������
* Output:                   �����еĶ�����
*******************************************************/
inline void BinaryTree::TreeClonde_paste(TreeNode* rootNode)
{
    TreeRootNode = TreeClone(rootNode);
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     ��ȡָ���ڵ�ĸ��ڵ�
* Input:                     TreeNode_to_getParent Ҫ���Ҹ��ڵ�Ľڵ�
*                              TreeNodefound Ҫ���ҵ���
* Output:                   �ҵ��ĸ��ڵ�
*******************************************************/
inline TreeNode* BinaryTree::get_TreeNode_parnet(TreeNode* TreeNodefound, TreeNode* TreeNode_to_getParent)
{
    TreeNode* TreeNodefound_left = NULL;
    //TreeNodefound_left = new TreeNode;
    
    TreeNode* TreeNodefound_right = NULL;
    //TreeNodefound_right = new TreeNode;

    if (TreeNodefound == NULL    //����
        || TreeNodefound->left == TreeNode_to_getParent 
        || TreeNodefound->right == TreeNode_to_getParent)    //���ڵ����Ҫ���ҵĸ��ڵ�
    {
        return TreeNodefound;
    }

    //�������Ƿ�Ϊ���ڵ�
    TreeNodefound_left = get_TreeNode_parnet(TreeNodefound->left, TreeNode_to_getParent); 
    if (TreeNodefound_left != NULL)
    {
        
        return TreeNodefound_left;
        delete TreeNodefound_left;
        delete TreeNodefound_right;
    }//�ǵĻ���return��������������

    //�������Ƿ�Ϊ���ڵ�
    TreeNodefound_right = get_TreeNode_parnet(TreeNodefound_right, TreeNode_to_getParent); 
    if (TreeNodefound_right != NULL)
    {
        
        return TreeNodefound_right;
        delete TreeNodefound_left;
        delete TreeNodefound_right;
    }//�ǵĻ���return

    delete TreeNodefound_left;
    delete TreeNodefound_right;
    return NULL; //��������δ�ҵ�������NULL
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     �ڶ�������Ѱ�ҽڵ�
* Input:                     to_find Ҫ���ҽڵ�
*                              TreeNodefound Ҫ���ҵ���
* Output:                   Ѱ�ҵĽ��
*******************************************************/
inline TreeNode* BinaryTree::TreeFind(TreeNode* TreeNodefound, int to_find)
{
    if (TreeNodefound == NULL)    //����
    {
        return TreeNodefound;
    }
    else
    {
        if (TreeNodefound->root == to_find)    //���ڵ����Ҫ���ҵĽڵ�
        {
            return TreeNodefound;
        }
        else if (TreeNodefound->root > to_find)    //����������
        {
            return TreeFind(TreeNodefound->left, to_find);
        }
        else    //����������
        {
            return TreeFind(TreeNodefound->right, to_find);
        }
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/22
* Func:                     �ڶ����������Ѱ�ҽڵ�
* Input:                     to_find Ҫ���ҽڵ�
* Output:                   Ѱ�ҵĽ��
*******************************************************/
inline void BinaryTree::TreeFind_TreeRootNode(int to_find)
{
    TreeNode* TreeNodereturn;
    TreeNodereturn = TreeRootNode;
    //TreeNodereturn = new TreeNode;
    TreeNodereturn=TreeFind(TreeNodereturn, to_find);

    if (TreeNodereturn == NULL)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        //����ҵ��ĸ��ڵ�ĵ�ַ
        cout << "Found " << "Address��" << TreeNodereturn << "value��" << TreeNodereturn->getRoot() << endl;
    }

    //delete TreeNodereturn;
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/20
* Func:                     ɾ���������еĽڵ�
* Input:                     to_delete Ҫ���ҽڵ�
*                              TreeNodeCopyTemp��Ҫɾ����������
*                              ��ʱ����
* Output:                   NO OUTPUT
*******************************************************/
inline void BinaryTree::DeleteTreeNode(TreeNode* TreeNodeCopyTemp, int to_delete)
{
    TreeNode* L = NULL;
    TreeNode* LL = NULL;

    TreeNode* tempNode=NULL;    //Ҫɾ���Ľڵ�
    tempNode = TreeNodeCopyTemp;

    TreeNode* tempNode_Parent;    //Ҫɾ���ڵ�ĸ��ڵ�
    tempNode_Parent = TreeNodeCopyTemp;

    int child;
    child = 0;    //�ӽڵ��־λ��0Ϊ���ӣ�1Ϊ�Һ���

    if (TreeNodeCopyTemp == NULL)    //����
    {
        return;
    }

    while (tempNode != NULL)
    {
        if (tempNode->getRoot() == to_delete)    //ɾ���ڵ�
        {
            if (tempNode->left == NULL && tempNode->right == NULL)    //Ҫɾ���Ľڵ���Ҷ�ӽڵ�
            {
                if (tempNode == TreeNodeCopyTemp)    //Ҫɾ�����Ǹ��ڵ�,������Ϊ1
                {
                    delete tempNode;
                }
                else if (child == 0)    //Ҫɾ���ڵ����丸�ڵ������
                {
                    tempNode_Parent->left = NULL;
                    delete tempNode;
                }
                else    //Ҫɾ���ڵ����丸�ڵ���Һ���
                {
                    tempNode_Parent->right = NULL;
                    delete tempNode;
                }
            }    //End if (tempNode->left == NULL && tempNode->right == NULL)    //Ҫɾ���Ľڵ���Ҷ�ӽڵ�

            else if (tempNode->right == NULL)    //Ҫɾ���ڵ�ֻ������
            {
                if (child == 0)    //Ҫɾ���ڵ����丸�ڵ������
                {
                    tempNode_Parent->left = tempNode->left;
                }
                else    //Ҫɾ���ڵ����丸�ڵ���Һ���
                {
                    tempNode_Parent->right = tempNode->left;
                }

                delete tempNode;
            }    //End else if (tempNode->right == NULL)    //Ҫɾ���ڵ�ֻ������

            else    //Ҫɾ���Ľڵ������Һ��ӣ�����������С�Ľڵ����˽ڵ�
            {
                LL = tempNode;
                L = tempNode->right;    //�Һ��� / ������

                while (L->left != NULL)    //Ѱ���������е���Сֵ
                {
                    LL = L;
                    L = L->left;
                }
                tempNode->changeRoot(L->getRoot());

                if (LL == tempNode)    //�Һ��ӵ�������Ϊ��
                {
                    LL->right = L->right;
                }
                else
                {
                LL->left = L->right;
                }

                delete L;
                /*
                if (L->left!=NULL)    //�Һ��ӵ���������Ϊ��
                {
                    LL = L; 
                    L = L->left;
                    tempNode->changeRoot(L->getRoot()); //��
                    LL->left = L->left;

                    while ( L->left != NULL)
                    {
                        L->left = tempNode->left;
                        L = L->left;
                    }
                    tempNode->left = NULL;
                }
                else    //�Һ��ӵ�������Ϊ��
                {
                    tempNode->changeRoot(L->getRoot());
                    LL->right = L->right;
                }*/

            }    //End else    //Ҫɾ���Ľڵ������Һ��ӣ������������Ľڵ����˽ڵ�

            tempNode = NULL;
        }// End if (tempNode->getRoot() == to_delete)    //ɾ���ڵ�

        else if (to_delete < tempNode->getRoot())    //������������Ҫɾ���Ľڵ�
        {
            child = 0;
            tempNode_Parent = tempNode;
            tempNode = tempNode->left;
        }

        else    //������������Ҫɾ���Ľڵ�
        {
            child = 1;
            tempNode_Parent = tempNode;
            tempNode = tempNode->right;
        }
    }    //End while (tempNode != NULL)
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     �ڶ����������ɾ���ڵ�
* Input:                     to_delete Ҫ���ҽڵ�
* Output:                   NO OUTPUT
*******************************************************/
inline void BinaryTree::DeleteTreeNode_TreeRootNode(int to_delete)
{
    DeleteTreeNode(TreeRootNode, to_delete);
}

/*���Թ��������õĺ���*/

/*inline void BinaryTree::DeleteTreeNode(TreeNode* TreeNodeCopyTemp, int to_delete)
{
    int flag;
    flag = 0;

    TreeNode* TreeNode_to_delete=NULL;    //p
    //TreeNode_to_delete = new TreeNode;

    TreeNode* TreeNode_to_delete_parent=NULL;    //f
    //TreeNode_to_delete_parent = new TreeNode;

    TreeNode* TreeNode_to_replace_deleteNode=NULL;    //s
    //TreeNode_to_replace_deleteNode = new TreeNode;

    TreeNode* TreeNode_to_replace_deleteNode_parent=NULL;    //q
    //TreeNode_to_replace_deleteNode_parent = new TreeNode;

    TreeNode_to_delete = TreeFind(TreeRootNode,to_delete);
    TreeNode_to_delete_parent = get_TreeFind_parnet(TreeRootNode, TreeNode_to_delete);

    if (TreeNode_to_delete == NULL)
    {
        cout << "Not Fount" << endl;
    }
    else
    {
        if (TreeNode_to_delete->left == NULL)
        {
            TreeNode_to_replace_deleteNode = TreeNode_to_delete->right;
        }
        else if (TreeNode_to_delete->right == NULL)
        {
            TreeNode_to_replace_deleteNode = TreeNode_to_delete->left;
        }
        else
        {
            TreeNode_to_replace_deleteNode_parent = TreeNode_to_delete;
            TreeNode_to_replace_deleteNode = TreeNode_to_delete->left;
            while (TreeNode_to_replace_deleteNode->right != NULL)
            {
                TreeNode_to_replace_deleteNode_parent = TreeNode_to_replace_deleteNode;
                TreeNode_to_replace_deleteNode = TreeNode_to_replace_deleteNode->right;
            } 
            if (TreeNode_to_replace_deleteNode_parent == TreeNode_to_delete)
            {
            TreeNode_to_replace_deleteNode_parent->left = TreeNode_to_replace_deleteNode->left;
            }
            else
            {
                TreeNode_to_replace_deleteNode_parent->right= TreeNode_to_replace_deleteNode->left;
            }
            TreeNode_to_delete->changeRoot(TreeNode_to_replace_deleteNode->getRoot());
            delete TreeNode_to_replace_deleteNode;

            flag = 1;
        }

        if (flag == 0)
        {
            if (TreeNode_to_delete_parent == NULL)
            {
                TreeNodeCopyTemp = TreeNode_to_replace_deleteNode;
            }
            else if(TreeNode_to_delete_parent->left == TreeNode_to_delete)
            {
                TreeNode_to_delete_parent->left = TreeNode_to_replace_deleteNode;
            }
            else
            {
                TreeNode_to_delete_parent->right = TreeNode_to_replace_deleteNode;
            }

            delete TreeNode_to_replace_deleteNode;
            delete TreeNode_to_delete;
        }
    }
}*/

/*inline void BinaryTree::DeleteTreeNode(TreeNode* TreeNodeDelete, int to_delete)
{
    if (TreeNodeDelete == NULL)
    {
        return;
    }
    if (TreeNodeDelete->getRoot() > to_delete)
    {
        DeleteTreeNode(TreeNodeDelete->left, to_delete);//�������Ľ��ֵ������ֵ�󣬾���Ҫ����������
    }
    else if (TreeNodeDelete->getRoot() < to_delete)
    {
        DeleteTreeNode(TreeNodeDelete->right, to_delete);//�������Ľ��ֵ������ֵС������Ҫ����������
    }
    else
    { //���ҵ���ɾ���ڵ�
       //������ҽ��Ϊ��ֻ��Ҫ��ʣ�µ��һ�������������ȥ
        if (TreeNodeDelete->left == NULL)
        { //������Ϊ��
            TreeNode* tempNode = TreeNodeDelete;
            TreeNodeDelete = TreeNodeDelete->right;
            delete tempNode;
        }
        else if (TreeNodeDelete == NULL)
        { //������Ϊ��
            TreeNode* tempNode = TreeNodeDelete;
            TreeNodeDelete = TreeNodeDelete->left;
            delete tempNode;
        }
        else
        {
            //������������Ϊ��
            //һ���ɾ����������������������� �� ����������С���� ����ýڵ�
            //(������ò����������������������,��������������������Ǹ��ڵ�
            TreeNode* tempNode = TreeNodeDelete->left;//��������
            if (tempNode->right != NULL)
            {
                tempNode = tempNode->right;//����������������
            }
            TreeNodeDelete->changeRoot(tempNode->getRoot());//����������ֵ������Ҫɾ�����ǽ��
            DeleteTreeNode(TreeNodeDelete->left, tempNode->getRoot());//ɾ��������
        }
    }
}*/