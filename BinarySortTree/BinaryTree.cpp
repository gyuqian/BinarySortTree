#include "BinaryTree.h"
#include "Link.cpp"
#include "iostream"

using namespace std;

inline BinaryTree::BinaryTree()
{
    numberNodeCount = 0;
    DataCount = 0;
    MaxData = 0;
    rootdata = NULL;
    TreeRootNode = NULL;
    high = 0;
}

inline int BinaryTree::getARandNumberBetweenZeroAndMaxData()
{
    return rand() % MaxData;
}

inline void BinaryTree::getRandRootData_creetTree()
{
    int i;
    int randnumber;

    cout << "随机序列：" << endl;
    for (i = 0; i < DataCount; i++)
    {
        randnumber= getARandNumberBetweenZeroAndMaxData();
        TreeNode* TreeNodeReturn;
        TreeNodeReturn = TreeFind(TreeRootNode, randnumber);
        while (TreeNodeReturn != NULL)
        {
            randnumber = getARandNumberBetweenZeroAndMaxData();
            TreeNodeReturn = TreeFind(TreeRootNode, randnumber);
        }
        delete TreeNodeReturn;
        cout << randnumber << " ";
        TreeRootNode = insertNode(TreeRootNode, randnumber);
    }
    cout << endl;
}

inline void BinaryTree::GetMaxDataAndDataCount(int data, int max)
{
    DataCount = data;
    MaxData = max;
}

inline void BinaryTree::GetMaxDataAndDataCountFromKeyboard()
{
    /*cout << "Please input \"DataCount\"(0<DataCount<=20) and \"MaxData\"(50<=MaxData<=100)" << ":" << endl;
    cin >> DataCount >> MaxData;
    if (DataCount < 0 || DataCount>20 || MaxData < 50 || MaxData>100)
    {
        cout << "Error Input" << endl;
        GetMaxDataAndDataCountFromKeyboard();
    }*/
    GetDataCountFromKeyBoard();
    GetMaxDataFromKeyBoard();
}

inline void BinaryTree::GetDataCountFromKeyBoard()
{
    cout << "Please input \"DataCount\"(0<DataCount<=20)" << endl;
    
    cin >> DataCount;
    if (cin.fail()==1)
    {
        cout << "Error Input" << endl;
        cin.sync();
        cin.clear();
        cin.ignore();
        GetDataCountFromKeyBoard();
    }
    if (DataCount <0 || DataCount > 20)
    {
        cout << "Error Input" << endl;
        GetDataCountFromKeyBoard();
    }
}

inline void BinaryTree::GetMaxDataFromKeyBoard()
{
    cout << "Please input \"MaxData\"(50<=MaxData<=100)" << endl;
    cin >> MaxData;
    if (cin.fail() == 1)
    {
        cout << "Error Input" << endl;
        cin.sync();
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max());
        GetMaxDataFromKeyBoard();
    }
    if (MaxData < 50 || MaxData>100)
    {
        cout << "Error Input" << endl;
        GetMaxDataFromKeyBoard();
    }
}

inline TreeNode* BinaryTree::insertNode(TreeNode* TreeNodeinsert, int a)
{
    if (TreeNodeinsert == NULL)
    {
        TreeNodeinsert = new TreeNode;
        TreeNodeinsert->changeRoot(a) ;
    }
    else  if (a < TreeNodeinsert->getRoot())
    {
        TreeNodeinsert->left = insertNode(TreeNodeinsert->left, a);
    }     //插入左子树
    else
    {
        TreeNodeinsert->right = insertNode(TreeNodeinsert->right, a);
    }     //插入右子树
    return TreeNodeinsert;
    delete TreeNodeinsert;
}

inline void BinaryTree::getTreeHigh(TreeNode* Tree, int& high)
{
    if (Tree == NULL)
    {
        high = 0;
        return;
    }
    else
    {
        int lhigh, rhigh;
        getTreeHigh(Tree->left, lhigh);  //求左子树高度
        getTreeHigh(Tree->right, rhigh);  //求右子树高度
        if (lhigh >= rhigh)
            high = lhigh + 1;
        else
            high = rhigh + 1;
    }
}

inline void BinaryTree::getTreeHigh_TreeRootNode()
{
    getTreeHigh(TreeRootNode, high);
    cout << "树高：" << high << endl;
}

inline void BinaryTree::outTreeLeaf(TreeNode* Tree)
{
    if (Tree == NULL)
        return;
    else if (Tree->left == NULL && Tree->right == NULL)
        //结点的左右子树同时为空，即为叶子
    {
        cout << Tree->root << " ";
        return;
    }
    else
    {
        outTreeLeaf(Tree->left);
        outTreeLeaf(Tree->right);
    }
}

inline void BinaryTree::outTreeLeaf_TreeRootNode()
{
    cout << "叶子：" << endl;
    outTreeLeaf(TreeRootNode);
    cout << endl;
}

inline void	BinaryTree::inordeTree(TreeNode* Tree)
{
    if (Tree != NULL)
    {
        inordeTree(Tree->left);
        cout << Tree->getRoot() << "  ";
        inordeTree(Tree->right);
    }
}

