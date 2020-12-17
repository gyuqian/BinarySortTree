#pragma once
#include "homework.h"

#include <iostream>

inline void homework::homework1()
{
    Tree.GetMaxDataAndDataCountFromKeyboard();
	Tree.getRandRootData_creetTree();
	Tree.getTreeHigh_TreeRootNode();
	Tree.outTreeLeaf_TreeRootNode();
	Tree.inordeTree_TreeRootNode();
}

inline void homework::homework2()
{
	
	TreeClone.TreeClonde_TreeRootNode_V(Tree.TreeRootNode);

	int find_which_tree;
	find_which_tree = 0;
	int to_find;
	cout << "Please Input a Number to Choose a Tree£º" << endl
		<< "Enter 1 to Seach Source Binary Tree" << endl
		<< "Enter 2 to Seach The Copy Of Source Tree" << endl
		<< "Press Enter to confirm!" << endl;
	cin >> find_which_tree;
	if (find_which_tree == 1)
	{
		cout << "Please Input a Number to Find, Press Enter to confirm!" << endl;
	    cin >> to_find;
		Tree.TreeFind_TreeRootNode(to_find);
	}
	else if (find_which_tree == 2)
	{
		cout << "Please Input a Number to Find, Press Enter to confirm!" << endl;
		cin >> to_find;
		TreeClone.TreeFind_TreeRootNode(to_find);
	}

	int to_delete;
	cout << "Please Input a Number to Delete, Press Enter to confirm!" << endl;
	cin >> to_delete;

	TreeClone.DeleteTreeNode_TreeRootNode(to_delete);
	TreeClone.inordeTree_TreeRootNode();
}