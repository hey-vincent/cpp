#include <iostream>
#include <memory.h>
using namespace std;


typedef struct _element
{

}Element;


class ds_List
{
public:
	ds_List();
	~ds_List();

private:
	int		m_nSize;
	void	*pData;	
	ds_List *pNext;

public:
	// insert
	int	insert_element(ds_List* pIndex, ds_List& element); 
	int insert_element(int nIndex, ds_List* pElement);
	int push_back(ds_List* pElement);

	// delete return last one
	ds_List* delete_element(ds_List* pIndex);
	ds_List* delete_element(int nIndex);
	ds_List* delete_rangeof(ds_List* pStart, ds_List* pEnd = NULL);

	// Get
	ds_List* get_head();
	ds_List* get_last();

private:
	int destroy(ds_List* pElement);

};