#include <iostream>

#include "HeapSortRecursion.hpp"
#include "Heap.hpp"
using namespace std;

/**
�����򣺵ݹ鷽ʽ
1.�������ʼ����
�����ʾΪ��ɶ���������������Ҷ�ӽڵ㣨len/2-1�����ϵ������������ӽڵ�����
2.����β���ν�����len-1  i--������,�ٵ��õ�������

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

#if 0  //д��ͷ�ļ� heepSortRecursion.hpp

/*�����������ڵ�λ��
@para data:���������� ������Ϊ��
@para index: �����������±�
@para len :��ǰ�������ĳ��� �����ж����������Ƿ����
**/
template<class T>
void HeapAdjust(T *data,const int index,const int len,bool isAscending=true)
{
	int max=index; //��¼��ǰ������
	int lChild=2*index+1; //������
	int rChild=2*index+2;
	if(isAscending)
	{
		//�����
		if(lChild<len && data[max]<data[lChild]) max=lChild;
		if(rChild<len && data[max]<data[rChild]) max=rChild;
	}
	else
	{
		//����С
		if(lChild<len && data[max]>data[lChild]) max=lChild;
		if(rChild<len && data[max]>data[rChild]) max=rChild;

	}
	if(max!=index) 
	{
		swap(data[index],data[max]);
		//ע��  ���ܵ�ǰ��max=������ֵ�п���С�����ҽڵ㣬����Ҫ�ݹ�
		HeapAdjust(data,max,len,isAscending);
	}
}

template<class T>
void HeapSort(T *data,const int len,bool isAscending=true)
{
	//��ʼ����--Ч�����и��ڵ㶼���ӽڵ��
	for(int i=len/2-1;i>=0;i--)
	{
		//��������
		HeapAdjust(data,i,len,isAscending);

	}
	//���� �����Ѷ� ��β�����Ѷ���for(i=len-1  ;i--)�� ���仯���̻�һֱ�ݹ�
	for(int j=len-1;j>=0;j--)
	{
		swap(data[0],data[j]);
		HeapAdjust(data,0,j,isAscending);
	}
	
}
#endif 

int main()
{

#if 0 //���Դ���
	int arr[]={4,2,8,0,5,7,1,3,9};
	int len=sizeof(arr)/sizeof(int);
	HeapSort(arr,len,false);
	//��ӡ
	PrintData(arr,len);

#endif


#if 1 //�����Ա���
	MyHeap<int> heap1(100);
	cout<<"�Ƿ�Ϊ�գ�"<<heap1.IsEmpty()<<endl;
	heap1.Push(1);
	heap1.Push(5);
	heap1.Push(2);
	heap1.Push(7);
	heap1.Push(3);
	heap1.Push(6);
	heap1.Push(4);
	cout<<"MAX��"<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"ɾ����"<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"ɾ����"<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"ɾ����"<<heap1.Top()<<endl;
#endif


#if 1 //�Ա������� ˼·�������ݼ���ѣ�Ȼ���ٵ���
	MyHeap<int> heap2(100);
	int arr[] ={1,2,3,9,7,5,3,63,1,35,34,6};
	int len = sizeof(arr)/sizeof(int);
	for(int i=0;i<len;i++) //�����
	{
		heap2.Push(arr[i]);
	}
	for(int i=0;i<len;i++) //�����
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