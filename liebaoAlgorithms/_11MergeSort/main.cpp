#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MergeSort2Recursion.h"

//产生随机数
#define MAX 10
#include <time.h>
#include <sys/timeb.h>

using namespace std;

long getSysTime()
{
	struct timeb tb;
	ftime(&tb);
	return (long)(tb.time*1000+tb.millitm);
}

//创建随机数组
int* GreateArray()
{
	srand((unsigned int)time(NULL));
	int* arr = new int[sizeof(int)*MAX];
	for(int i=0;i<MAX;i++)
		arr[i]=rand() & MAX;
	return arr;
}

template<class T>
void PrintArr(T *arr,int len)
{
	for(int i=0;i<len;i++)
		cout<< arr[i]<<" ";
	cout << endl;
}


int main()
{
	
	int* arr=GreateArray();
	int* temp=new int[MAX];
	PrintArr(arr,MAX);

	MergeSort(arr,0,MAX-1);
	PrintArr(arr,MAX);
	MergeSort(arr,0,MAX-1,false);
	PrintArr(arr,MAX);

	int arr1[]={43,2,5,6,3,9,56,4};
	PrintArr(arr1,8);
	MergeSort(arr1,0,8-1);
	PrintArr(arr1,8);
	MergeSort(arr1,0,8-1,false);
	PrintArr(arr1,8);

	delete[] arr;
	delete[] temp;
	system("pause");
	return 0;
}