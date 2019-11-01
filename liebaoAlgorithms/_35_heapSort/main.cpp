#include <iostream>

#include "HeapSortRecursion.hpp"
#include "Heap.hpp"
using namespace std;

/**
堆排序：递归方式
1.有数组初始化堆
数组表示为完成二叉树，再由最后非叶子节点（len/2-1）向上调整，交换父子节点数据
2.堆首尾依次交换（len-1  i--）交换,再调用调整函数

**/


template<class T>
void PrintData(T *data,const int len)
{
	for(int i=0;i<len;i++)
	{
		cout<< data[i]<<" ";
	}
	cout<<endl;
}

#if 0  //写到头文件 heepSortRecursion.hpp

/*调整二叉树节点位置
@para data:待调整数组 二叉树为大顶
@para index: 调整的数据下标
@para len :当前二叉树的长度 用于判断左右子树是否存在
**/
template<class T>
void HeapAdjust(T *data,const int index,const int len,bool isAscending=true)
{
	int max=index; //记录当前的索引
	int lChild=2*index+1; //左子树
	int rChild=2*index+2;
	if(isAscending)
	{
		//找最大
		if(lChild<len && data[max]<data[lChild]) max=lChild;
		if(rChild<len && data[max]<data[rChild]) max=rChild;
	}
	else
	{
		//找最小
		if(lChild<len && data[max]>data[lChild]) max=lChild;
		if(rChild<len && data[max]>data[rChild]) max=rChild;

	}
	if(max!=index) 
	{
		swap(data[index],data[max]);
		//注意  可能当前与max=交换的值有可能小于左右节点，故需要递归
		HeapAdjust(data,max,len,isAscending);
	}
}

template<class T>
void HeapSort(T *data,const int len,bool isAscending=true)
{
	//初始化堆--效果所有父节点都比子节点大
	for(int i=len/2-1;i>=0;i--)
	{
		//调整数据
		HeapAdjust(data,i,len,isAscending);

	}
	//排序 交换堆顶 对尾交换堆顶（for(i=len-1  ;i--)） ，变化过程会一直递归
	for(int j=len-1;j>=0;j--)
	{
		swap(data[0],data[j]);
		HeapAdjust(data,0,j,isAscending);
	}
	
}
#endif 

int main()
{

#if 0 //测试传智
	int arr[]={4,2,8,0,5,7,1,3,9};
	int len=sizeof(arr)/sizeof(int);
	HeapSort(arr,len,false);
	//打印
	PrintData(arr,len);

#endif


#if 1 //测试猎豹堆
	MyHeap<int> heap1(100);
	cout<<"是否为空："<<heap1.IsEmpty()<<endl;
	heap1.Push(1);
	heap1.Push(5);
	heap1.Push(2);
	heap1.Push(7);
	heap1.Push(3);
	heap1.Push(6);
	heap1.Push(4);
	cout<<"MAX："<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"删除后："<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"删除后："<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"删除后："<<heap1.Top()<<endl;
#endif


#if 1 //猎豹堆排序 思路：把数据加入堆，然后再弹出
	MyHeap<int> heap2(100);
	int arr[] ={1,2,3,9,7,5,3,63,1,35,34,6};
	int len = sizeof(arr)/sizeof(int);
	for(int i=0;i<len;i++) //加入堆
	{
		heap2.Push(arr[i]);
	}
	for(int i=0;i<len;i++) //加入堆
	{
		arr[i]=heap2.Top();
		heap2.Pop();
	}
	PrintData(arr,len);
	cout<<endl;
#endif
	system("pause");
	return 0;
}