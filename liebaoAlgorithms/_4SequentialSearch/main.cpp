#include <iostream>

using namespace std;
int SequentialSearch(int *a,const int length,const int data);
int main()
{
	int a[]={1,3,5,7,9,0,2,4,6,8};
    
    cout<<SequentialSearch(a,10,5);
	system("pause");
	return 0;
}

int SequentialSearch(int *a,const int length,const int data)
{
	int res=-1;
	for(int i=0;i<length;i++)
	{
		if(a[i]==data) res=i;
	}
	return res;
}