#include <iostream>

using namespace std;

//--��ʼ�㷨-�ڿ�����--����
template<class T>
void FastSort(T *list,const int left,const int right);

//--��ʼ�㷨-�ڿ�����
template<class T>
void FastSort1(T *list,const int left,const int right,bool isAscending);

//--�Ľ��Ŀ�������--�Ա�
template<class T>
void  FastSort2(T *list,const int left,const int right);

//--�Ľ��㷨 ���������� isAscending=true ����
template<class T>
void  FastSort2(T *list,const int left,const int right, bool isAscending);


//--�Ľ��㷨 ���������� isAscending=true ���� ����������
template<class T>
void  FastSort3(T *list,const int left,const int right, bool isAscending);

//--��ӡ����
template<class T>
void PrintList(T *list,const int len)
{
	for(int i=0;i<len;i++)
        cout<< list[i]<<" ";
    cout <<endl;
}
int main()
{
#if 1 //�����ڿ�����
	int a[]={1,3,5,7,9,0,2,4,6,8};
	int len = sizeof(a)/sizeof(int);
	cout<<"�����ڿ�����..."<<endl;
	//��С����
    FastSort(a,0,len-1);
    PrintList(a,len);
	//�Ӵ�С
	FastSort1(a,0,len-1,false);
    PrintList(a,len);
#endif

#if 1 //���ԸĽ��㷨--�Ա�
	int m[]={1,3,5,7,9,0,2,4,6,8,99}; //ĩβ��һλ���ݣ����������ݴ�
	int mlen = sizeof(m)/sizeof(int);
	cout<<"���ԸĽ��㷨--�Ա�"<<endl;
	FastSort2(m,0,mlen-2);
	PrintList(m,mlen);
	FastSort2(m,0,mlen-2,false);
	PrintList(m,mlen);

	cout<<"�����һ������"<<endl;
	FastSort3(m,0,mlen-1,true); //����
	PrintList(m,mlen);
	FastSort3(m,0,mlen-1,false); //����
	PrintList(m,mlen);
#endif
	system("pause");
	return 0;
}


//--��ʼ�㷨-
//���ȶ��������У�i,j�ֱ��Ӧ��ʼ����ֹλ�ã���׼��Ϊarr[0]=4,�ڿ� ��
//����i--,j--ֱ��i=j,������i�Ҵ�ģ�j�Ҵ�� ����Ȼ�������ҵݹ�
template<class T>
void FastSort(T *list,const int left,const int right)
{
	int i=left,j=right;
	//��������
	if(i <j)  
	{
		//��׼��
		T temp=list[left]; 
		//ѭ���ҵ���һ���м��� ��С�������� 
		while(i<j) 
		{
			//�ҵ��� ֱ����С�Ľ���
			while(i<j &&  list[j] >= temp )
			{
				j--;
			}
			//��� iָ����һλ
			if(i<j)
			{
				list[i]=list[j];
				i++;
			}
			
			//���� �Ҵ�Ľ���
			while(i<j && list[i]<temp)
			{
				i++;
			}
			if(i<j)
			{
				list[j]=list[i];
				j--;
			}
		}
		//��׼����Ϊ
		list[j]=temp;
		//�ݹ���ߡ��ұ�
		FastSort(list,left,i-1);
		FastSort(list,j+1,right);
	}
}

//--��ʼ�㷨����������
template<class T>
void FastSort1(T *list,const int left,const int right,bool isAscending=true)
{
	int i=left,j=right;
	//��������
	if(i <j)  
	{
		//��׼��
		T temp=list[left]; 
		//ѭ���ҵ���һ���м���
		while(i<j) {
			//�Ӵ�С
			if(isAscending) 
			{
				//�ҵ��� ֱ����С�Ľ���
				while(i<j &&  list[j] > temp ){
					j--;
				}
				//��� iָ����һλ
				if(i<j){
					list[i]=list[j];
					i++;
				}
				//���� �Ҵ�Ľ���
				while(i<j && list[i]<temp){
					i++;
				}
				if(i<j){
					list[j]=list[i];
					j--;
				}
			}
			else 
			{
				//�Ӵ�С�������С�Ľ������ұ��Ҵ��
				//�ұ�j--ֱ���ҵ�>temp
				while(i<j && list[j] <= temp){
					j--;
				}
				//�ҵ��� ������ ����iֵ��i++
				if(i<j) {
					list[i]=list[j];
					i++;
				}
				//���i
				while(i<j && list[i]>temp){
					i++;
				}
				if(i<j) {
					list[j]=list[i];
					j--;
				}
			}
			
		}
		//��׼����Ϊ
		list[j]=temp;
		//�ݹ���ߡ��ұ�
		FastSort1(list,left,i-1,isAscending);
		FastSort1(list,j+1,right,isAscending);
	}
}

