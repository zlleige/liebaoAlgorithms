#include <iostream>
using namespace std;
void BubbleSort(int list[],int n);
void Swap(int &a,int &b);
int main()
{
    int a[]={3,46,23,24,5,2,3,4,8};
    BubbleSort(a,9);
    for(int i=0;i<9;i++)
        cout<< a[i]<<" ";
    cout <<endl;
	system("pause");
    return 0;
}
//��������̫��
void BubbleSort(int list[],const int n)
{
    for(int i=0;i<n-1;i++)  { //9��ѭ��
        for(int j=0;j<n-1-i;j++) {
            //if(list[j]>list[j+1]) {  //��С����  ����
				if(list[j]<list[j+1]) {  //�ɴ�С  ����
                Swap(list[j],list[j+1]);
                //std::swap(list[j],list[j+1]);
            }
        }
    }
}

void Swap(int &a,int &b){
    int temp=0;
    temp=a;
    a=b;
    b=temp;
}