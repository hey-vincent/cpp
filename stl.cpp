#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int>  vec(10,0);
	vec[5] = 1;
	vec[6] = 6;
	vector<int>::iterator search;
	string result = (search=std::find(vec.begin(), vec.end(),1)) == vec.end()? "not found" : "found" ;
	std::cout<< result <<std::endl;
	cout << *(search+1) << endl;
	
	for(int i = 0; i < 10; i++)
	{
		if(i == 5)
			continue;
		cout << i ;
	}
	
	return 0;
}