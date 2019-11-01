#include <iostream>
#include "MergeSortIteration.h"
using namespace std;


template<class T>
void PrintArr(T *arr,int len)
{
	for(int i=0;i<len;i++)
		cout<< arr[i]<<" ";
	cout << endl;
}

int main()
{
	//第一为不用  --猎豹源码
	int arr[]={0,12,4,32,3,5,64,23,1,541,2,6};
	PrintArr(arr,12);
	MergeSort(arr,11);
	PrintArr(arr,12);
	system("pause");
	return 0;
}