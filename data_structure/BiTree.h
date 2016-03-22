#pragma once

#include <stack>

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

	// insert a node into a tree
	int Insert_Node(NODE* pNode, void* pData);

	// three ways to traverse binary tree
	int Traverse_Previous(NODE* pStart);
	int Traverse_Middle();
	int Traverse_Back();

	// read nodes
	int Read_Nodes(NODE*,int);

private:
	NODE* root;				// root_node

};

