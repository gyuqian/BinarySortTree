/***********************************************
* Auther:				gyuqian
* Data:					2020/12/15
* Last-modified:		2020/12/18
* File:					对一棵二叉树操作的封装
*                          函数实现
************************************************/
#pragma once
#include "BinaryTree.h"
#include "iostream"

using namespace std;

/******************************************************
 * Author : gyuqian
 * Date   : 2020/12/16
 * Func   : 构造函数，初始化二叉树类中变量的初始值
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
 * Func      : 生成一个随机数，数值范围为 0~MaxData
 * Input      : Nothing
 * Output    : 返回一个随机数
 ******************************************************/
inline int BinaryTree::getARandNumberBetweenZeroAndMaxData()
{
    return rand() % MaxData;    //生成随机数，数值范围0~MaxData
}

/******************************************************
* Author    :gyuqian
* Data       :2020/12/16
* Func       :生成随机数列并输出，
                  同时使用随机数列创建二叉排序树
* input       :NO INPUT
* output     :NO OUTPUT
*******************************************************/
inline void BinaryTree::getRandRootData_creetTree()
{
    int i;    //定义局部循环变量
    //int* temp_rootdata;    //生成随机数列的暂存
    rootdata = new int[DataCount];

    int randnumber;   //随机数缓存变量

    cout << "Random Sequence:" << endl;    //输出提示

    //
    //循环过程，生成DataCount个随机数列，同时创建二叉排序树
    //
    for (i = 0; i < DataCount; i++)
    {
        randnumber= getARandNumberBetweenZeroAndMaxData();   //生成随机数
        TreeNode* TreeNodeReturn;    //定义局部变量，用于存储随机数在二叉排序树中的查找结果
        TreeNodeReturn = TreeFind(TreeRootNode, randnumber);    //查询生成的随机数是否在二叉树中
        //
        //生成不重复的随机数
        while (TreeNodeReturn != NULL)
        {
            randnumber = getARandNumberBetweenZeroAndMaxData();
            TreeNodeReturn = TreeFind(TreeRootNode, randnumber);
        }
        delete TreeNodeReturn;    //释放局部变量的内存

        //输出产生的随机数
        cout << randnumber << " ";
        //将生成的随机数列存储
        *(rootdata + i) = randnumber;
        //将生成的随机数插入二叉排序树
        TreeRootNode = insertNode(TreeRootNode, randnumber);
    }
    cout << endl;
}

/******************************************************
* Author    :gyuqian
* Data       :2020/12/16
* Func       :程序内变量赋值
* input       :data 用于赋值DataCount
*               :max 用于赋值MaxData
* output     :NO OUTPUT
*******************************************************/
inline void BinaryTree::GetMaxDataAndDataCount(int data, int max)
{
    DataCount = data;    //赋值DataCount
    MaxData = max;    //赋值MaxData
}

