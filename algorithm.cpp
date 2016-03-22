#include <iostream>
#include <vector>
#include "common.h"
using namespace std;


//:search -- binary_search
int BinarySearch(vector<int>& vec,int start, int deadline, int target)
{
    if(vec.size() == 0 || start > deadline)
    {
		return -1;	
    }
	
	int index = (start + deadline) / 2;
	cout << index ;
	int mid   = vec.at(index);
	cout << '\t' << mid << endl;

	if(mid == target)
	{
		return index;
	}
	else if (mid > target)
	{
		return BinarySearch(vec, start, index-1, target);
	}
	else
	{
		return BinarySearch(vec, index+1, deadline, target);
	}
}



//:sort -- Inserting sort

void insert_sort(int *arr, int len)
{
	show_elements<int>(arr,len);
	for(int x = 0; x < len; x++)
	{
		for(int y = 0; y < x; y++)
		{
			swap_if<int>(arr + x, arr + y,true);
		}
	}
}



int main()
{
	std::vector< int > vec;
	for(int x = 5;x< 15; x++)
	{
		vec.push_back(x);
	}
	cout << BinarySearch(vec,0, 9,6) << endl;


	int arr[10] = {9,8,7,10,2,4,6,1,3,5};
	insert_sort(arr, 10);
	show_elements<int>(arr,10);
	return 0;
}
