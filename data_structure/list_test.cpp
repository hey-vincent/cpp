#include "Chain.h"


int main()
{
	Chain list;
	int x = 0;
	int ar[] = {0,1,2,3,4,5,6,7,8,9,10};
	Node *pPrev = NULL;

	for(; x<10; x++)
	{
		list.insert(list.tail(), (void*)&(ar[x]));

		if (x == 6)
		{
			pPrev = list.tail();
		}
	}
	list.remove(pPrev);
	list.show_list();
	system("pause");
}