//--�Ľ��Ŀ�������
/**
˼·������
��С����
���ȶ��������У�i,j�ֱ��Ӧ��ʼ����ֹλ�ã�����Ϊ��ȡ��ߣ�picot=arr[0]=4��
ѭ��i++��j--��ͬʱ�ҵ�i>picot,j<=picot���������ߵ�ֵ��һ��ѭ����ϣ�i=jʱ��
��������arr[left]=picot=��j�м�ֵ(j����>=picot��ֵ)����˱�֤��һ�����ᣬ
��������������ݹ�
*/
template<class T>
void  FastSort2(T *list,const int left,const int right)
{
	if(left<right)
	{
		//ѡ����
		int i=left;
		int j=right+1;	//list���Ԥ��һλ�������ݣ������жϴ���
		int pivot=list[left];
		do
		{
			//ѭ��������
			do i++; while(list[i] < pivot);
			do j--; while(list[j] > pivot);
			if(i<j) swap(list[i],list[j]);
		}while(i<j);
		//�����ύ�� ��������ѭ����i=j������ݹ�ʱ�ظ�����
		swap(list[left],list[j]);
		//�ݹ����Ұ벿��
		FastSort2(list,left,j-1);
		FastSort2(list,j+1,right);
	}
}

//--�Ľ��㷨 ���������� isAscending=true ����
template<class T>
void  FastSort2(T *list,const int left,const int right, bool isAscending)
{
	if(left<right)
	{
		//ѡ����
		int i=left;
		int j=right+1;	//list���Ԥ��һλ�������ݣ������жϴ���
		int pivot=list[left];
		do{
			//ѭ������������
			if(isAscending){
				do i++; while(list[i] < pivot);
				do j--; while(list[j] > pivot);
				if(i<j) swap(list[i],list[j]);
			}
			//����
			else{
				do i++; while(list[i]>pivot);
				do j--; while(list[j]<pivot);
				if(i<j) swap(list[i],list[j]);
			}
		}while(i<j);
		//�����ύ�� ��������ѭ����i=j������ݹ�ʱ�ظ�����
		swap(list[left],list[j]);
		//�ݹ����Ұ벿��
		FastSort2(list,left,j-1,isAscending);
		FastSort2(list,j+1,isAscending);
	}
}


//--�Ľ��㷨 ���������� isAscending=true ���� ����������
template<class T>
void  FastSort3(T *list,const int left,const int right, bool isAscending)
{
	if(left<right)
	{
		//ѡ����
		int i=left;
		int j=right;	//list���Ԥ��һλ��������
		int pivot=list[left];
		do{
			//ѭ������������
			if(isAscending){
				do i++; while(list[i] < pivot);
				while(list[j] > pivot) j--;
				//do j--; while(list[j] > pivot);
				if(i<j) swap(list[i],list[j]);
			}
			//����
			else{
				do i++; while(list[i]>pivot);
				//do j--; while(list[j]<pivot);
				while(list[j] < pivot) j--;
				if(i<j) swap(list[i],list[j]);
			}
		}while(i<j);
		//�����ύ�� ��������ѭ����i=j������ݹ�ʱ�ظ�����
		swap(list[left],list[j]);
		//�ݹ����Ұ벿��
		FastSort2(list,left,j-1,isAscending);
		FastSort2(list,j+1,isAscending);
	}
}