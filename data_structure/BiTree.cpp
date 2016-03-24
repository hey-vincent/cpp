#include "BiTree.h"
#include <iostream>


BiTree::BiTree(void)
{
	m_root = NULL;
}


BiTree::~BiTree(void)
{
	//Free memory for Tree. Need to do.
	vector<NODE*> vecNodes = Read_Nodes_ByLine();
	if (!vecNodes.empty())
	{
		for(auto iter = vecNodes.begin(); iter != vecNodes.end();iter++)
		{
			free(*iter);
		}
	}

}

/******************************************************************/
//Create a search tree according the give data
/******************************************************************/
int BiTree::Create_SearchTree(vector<int> vecData)
{
	for(auto i = 0; i < vecData.size(); i++)
	{
		for (auto j = 0; j < i; j++ )
		{
			if(vecData[i] < vecData[j])
			{
				auto exchg = vecData[j];
				vecData[j] = vecData[i];
				vecData[i] = exchg;
			}
		}
	}
	auto mid_index = (int)(vecData.size() / 2);
	auto root_data = vecData[mid_index];
	m_root = (NODE*)malloc(sizeof(NODE));
	memcpy(m_root->pData, &vecData[mid_index], sizeof(void*));
	
	auto node_counts = 1;										// counts of node
	auto index = 1;
	list<NODE> listNode;
	listNode.push_back(*m_root);
	NODE *pNode = NULL;
	
	return 0;
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
		m_root = pNew_Node;
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
int BiTree::Remove_Node(NODE* pNode)
{
	if (NULL == pNode)
	{
		return -1;
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

/******************************************************************/
//Read all nodes by lines
//return value: vector<NODE*> ,all nodes of tree
/******************************************************************/
vector<BiTree::NODE*> BiTree::Read_Nodes_ByLine()
{
	vector<NODE*> vecNodes;	
	if (NULL == m_root)
	{
		return vecNodes;											// invalid start node
	}
	vecNodes.push_back(m_root);	

	int cursor = 0;												// Elements before cursor has been read. 
	int counts  = 1;
	
	while(cursor < vecNodes.size())
	{
		while (cursor <  counts)									// Elements after cursor are need to be read.
		{
			if (NULL != vecNodes[cursor]->pLSon)
				vecNodes.push_back(vecNodes[cursor]->pLSon);
			if (NULL != vecNodes[cursor]->pRSon)
				vecNodes.push_back(vecNodes[cursor]->pRSon);
		}
		cursor ++;									
		counts = vecNodes.size();
	}

	return vecNodes;
}