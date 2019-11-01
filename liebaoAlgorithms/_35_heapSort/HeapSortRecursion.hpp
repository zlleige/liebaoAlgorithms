#ifndef _HEAPSORTRECURSION_H
#define _HEAPSORTRECURSION_H
#include <iostream>

/**
�����򣺵ݹ鷽ʽ
1.�������ʼ����
�����ʾΪ��ɶ���������������Ҷ�ӽڵ㣨len/2-1�����ϵ������������ӽڵ�����
2.����β���ν�����len-1  i--������,�ٵ��õ�������
**/


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
	if(max!=index) //max��¼�������ӽڵ������
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
	for(int i=len/2-1;i>=0;i--) //�����ķ�Ҷ�ӽڵ㿪ʼ
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