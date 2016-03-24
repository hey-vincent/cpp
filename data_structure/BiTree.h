#pragma once

#include <vector>
#include <stack>
#include <list>
using namespace std;

typedef enum Pos
{
	left		=	0,
	right	=	1,
};



class BiTree
{
	typedef struct _node 
	{
		 void*	pData;
		_node*	pLSon;
		_node*	pRSon;

		_node()
		{
			pData = NULL;
			pLSon = NULL;
			pRSon = NULL;
		}

	}NODE;

public:
	 BiTree(void);
	~BiTree(void);

	// create a search-tree 
	int Create_SearchTree(vector<int> vecData);

	// insert a node into a tree
	int Insert_Node(NODE* pNode, void* pData);

	// remove a node of tree
	int Remove_Node(NODE* pNode);

	// three ways to traverse binary tree
	int Traverse_Previous(NODE* pStart);
	int Traverse_Middle();
	int Traverse_Back();

	// read nodes
	vector<NODE*> Read_Nodes_ByLine();

private:
	NODE* m_root;				// root_node

};

