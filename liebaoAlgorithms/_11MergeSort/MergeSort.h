#ifndef _MERGRSORT_H
#define _MERGRSORT_H

#include <iostream>

/*
@para:arr:����������
@para:start:���
@para:end:�յ�
@para:mid:�ֽ�
@para:isAscending:�Ƿ�����
*/	
template<class T>
void Merge(T *arr,int start,int end,int mid,bool isAscending)
{
	//��ʱ�ռ䣬���ڱ�������
	T *temp=new T[end-start+1];
	//���� ������������
	int l_start=start; 
	int l_end=mid;
	int r_start=mid+1;
	int r_end=end; 
	int len=0; //��¼��ʱ���������
	//��ѭ��������
	while(l_start <= l_end && r_start <= r_end) 
	{
		if(isAscending) //����
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
	//�������� ���
	while(l_start<=l_end)
	{
		temp[len++]=arr[l_start++];
	}
	while(r_start<=r_end)
	{
		temp[len++]=arr[r_start++];
	}

	//����
	for(int i=0;i<len;i++)
	{
		arr[start+i]=temp[i];
	}

	//�ͷ�
	delete[] temp;
}


/*
@para:arr:����������
@para:start:���
@para:end:�յ�
@para:isAscending:�Ƿ�����
*/	
template<class T>
void MergeSort(T *arr,int start,int end,bool isAscending=true)
{
	//�������������ܷ���ʱ
	if(start >= end) return;
	//����ݹ�
	int mid=(start+end)/2;
	MergeSort(arr,start,mid,isAscending); //��
	MergeSort(arr,mid+1,end,isAscending); //�ұ�
	Merge(arr,start,end,mid,isAscending); //���� ���������αȽϣ�����arr���õ���������
}
#endif

