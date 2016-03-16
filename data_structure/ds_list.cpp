#include "ds_list.h"
#include <memory.h>
#include <stdlib.h>


ds_List::ds_List()
{
	m_nSize = 0;
	pHead = NULL;
	pTail = NULL;
}

ds_List::~ds_List()
{
	
}

int ds_List::insert_element(List_Elm* pPrev, void* pData)
{
	// Allocate memory for new element
	List_Elm* pNewElement = (List_Elm*)malloc(sizeof(List_Elm));
	if(pNewElement == NULL)
							{
								return -1;
							}
	pNewElement->pData = pData;
	pNewElement->pNext = NULL;
	
	if(pPrev == NULL)
							{
								pNewElement->pNext = pHead;
								pHead = pNewElement;			// now new element become the HEAD of list
								if(m_nSize == 0)
								{
									pTail = pNewElement;		// new element is tail if this list is empty.
								}
								m_nSize++;
							}
	else
							{
								// insert 
								List_Elm* pPreNext = pPrev->pNext;// maybe it's NULL. whatever.
								*pPrev->pNext = *pNewElement;
								*(pNewElement->pNext) = *pPreNext;
								if(pPreNext == NULL)
								{
									*pTail = *pNewElement;		// now tail was changed.
								}
								m_nSize++;
							}
		
	return 0;
	
}

/*********************************************************************/
/* remove the element behind pPrev
/*********************************************************************/
int ds_List::remove_element(List_Elm* pPrev)
{
    List_Elm *pBefore = (pPrev->pNext);
    //1. pPrev point to next->next
    *(pPrev->pNext) = *(pBefore->pNext);
    //2. free memory for element which was removed
    free(pBefore);

    return 0;
}





/*********************************************************************/
/*Get head node of the list
/*********************************************************************/
List_Elm* ds_List::get_head()
{
	return pHead;
}

/*********************************************************************/
/*Get head node of the list
/*********************************************************************/
List_Elm* ds_List::get_tail()
{
	return pTail;
}




/*********************************************************************/
/* Print all elements of the list
/*********************************************************************/
void ds_List::show_list()
{
	List_Elm* pStart =  pHead;
	while(pStart->pNext != NULL)
	{
		int  *pData = (int*)(pStart->pData);
		cout << *pData << '\t';
		pStart = pStart->pNext;
	}
}

