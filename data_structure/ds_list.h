#include <iostream>
#include <memory.h>
using namespace std;

/*********************************************************************
# structure of an List_Elm of List.
# Users who wants to use the list just care about the DATA of element.
# They have no need to pay their attention on  the pointer to NEXT.
*********************************************************************/
typedef struct list_elm
{
	void*	 pData;
	list_elm* pNext;
	
	list_elm()
	{
		pData = NULL;
		pNext = NULL;
	}
}List_Elm;


class ds_List
{
public:
	ds_List();
	~ds_List();

private:
	int		m_nSize;
	List_Elm* pHead;
	List_Elm* pTail;
public:
	// insert
	int	insert_element(List_Elm* pPrev, void* pData); 
	//int insert_element(int nIndex, List_Elm* pElement);
	//int push_back(List_Elm* pElement);

	// delete return last one
	//List_Elm* delete_element(List_Elm* pIndex);
	//List_Elm* delete_element(int nIndex);
	//List_Elm* delete_rangeof(List_Elm* pStart, List_Elm* pEnd = NULL);

	// Get
	List_Elm* get_head();
	//List_Elm* get_tail();
	
	// show list
	void show_list();

private:
	//int destroy(List_Elm* pElement);

};