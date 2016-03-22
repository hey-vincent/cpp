#include "BiTree.h"
#include <iostream>

BiTree::BiTree(void)
{
}


BiTree::~BiTree(void)
{
	//Free memory for Tree. Need to do.

}

/******************************************************************/
//Insert data into a tree as a node.
/******************************************************************/
int BiTree::Insert_Node(NODE* pNode,void* pData)
{
	NODE* pNew_Node = (NODE*)malloc(sizeof(NODE));
	if (NULL == pNew_Node)
	{
		return -1;
	}
	memcpy(pNew_Node->pData, pData, sizeof(void*));				// copy value
	if (NULL == pNode)
	{
		root = pNew_Node;
		return 0;
	}

	auto pNode_Left = pNode->pLSon;								// Original sons
	auto pNode_Right= pNode->pRSon;

	if( memcmp(pData, pNode->pData, sizeof(pData)) <= 0)			// left son
	{
		// original node
		if (NULL != pNode->pLSon)
		{
			pNode->pLSon = pNew_Node;
		}
		pNew_Node->pLSon = pNode_Left;
	}
	else														// right son
	{
		if (NULL != pNode->pRSon)
		{
			pNode->pRSon = pNew_Node;
		}
		pNew_Node->pRSon = pNode_Right;
	}

	return 0;
}


/******************************************************************/
//Traverse a binary tree previous. Root -> left_song -> right_son
/******************************************************************/
int BiTree::Traverse_Previous(NODE* pStart)
{
	if (NULL == pStart)
	{
		return -1;											// invalid start node
	}
	int data = *((int*)pStart->pData);
	std::cout<< data << std::endl;
	Traverse_Previous(pStart->pLSon);
	Traverse_Previous(pStart->pRSon);
	return 0;
}

int BiTree::Read_Nodes(NODE* pStart,int nSize)
{
	if (NULL == pStart)
	{
		return -1;											// invalid start node
	}
	int data = *((int*)pStart->pData);
	std::stack<NODE*> nodes_stack;
	
	while(pStart->pLSon)
	{
		nodes_stack.push(pStart->pLSon);
	}

	return 0;
}