/******************************************************
* Author    :gyuqian
* Data       :2020/12/16
* Func       :从键盘读取数据，对变量赋值
* input       :From Keyboard
* output     :NO OUTPUT
*******************************************************/
inline void BinaryTree::GetMaxDataAndDataCountFromKeyboard()
{
    GetDataCountFromKeyBoard();    //获取生成随机数列的数据个数
    GetMaxDataFromKeyBoard();    //获取生成随机数列数据的最大值

    ///
    //以下为测试使用，已弃用
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
* Func:                     从键盘读取数据，对变量赋值
* Input:                     From Keyboard
* Output:                   输出提示
*******************************************************/
inline void BinaryTree::GetDataCountFromKeyBoard()
{
    cout << "Please input \"DataCount\"(0<DataCount<=20)" << endl;
    
    cin >> DataCount;

    //对输入的数据进行判断，如果不符合要求则重新输入
    if (cin.fail()==1)    //错误输入，标志位自动置1
    {
        cout << "Error Input" << endl;
        //cin.sync();    
        cin.clear();    //重置标志位
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');    //清空输入缓冲区

        GetDataCountFromKeyBoard();
    }
    if (DataCount <0 || DataCount > 20)    //对输入数据的大小进行判断，如果不符合要求则重新输入
    {
        cout << "Error Input" << endl;

        GetDataCountFromKeyBoard();
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     从键盘读取数据，对变量赋值
* Input:                     From Keyboard
* Output:                   输出提示
*******************************************************/
inline void BinaryTree::GetMaxDataFromKeyBoard()
{
    cout << "Please input \"MaxData\"(50<=MaxData<=100)" << endl;
    cin >> MaxData;

    //对输入的数据进行判断，如果不符合要求则重新输入
    if (cin.fail() == 1)//错误输入，标志位自动置1
    {
        cout << "Error Input" << endl;
        //cin.sync();
        cin.clear();    //重置标志位
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');    //清空输入缓冲区

        GetMaxDataFromKeyBoard();
    }
    if (MaxData < 50 || MaxData>100)    //对输入数据的大小进行判断，如果不符合要求则重新输入
    {
        cout << "Error Input" << endl;

        GetMaxDataFromKeyBoard();
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     向二叉树中插入新节点
* Input:                     a：要输入的数据
*                              TreeNodeinsert：需要操作的二叉树
* Output:                   操作完成的二叉树
*******************************************************/
inline TreeNode* BinaryTree::insertNode(TreeNode* TreeNodeinsert, int a)
{
    if (TreeNodeinsert == NULL)    //二叉树为空
    {
        TreeNodeinsert = new TreeNode;
        TreeNodeinsert->changeRoot(a) ;
    }
    else  if (a < TreeNodeinsert->getRoot())    //插入左子树
    {
        TreeNodeinsert->left = insertNode(TreeNodeinsert->left, a);
    } 
    else    //插入右子树
    {
        TreeNodeinsert->right = insertNode(TreeNodeinsert->right, a);
    } 
    return TreeNodeinsert;

    delete TreeNodeinsert;    //释放局部变量的内存
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     获取二叉树的树高
* Input:                     TreeNodeinsert：需要操作的二叉树
* Output:                   high：树高
*******************************************************/
inline void BinaryTree::getTreeHigh(TreeNode* Tree, int& high)
{
    if (Tree == NULL)    //空树
    {
        high = 0;
        return;
    }
    else
    {
        int lhigh;  //左子树
        int rhigh;   //右子树

        getTreeHigh(Tree->left, lhigh);  //求左子树高度
        getTreeHigh(Tree->right, rhigh);  //求右子树高度
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
* Func:                     获取对象中二叉树的树高
* Input:                     对象中的二叉树
* Output:                   向屏幕输出：
*                               high：树高
*******************************************************/
inline void BinaryTree::getTreeHigh_TreeRootNode()
{
    getTreeHigh(TreeRootNode, high);

    cout << "High：" << endl << high << endl;
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     输出二叉树的叶子节点
* Input:                     Tree：需要操作的二叉树
* Output:                   向屏幕输出：
*                               每一个叶子节点
*******************************************************/
inline void BinaryTree::outTreeLeaf(TreeNode* Tree)
{
    if (Tree == NULL)    //空树
    {
        return;
    }
    else if (Tree->left == NULL && Tree->right == NULL)    //结点的左右子树同时为空，即为叶子
    {
        cout << Tree->root << " ";
        return;
    }
    else
    {
        outTreeLeaf(Tree->left);    //输出左子树的叶子节点
        outTreeLeaf(Tree->right);   //输出右子树的叶子节点
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     输出对象中二叉树的叶子节点
* Input:                     NO INPUT
*                               操作对象中的二叉树
* Output:                   向屏幕输出：
*                               每一个叶子节点
*******************************************************/
inline void BinaryTree::outTreeLeaf_TreeRootNode()
{
    cout << "Leaf：" << endl;
    outTreeLeaf(TreeRootNode);
    cout << endl;
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     输出二叉树的中序遍历结果
* Input:                     Tree：需要操作的二叉树
* Output:                   向屏幕输出：
*                               中序遍历结果
*******************************************************/
inline void	BinaryTree::inordeTree(TreeNode* Tree)
{
    if (Tree != NULL)
    {
        inordeTree(Tree->left);    //遍历左子树
        cout << Tree->getRoot() << " ";    //输出节点值
        inordeTree(Tree->right);    //遍历右子树
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     输出对象中二叉树的中序遍历结果
* Input:                     NO INPUT
*                               操作对象中的二叉树
* Output:                   向屏幕输出：
*                               中序遍历结果
*******************************************************/
inline void BinaryTree::inordeTree_TreeRootNode()
{
    if (TreeRootNode != NULL)
    {
        cout << "BinarySortTree：" << endl;
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
* Func:                     深度复制二叉树
* Input:                     rootNode 要复制的源二叉树
* Output:                   二叉树副本
*******************************************************/
inline TreeNode* BinaryTree::TreeClone(TreeNode* rootNode)
{
    if (rootNode == NULL) //空树
    {
        return NULL;
    }
    TreeNode* new_node = NULL;
    new_node = new TreeNode;

    new_node->changeRoot(rootNode->root);
    new_node->left = TreeClone(rootNode->left);    //拷贝左子树
    new_node->right = TreeClone(rootNode->right);    //拷贝右子树

    return new_node;
    delete new_node;
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     用拷贝的方式创建对象中的二叉树
* Input:                     rootNode 要复制的源二叉树
* Output:                   对象中的二叉树
*******************************************************/
inline void BinaryTree::TreeClonde_paste(TreeNode* rootNode)
{
    TreeRootNode = TreeClone(rootNode);
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     获取指定节点的父节点
* Input:                     TreeNode_to_getParent 要查找父节点的节点
*                              TreeNodefound 要查找的树
* Output:                   找到的父节点
*******************************************************/
inline TreeNode* BinaryTree::get_TreeNode_parnet(TreeNode* TreeNodefound, TreeNode* TreeNode_to_getParent)
{
    TreeNode* TreeNodefound_left = NULL;
    //TreeNodefound_left = new TreeNode;
    
    TreeNode* TreeNodefound_right = NULL;
    //TreeNodefound_right = new TreeNode;

    if (TreeNodefound == NULL    //空树
        || TreeNodefound->left == TreeNode_to_getParent 
        || TreeNodefound->right == TreeNode_to_getParent)    //根节点就是要查找的父节点
    {
        return TreeNodefound;
    }

    //左子树是否为父节点
    TreeNodefound_left = get_TreeNode_parnet(TreeNodefound->left, TreeNode_to_getParent); 
    if (TreeNodefound_left != NULL)
    {
        
        return TreeNodefound_left;
        delete TreeNodefound_left;
        delete TreeNodefound_right;
    }//是的话，return，无需找右子树

    //右子树是否为父节点
    TreeNodefound_right = get_TreeNode_parnet(TreeNodefound_right, TreeNode_to_getParent); 
    if (TreeNodefound_right != NULL)
    {
        
        return TreeNodefound_right;
        delete TreeNodefound_left;
        delete TreeNodefound_right;
    }//是的话，return

    delete TreeNodefound_left;
    delete TreeNodefound_right;
    return NULL; //左右子树未找到，返回NULL
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/18
* Func:                     在二叉树中寻找节点
* Input:                     to_find 要查找节点
*                              TreeNodefound 要查找的树
* Output:                   寻找的结果
*******************************************************/
inline TreeNode* BinaryTree::TreeFind(TreeNode* TreeNodefound, int to_find)
{
    if (TreeNodefound == NULL)    //空树
    {
        return TreeNodefound;
    }
    else
    {
        if (TreeNodefound->root == to_find)    //根节点就是要查找的节点
        {
            return TreeNodefound;
        }
        else if (TreeNodefound->root > to_find)    //查找左子树
        {
            return TreeFind(TreeNodefound->left, to_find);
        }
        else    //查找右子树
        {
            return TreeFind(TreeNodefound->right, to_find);
        }
    }
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/22
* Func:                     在对象二叉树中寻找节点
* Input:                     to_find 要查找节点
* Output:                   寻找的结果
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
        //输出找到的根节点的地址
        cout << "Found " << "Address：" << TreeNodereturn << "value：" << TreeNodereturn->getRoot() << endl;
    }

    //delete TreeNodereturn;
}

/******************************************************
* Author:                  gyuqian
* Data:                     2020/12/16
* Last-modified:		    2020/12/20
* Func:                     删除二叉树中的节点
* Input:                     to_delete 要查找节点
*                              TreeNodeCopyTemp：要删除二叉树的
*                              临时拷贝
* Output:                   NO OUTPUT
*******************************************************/
inline void BinaryTree::DeleteTreeNode(TreeNode* TreeNodeCopyTemp, int to_delete)
{
    TreeNode* L = NULL;
    TreeNode* LL = NULL;

    TreeNode* tempNode=NULL;    //要删除的节点
    tempNode = TreeNodeCopyTemp;

    TreeNode* tempNode_Parent;    //要删除节点的父节点
    tempNode_Parent = TreeNodeCopyTemp;

    int child;
    child = 0;    //子节点标志位，0为左孩子，1为右孩子

    if (TreeNodeCopyTemp == NULL)    //空树
    {
        return;
    }

    while (tempNode != NULL)
    {
        if (tempNode->getRoot() == to_delete)    //删除节点
        {
            if (tempNode->left == NULL && tempNode->right == NULL)    //要删除的节点是叶子节点
            {
                if (tempNode == TreeNodeCopyTemp)    //要删除的是根节点,且树高为1
                {
                    delete tempNode;
                }
                else if (child == 0)    //要删除节点是其父节点的左孩子
                {
                    tempNode_Parent->left = NULL;
                    delete tempNode;
                }
                else    //要删除节点是其父节点的右孩子
                {
                    tempNode_Parent->right = NULL;
                    delete tempNode;
                }
            }    //End if (tempNode->left == NULL && tempNode->right == NULL)    //要删除的节点是叶子节点

            else if (tempNode->right == NULL)    //要删除节点只有左孩子
            {
                if (child == 0)    //要删除节点是其父节点的左孩子
                {
                    tempNode_Parent->left = tempNode->left;
                }
                else    //要删除节点是其父节点的右孩子
                {
                    tempNode_Parent->right = tempNode->left;
                }

                delete tempNode;
            }    //End else if (tempNode->right == NULL)    //要删除节点只有左孩子

            else    //要删除的节点有左右孩子，找右子树最小的节点代替此节点
            {
                LL = tempNode;
                L = tempNode->right;    //右孩子 / 右子树

                while (L->left != NULL)    //寻找右子树中的最小值
                {
                    LL = L;
                    L = L->left;
                }
                tempNode->changeRoot(L->getRoot());

                if (LL == tempNode)    //右孩子的左子树为空
                {
                    LL->right = L->right;
                }
                else
                {
                LL->left = L->right;
                }

                delete L;
                /*
                if (L->left!=NULL)    //右孩子的左子树不为空
                {
                    LL = L; 
                    L = L->left;
                    tempNode->changeRoot(L->getRoot()); //用
                    LL->left = L->left;

                    while ( L->left != NULL)
                    {
                        L->left = tempNode->left;
                        L = L->left;
                    }
                    tempNode->left = NULL;
                }
                else    //右孩子的左子树为空
                {
                    tempNode->changeRoot(L->getRoot());
                    LL->right = L->right;
                }*/

            }    //End else    //要删除的节点有左右孩子，找左子树最大的节点代替此节点

            tempNode = NULL;
        }// End if (tempNode->getRoot() == to_delete)    //删除节点

        else if (to_delete < tempNode->getRoot())    //在左子树查找要删除的节点
        {
            child = 0;
            tempNode_Parent = tempNode;
            tempNode = tempNode->left;
        }

        else    //在右子树查找要删除的节点
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
* Func:                     在对象二叉树中删除节点
* Input:                     to_delete 要查找节点
* Output:                   NO OUTPUT
*******************************************************/
inline void BinaryTree::DeleteTreeNode_TreeRootNode(int to_delete)
{
    DeleteTreeNode(TreeRootNode, to_delete);
}

/*调试过程中弃用的函数*/

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
        DeleteTreeNode(TreeNodeDelete->left, to_delete);//遍历到的结点值比所给值大，就需要遍历左子树
    }
    else if (TreeNodeDelete->getRoot() < to_delete)
    {
        DeleteTreeNode(TreeNodeDelete->right, to_delete);//遍历到的结点值比所给值小，就需要遍历右子树
    }
    else
    { //查找到了删除节点
       //左或者右结点为空只需要将剩下的右或者左子树换上去
        if (TreeNodeDelete->left == NULL)
        { //左子树为空
            TreeNode* tempNode = TreeNodeDelete;
            TreeNodeDelete = TreeNodeDelete->right;
            delete tempNode;
        }
        else if (TreeNodeDelete == NULL)
        { //右子树为空
            TreeNode* tempNode = TreeNodeDelete;
            TreeNodeDelete = TreeNodeDelete->left;
            delete tempNode;
        }
        else
        {
            //左右子树都不为空
            //一般的删除策略是左子树的最大数据 或 右子树的最小数据 代替该节点
            //(这里采用查找左子树最大数据来代替,最大是在左子树的最右那个节点
            TreeNode* tempNode = TreeNodeDelete->left;//找左子树
            if (tempNode->right != NULL)
            {
                tempNode = tempNode->right;//找左子树的右子树
            }
            TreeNodeDelete->changeRoot(tempNode->getRoot());//将右子树的值赋给需要删除的那结点
            DeleteTreeNode(TreeNodeDelete->left, tempNode->getRoot());//删除右子树
        }
    }
}*/