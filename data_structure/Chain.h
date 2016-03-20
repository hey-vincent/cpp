#include <iostream>
#include <memory.h>
using namespace std;

/*********************************************************************
# structure of an List_Elm of List.
# Users who wants to use the list just care about the DATA of element.
# They have no need to pay their attention on  the pointer to NEXT.
*********************************************************************/
typedef struct node
{
	void *pData;
	node *pNext;
	
	node()
	{
		pData = NULL;
		pNext = NULL;
	}
}Node;


class Chain
{
public:
	 Chain();
	~Chain();

private:
	int    m_nSize;
	Node*  pHead;
	Node*  pTail;
public:
	// insert
	int	insert(Node* pPrev, void* pData);
    
    // remove
    int remove(Node* pPrev);

	// Get
	int	 size();
	Node* head();
	Node* tail();
	
	// show list
	void show_list();

private:
	//int destroy(List_Elm* pElement);

};