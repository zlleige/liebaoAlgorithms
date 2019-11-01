#ifndef _MERGRSORT_H
#define _MERGRSORT_H

#include <iostream>

/*
@para:arr:待排序数据
@para:start:起点
@para:end:终点
@para:mid:分界
@para:isAscending:是否升序
*/	
template<class T>
void Merge(T *arr,int start,int end,int mid,bool isAscending)
{
	//临时空间，用于保存数据
	T *temp=new T[end-start+1];
	//分组 左右两组数据
	int l_start=start; 
	int l_end=mid;
	int r_start=mid+1;
	int r_end=end; 
	int len=0; //记录临时数组的数据
	//轮循两组数据
	while(l_start <= l_end && r_start <= r_end) 
	{
		if(isAscending) //升序
		{
			if(arr[l_start] < arr[r_start])
				temp[len++]=arr[l_start++];
			else 
				temp[len++]=arr[r_start++];
		}
		else
		{
			if(arr[l_start] < arr[r_start])
				temp[len++]=arr[r_start++];
			else 
				temp[len++]=arr[l_start++];
		}
	}
	//残余数据 添加
	while(l_start<=l_end)
	{
		temp[len++]=arr[l_start++];
	}
	while(r_start<=r_end)
	{
		temp[len++]=arr[r_start++];
	}

	//覆盖
	for(int i=0;i<len;i++)
	{
		arr[start+i]=temp[i];
	}

	//释放
	delete[] temp;
}


/*
@para:arr:待排序数据
@para:start:起点
@para:end:终点
@para:isAscending:是否升序
*/	
template<class T>
void MergeSort(T *arr,int start,int end,bool isAscending=true)
{
	//结束条件，不能分组时
	if(start >= end) return;
	//分组递归
	int mid=(start+end)/2;
	MergeSort(arr,start,mid,isAscending); //左
	MergeSort(arr,mid+1,end,isAscending); //右边
	Merge(arr,start,end,mid,isAscending); //排序 将分组依次比较，覆盖arr，得到有序序列
}
#endif

