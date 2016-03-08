#include <iostream>
using namespace std;

#ifndef null
#define null 0
#endif

/***************************************************************/
// Some common or useful functions
/***************************************************************/

//show elements from a sequence
template<typename T>
void show_elements(T* pStart, int nLen)
{
	for(int x = 0; x < nLen && (pStart+x) != null; x++)
	{
		cout<< *(pStart + x) << '\t' ;
	}
	cout << endl;
}

// swap two objects as a given comparation 
template<typename T>
void swap_if(T *a, T *b, bool lower)
{
	if ((lower && *a < *b) || (!lower && *a > *b))
	{
		int trans = *a;
		*a = *b;
		*b = trans;
	}
	
}