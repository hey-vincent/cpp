#include "Chain.h"
#include <memory.h>
#include <stdlib.h>


Chain::Chain()
{
	m_nSize = 0;
	pHead = NULL;
	pTail = NULL;
}

Chain::~Chain()
{
	
}

int Chain::insert(Node* pPrev, void* pData)
{
	// Allocate memory for new element
	Node* pNewElement = (Node*)malloc(sizeof(Node));
	if(pNewElement == NULL)
							{
								return -1;
							}
	pNewElement->pData = pData;
	pNewElement->pNext = NULL;
	
	if(NULL == pPrev)		// insert at head
							{
								pNewElement->pNext = pHead;
								pHead = pNewElement;			// now new element become the HEAD of list
								if(NULL == pNewElement->pNext)
								{
									pTail = pNewElement;
								}
								m_nSize++;
							}
	else					// insert at body
							{
								Node* pOld = pPrev->pNext;		// old next
								pPrev->pNext = pNewElement;	// new next
								(pPrev->pNext)->pNext= pOld;// old next behind new element inserted

								if(pOld == NULL)
								{
									pTail = pNewElement;
								}
								m_nSize++;
							}
		
	return 0;
	
}

/*********************************************************************/
/* remove the element behind pPrev
/*********************************************************************/
int Chain::remove(Node* pPrev)
{
	Node* pOld = pPrev->pNext;		//old next
	if (NULL == pOld)
	{
		cout << "Error! Out of range.Try to remove an element located behind tail." << endl;
		return -1;
	}
	pPrev->pNext = pOld->pNext;
    free(pOld);
	m_nSize --;
    return 0;
}


/*********************************************************************/
/*Get head node of the list
/*********************************************************************/
Node* Chain::head()
{
	return pHead;
}

/*********************************************************************/
/*Get head node of the list
/*********************************************************************/
Node* Chain::tail()
{
	return pTail;
}

/*********************************************************************/
/*Get head node of the list
/*********************************************************************/
int Chain::size()
{
	return m_nSize;
}



/*********************************************************************/
/* Print all elements of the list
/*********************************************************************/
void Chain::show_list()
{
	Node* pStart =  pHead;
	cout << "size: " << m_nSize <<endl;
	cout << "elmt: " ;
	while(pStart != NULL)
	{
		int  *pData = (int*)(pStart->pData);
		cout << *pData << ", ";
		pStart = pStart->pNext;
	}
	cout << endl;
}

