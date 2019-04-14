#include <iostream>

using namespace std;

template<class T>
void InsertSort(T *list,const int count);


int main()
{
	int a[]={1,3,5,7,9,0,2,4,6,1};
    InsertSort(a,10);
    for(int i=0;i<10;i++)
        cout<< a[i]<<" ";
    cout <<endl;

	system("pause");
	return 0;
}


//--�������� ��������������ѭ������1��ʼ�����ݴ�temp����tempǰ��ıȽϣ���λ����

template<class T>
void InsertSort(T *list,const int count)
{
	int left=0;
	for(int i=1;i<count;i++)
	{
		//��λ��������
		left=i-1;   //ǰһλ����
		T temp=list[i]; //�ݴ�����
		while(left>=0 && list[left]>temp) //��С�������� ��λ����
		{
			list[left+1]=list[left]; //��λ
			left--;
		}
		list[left+1]=temp; //�������� ��Ϊleft--
	}
}

