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

//n-1此扫描,每次扫描只是记录标志，把数据放到最左边,起始值为i+1,终止值为n
//void SelectSort(int list[],const int n)
void SelectSort(int *list,const int n)
{
	for(int i=0;i<n-1;i++) //n此扫描 
	{
		int min=i; //存最小index
		for(int j=i+1;j<n;j++)   
		{
			//if(list[j]<list[min]) min=j; //从小到大
			if(list[j]>list[min]) min=j; //
		}
		if(min!=i) std::swap(list[i],list[min]);
	}
}