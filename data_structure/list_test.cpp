#include "ds_list.h"


int main()
{
	ds_List list;
	int x = 0;
	int ar[] = {0,1,2,3,4,5,6,7,8,9,10};
	List_Elm *pPrev = NULL;

	for(; x<10; x++)
	{
		list.insert_element(list.get_tail(), (void*)(ar+x));
		if (x == 6)
		{
			pPrev = list.get_tail();
		}
	}
	
	list.show_list();
	system("pause");
}