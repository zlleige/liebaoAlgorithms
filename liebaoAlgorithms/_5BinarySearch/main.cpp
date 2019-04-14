#include <iostream>
using namespace std;
int BinarySearch(int *list,const int count,const int data);
int main()
{
   int a[]={1,2,3,4,5,6,7,8,9,10};
    
    cout<<BinarySearch(a,10,5)<<endl;
	cout<<BinarySearch(a,10,35)<<endl;
	system("pause");
    return 0;
}

//从小到大
int BinarySearch(int *list,const int count,const int data)
{
    int l=0;
    int r=count-1;
    int m=0;
    while(l<=r)
    {
		m=(l+r)/2;
        if(list[m]== data) return m;
        else if(list[m]>data) r=m-1;
        else l=m+1;
    }
	return -1;
}