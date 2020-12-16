#include "TreeNode.h"
#include "iostream"

inline TreeNode::TreeNode()
{
	left = NULL;
	right = NULL;
	root = -1;
}

inline void TreeNode::changeRoot(int noderoot)
{
	root = noderoot;
}

inline int TreeNode::getRoot()
{
	return root;
}