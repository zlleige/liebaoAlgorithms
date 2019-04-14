#include <iostream>
using namespace std;
int BinarySearch_Recursion(int *list,const int l,const int r,const int data);
int BinarySearch(int *list,const int count,const int data);
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    cout<<"递归"<<endl;
    cout<<BinarySearch_Recursion(a,0,9,5)<<endl;
	cout<<BinarySearch_Recursion(a,0,9,35)<<endl;
	cout<<"迭代"<<endl;
	cout<<BinarySearch(a,10,5)<<endl;
	cout<<BinarySearch(a,10,35)<<endl;
	system("pause");
    return 0;
}

//递归二分查找
int BinarySearch_Recursion(int *list,const int l,const int r,const int data){
	
	if(l<=r) 
	{
		int m=(l+r)/2;
	if(list[m]==data) return m;
	else if(list[m]>data)
		return BinarySearch_Recursion(list,l,m-1,data);
	else
		return BinarySearch_Recursion(list,m+1,r,data);
	}
	else return -1;
}
//迭代 从小到大
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