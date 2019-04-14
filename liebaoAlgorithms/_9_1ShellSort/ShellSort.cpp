#include <iostream>

#include <sys/timeb.h>
#include <time.h>

#define MAX 50000

long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return (long)(tb.time*1000+tb.millitm);
}
using namespace std;

//--��ʼ�㷨-�ڿ�����--����
template<class T>
void FastSort(T *list,const int left,const int right);

//--��ʼ�㷨-�ڿ�����
template<class T>
void FastSort1(T *list,const int left,const int right,bool isAscending);

//--ϣ������
template<class T>
void ShellSort(T *list,const int len);

//--ϣ������-isAscending=TRUE ����
template<class T>
void ShellSort(T *list,const int len, bool isAscending);

//--�������� ��������������ѭ������1��ʼ�����ݴ�temp����tempǰ��ıȽϣ���λ����
template<class T>
void InsertSort(T *list,const int count);

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
	ShellSort(a,len);
    PrintList(a,len);  //����
	ShellSort(a,len,false); //����
    PrintList(a,len);
#endif

	//�����������
	int arr[MAX]={0};
	srand((unsigned int)time(NULL));
	for(int i=0;i<MAX;i++)
	{
		int randNum=rand() % MAX;
		arr[i]=randNum;
	}
	cout<<"��������ɡ�����"<<endl;
	//PrintList(arr,MAX);

	//ShellSort(arr,MAX);
    //PrintList(arr,MAX);  //����
	//ShellSort(arr,MAX,false); //����
    //PrintList(arr,MAX);

	long tshell_s=getSystemTime();
	ShellSort(arr,MAX);
	long tshell_e=getSystemTime();
	cout<<"ϣ������"<<MAX<<"����Ҫʱ�䣺"<<tshell_e-tshell_s <<"ms"<<endl;

	//���ɲ�����������
	srand((unsigned int)time(NULL));
	for(int i=0;i<MAX;i++)
	{
		int randNum=rand() % MAX;
		arr[i]=randNum;
	}
	long tInsert_s=getSystemTime();
	InsertSort(arr,MAX);
	long tInser_e=getSystemTime();
	cout<<"��������"<<MAX<<"����Ҫʱ�䣺"<<tInser_e-tInsert_s <<"ms"<<endl;

	system("pause");
	return 0;
}

//--ϣ������-��С����
template<class T>
void ShellSort(T *list,const int len)
{
	//������
	int increasement=len;
	do{
		increasement=increasement/3+1;
		//ѭ���Ը�������м��β�������
		for(int j=0;j<increasement;j++)
		{
			//��������--ѭ���������ݣ����뵽ǰ�������
			int left=0;  //������֮ǰ������λ��
			for(int i=j+increasement;i<len;i+=increasement) //i=increasemen �ڶ�������ʼ��
			{
				//�����ǰ�Ķ���
				left=i-increasement; 
				T temp=list[i]; //��ǵ�ǰ����������
				while(left>=0 && list[left]>temp) //�ƶ�
				{
					list[left+increasement]=list[left];
					left-=increasement; //left��ʼΪ1ʱ��ֻ�ƶ�һλ��֮��left=0��left>0���������Ƴ�
				}
				//�ж��Ƿ��ƶ������� �ƶ�֮����Ҫ�����ݲ���
				if(left<i) list[left+increasement]=temp;
			}
		}
	}while(increasement>1); //=1ʱ�˳� ��һ��increasement/3+1; �ڶ��α�Ϊ1��������룩 �ܹ���ִ������
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
//--ϣ������-isAscending=TRUE ����
template<class T>
void ShellSort(T *list,const int len, bool isAscending)
{
	//������
	int increasement=len;
	//ѭ��2�β�������
	do{
		increasement=increasement/3+1;
		//��������--ѭ���������ݣ����뵽ǰ�������
		int left=0;  //������֮ǰ������λ��
		//ѭ���Ը�������м��β�������
		for(int j=0;j<increasement;j++)
		{
			for(int i=2*increasement;i<len;i+=increasement)//i=2*increasemen �ڶ�������ʼ��
			{
				//�����ǰ�Ķ���
				left=i; 
				T temp=list[left]; //��ǵ�ǰ����������
				if(isAscending)
				{
					while(left>0 && list[left-increasement]>temp) //�ƶ�
					{
						list[left]=list[left-increasement];
						left-=increasement; //left��ʼΪ1ʱ��ֻ�ƶ�һλ��֮��left=0��left>0���������Ƴ�
					}
				}
				else{
					while(left>0 && list[left-increasement]<temp) //�ƶ�
					{
						list[left]=list[left-increasement];
						left-=increasement; //left��ʼΪ1ʱ��ֻ�ƶ�һλ��֮��left=0��left>0���������Ƴ�
					}
				}
				//�ж��Ƿ��ƶ������� �ƶ�֮����Ҫ�����ݲ���
				if(left<i) list[left]=temp;
			}
		}
	}while(increasement>1); ////=1ʱ�˳� ��һ��increasement/3+1; �ڶ��α�Ϊ1��������룩 �ܹ���ִ������
}