#include <iostream>
using namespace std;

void SelectSort(int *list,const int n);
int main()
{
    int a[]={1,3,5,7,9,0,2,4,6,8};
    SelectSort(a,10);
    for(int i=0;i<10;i++)
        cout<< a[i]<<" ";
    cout <<endl;
	system("pause");
	return 0;
}

//n-1��ɨ��,ÿ��ɨ��ֻ�Ǽ�¼��־�������ݷŵ������,��ʼֵΪi+1,��ֵֹΪn
//void SelectSort(int list[],const int n)
void SelectSort(int *list,const int n)
{
	for(int i=0;i<n-1;i++) //n��ɨ�� 
	{
		int min=i; //����Сindex
		for(int j=i+1;j<n;j++)   
		{
			//if(list[j]<list[min]) min=j; //��С����
			if(list[j]>list[min]) min=j; //
		}
		if(min!=i) std::swap(list[i],list[min]);
	}
}