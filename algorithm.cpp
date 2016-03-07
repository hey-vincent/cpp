#include <iostream>
#include <vector>
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


int main()
{
	std::vector< int > vec;
	for(int x = 5;x< 15; x++)
	{
		vec.push_back(x);
	}
	cout << BinarySearch(vec,0, 9,6) << endl;
	return 0;
}
