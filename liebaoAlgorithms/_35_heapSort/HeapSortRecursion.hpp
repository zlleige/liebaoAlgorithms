#ifndef _HEAPSORTRECURSION_H
#define _HEAPSORTRECURSION_H
#include <iostream>

/**
堆排序：递归方式
1.有数组初始化堆
数组表示为完成二叉树，再由最后非叶子节点（len/2-1）向上调整，交换父子节点数据
2.堆首尾依次交换（len-1  i--）交换,再调用调整函数
**/


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
	if(max!=index) //max记录了左右子节点的索引
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
	for(int i=len/2-1;i>=0;i--) //从最后的非叶子节点开始
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