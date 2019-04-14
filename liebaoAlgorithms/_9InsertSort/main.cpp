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


//--插入排序 分析：从左至右循环（从1开始），暂存temp，和temp前面的比较，移位操作

template<class T>
void InsertSort(T *list,const int count)
{
	int left=0;
	for(int i=1;i<count;i++)
	{
		//移位插入数据
		left=i-1;   //前一位数据
		T temp=list[i]; //暂存数据
		while(left>=0 && list[left]>temp) //由小到大排列 移位操作
		{
			list[left+1]=list[left]; //移位
			left--;
		}
		list[left+1]=temp; //插入数据 因为left--
	}
}