inline void BinaryTree::inordeTree_TreeRootNode()
{
    if (TreeRootNode != NULL)
    {
        cout << "二叉排序树：" << endl;
        inordeTree(TreeRootNode);
        cout << endl;
    }
    else
    {
        cout << "This Tree Does Not Have A Node!";
    }
}

inline TreeNode* BinaryTree::TreeClone(TreeNode* rootNode)
{
    if (rootNode == NULL) {
        return NULL;
    }
    TreeNode* new_node = NULL;
    new_node = new TreeNode;
    new_node->changeRoot(rootNode->root);
    new_node->left = TreeClone(rootNode->left);
    new_node->right = TreeClone(rootNode->right);

    return new_node;
    delete new_node;
}

inline void BinaryTree::TreeClonde_TreeRootNode_V(TreeNode* rootNode)
{
    TreeRootNode = TreeClone(rootNode);
}

inline TreeNode* BinaryTree::get_TreeFind_parnet(TreeNode* TreeNodefound, TreeNode* TreeNode_to_getParent)
{
    TreeNode* TreeNodefound_left = NULL;
    //TreeNodefound_left = new TreeNode;
    
    TreeNode* TreeNodefound_right = NULL;
    //TreeNodefound_right = new TreeNode;

    if (TreeNodefound == NULL || TreeNodefound->left == TreeNode_to_getParent || TreeNodefound->right == TreeNode_to_getParent)
    {
        return TreeNodefound;
    }

    TreeNodefound_left = get_TreeFind_parnet(TreeNodefound->left, TreeNode_to_getParent); //的左孩子 是否为p的父节点
    if (TreeNodefound_left != NULL)
    {
        
        return TreeNodefound_left;
        delete TreeNodefound_left;
        delete TreeNodefound_right;
    }//是的话，return left，无需找右子树

    TreeNodefound_right = get_TreeFind_parnet(TreeNodefound_right, TreeNode_to_getParent); //root的右孩子 是否为p的父节点
    if (TreeNodefound_right != NULL)
    {
        
        return TreeNodefound_right;
        delete TreeNodefound_left;
        delete TreeNodefound_right;
    }//是的话，return right

    delete TreeNodefound_left;
    delete TreeNodefound_right;
    return NULL; //左右子树都不包含p，返回 null; (return right 同样是null)
}

inline TreeNode* BinaryTree::TreeFind(TreeNode* TreeNodefound, int to_find)
{
    if (TreeNodefound == NULL)
    {
        return TreeNodefound;
    }
    else
    {
        if (TreeNodefound->getRoot() == to_find)
        {
            return TreeNodefound;
        }
        else if (TreeNodefound->getRoot() > to_find)
        {
            return TreeFind(TreeNodefound->left, to_find);
        }
        else
        {
            return TreeFind(TreeNodefound->right, to_find);
        }
    }
}

inline void BinaryTree::TreeFind_TreeRootNode(int to_find)
{
    TreeNode* TreeNodereturn;
    TreeNodereturn = new TreeNode;
    TreeNodereturn=TreeFind(TreeRootNode, to_find);
    if (TreeNodereturn == NULL)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << "地址：" << TreeNodereturn << "值：" << TreeNodereturn->getRoot() << endl;
    }

    delete TreeNodereturn;
}

inline void BinaryTree::DeleteTreeNode(TreeNode* TreeNodeCopyTemp, int to_delete)
{
    TreeNode* L;
    TreeNode* LL;
    TreeNode* tempNode=NULL;

    tempNode = TreeNodeCopyTemp;

    TreeNode* tempNode_Parent;
    tempNode_Parent = TreeNodeCopyTemp;

    int child;
    child = 0;

    if (TreeNodeCopyTemp == NULL)
    {
        return;
    }

    while (tempNode != NULL)
    {
        if (tempNode->getRoot() == to_delete)
        {
            if (tempNode->left == NULL && tempNode->right == NULL)
            {
                if (tempNode == TreeNodeCopyTemp)
                {
                    delete tempNode;
                }
                else if (child == 0)
                {
                    tempNode_Parent->left = NULL;
                    delete tempNode;
                }
                else
                {
                    tempNode_Parent->right = NULL;
                    delete tempNode;
                }
            }
            else if (tempNode->right == NULL)
            {
                if (child == 0)
                {
                    tempNode_Parent->left = tempNode->left;
                }
                else
                {
                    tempNode_Parent->right = tempNode->left;
                }

                delete tempNode;
            }
            else
            {
                LL = tempNode;
                L = tempNode->left;

                if (L->left!=NULL)
                {
                    LL = L;
                    L = L->left;
                    tempNode->changeRoot(L->getRoot());
                    LL->left = L->left;

                    while ( L->left != NULL)
                    {
                        L->left = tempNode->left;
                        L = L->left;
                    }
                    tempNode->left = NULL;
                }
                else
                {
                    tempNode->changeRoot(L->getRoot());
                    LL->right = L->right;
                }
            }

            tempNode = NULL;
        }
        else if (to_delete < tempNode->getRoot())
        {
            child = 0;
            tempNode_Parent = tempNode;
            tempNode = tempNode->left;
        }
        else
        {
            child = 1;
            tempNode_Parent = tempNode;
            tempNode = tempNode->right;
        }
    }
}

inline void BinaryTree::DeleteTreeNode_TreeRootNode(int to_delete)
{
    DeleteTreeNode(TreeRootNode, to_delete);
}

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