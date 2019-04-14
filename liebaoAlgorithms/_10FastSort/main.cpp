#include <iostream>

using namespace std;

//--初始算法-挖坑填数--传智
template<class T>
void FastSort(T *list,const int left,const int right);

//--初始算法-挖坑填数
template<class T>
void FastSort1(T *list,const int left,const int right,bool isAscending);

//--改进的快速排序--猎豹
template<class T>
void  FastSort2(T *list,const int left,const int right);

//--改进算法 加入升降序 isAscending=true 升序
template<class T>
void  FastSort2(T *list,const int left,const int right, bool isAscending);


//--改进算法 加入升降序 isAscending=true 升序 无需多加数据
template<class T>
void  FastSort3(T *list,const int left,const int right, bool isAscending);

//--打印数组
template<class T>
void PrintList(T *list,const int len)
{
	for(int i=0;i<len;i++)
        cout<< list[i]<<" ";
    cout <<endl;
}
int main()
{
#if 1 //测试挖坑填数
	int a[]={1,3,5,7,9,0,2,4,6,8};
	int len = sizeof(a)/sizeof(int);
	cout<<"测试挖坑填数..."<<endl;
	//从小到大
    FastSort(a,0,len-1);
    PrintList(a,len);
	//从大到小
	FastSort1(a,0,len-1,false);
    PrintList(a,len);
#endif

#if 1 //测试改进算法--猎豹
	int m[]={1,3,5,7,9,0,2,4,6,8,99}; //末尾多一位数据，比其他数据大
	int mlen = sizeof(m)/sizeof(int);
	cout<<"测试改进算法--猎豹"<<endl;
	FastSort2(m,0,mlen-2);
	PrintList(m,mlen);
	FastSort2(m,0,mlen-2,false);
	PrintList(m,mlen);

	cout<<"无需多一个数据"<<endl;
	FastSort3(m,0,mlen-1,true); //升序
	PrintList(m,mlen);
	FastSort3(m,0,mlen-1,false); //升序
	PrintList(m,mlen);
#endif
	system("pause");
	return 0;
}


//--初始算法-
//首先对整个序列，i,j分别对应起始和终止位置，基准数为arr[0]=4,挖坑 ，
//依次i--,j--直到i=j,交换（i找大的，j找大的 ），然后再左右递归
template<class T>
void FastSort(T *list,const int left,const int right)
{
	int i=left,j=right;
	//结束条件
	if(i <j)  
	{
		//基准数
		T temp=list[left]; 
		//循环找到第一个中间数 从小到大排列 
		while(i<j) 
		{
			//右到左 直到找小的交换
			while(i<j &&  list[j] >= temp )
			{
				j--;
			}
			//填坑 i指向下一位
			if(i<j)
			{
				list[i]=list[j];
				i++;
			}
			
			//左到右 找大的交换
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
		//基准数归为
		list[j]=temp;
		//递归左边、右边
		FastSort(list,left,i-1);
		FastSort(list,j+1,right);
	}
}

//--初始算法，加入排序
template<class T>
void FastSort1(T *list,const int left,const int right,bool isAscending=true)
{
	int i=left,j=right;
	//结束条件
	if(i <j)  
	{
		//基准数
		T temp=list[left]; 
		//循环找到第一个中间数
		while(i<j) {
			//从大到小
			if(isAscending) 
			{
				//右到左 直到找小的交换
				while(i<j &&  list[j] > temp ){
					j--;
				}
				//填坑 i指向下一位
				if(i<j){
					list[i]=list[j];
					i++;
				}
				//左到右 找大的交换
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
				//从大到小，左边找小的交换，右边找大的
				//右边j--直到找到>temp
				while(i<j && list[j] <= temp){
					j--;
				}
				//找到了 填数据 填入i值，i++
				if(i<j) {
					list[i]=list[j];
					i++;
				}
				//左边i
				while(i<j && list[i]>temp){
					i++;
				}
				if(i<j) {
					list[j]=list[i];
					j--;
				}
			}
			
		}
		//基准数归为
		list[j]=temp;
		//递归左边、右边
		FastSort1(list,left,i-1,isAscending);
		FastSort1(list,j+1,right,isAscending);
	}
}

//--改进的快速排序
/**
思路分析：
从小到大。
首先对整个序列，i,j分别对应起始和终止位置，枢轴为（取左边）picot=arr[0]=4；
循环i++，j--，同时找到i>picot,j<=picot，交换二者的值；一次循环完毕，i=j时，
交换枢轴arr[left]=picot=和j中间值(j处于>=picot的值)，如此保证换一个枢轴，
分两个区间继续递归
*/
template<class T>
void  FastSort2(T *list,const int left,const int right)
{
	if(left<right)
	{
		//选枢轴
		int i=left;
		int j=right+1;	//list最后预留一位不存数据，减少判断次数
		int pivot=list[left];
		do
		{
			//循环，交换
			do i++; while(list[i] < pivot);
			do j--; while(list[j] > pivot);
			if(i<j) swap(list[i],list[j]);
		}while(i<j);
		//将枢轴交换 经过上述循环，i=j，避免递归时重复枢轴
		swap(list[left],list[j]);
		//递归左右半部分
		FastSort2(list,left,j-1);
		FastSort2(list,j+1,right);
	}
}

//--改进算法 加入升降序 isAscending=true 升序
template<class T>
void  FastSort2(T *list,const int left,const int right, bool isAscending)
{
	if(left<right)
	{
		//选枢轴
		int i=left;
		int j=right+1;	//list最后预留一位不存数据，减少判断次数
		int pivot=list[left];
		do{
			//循环，交换升序
			if(isAscending){
				do i++; while(list[i] < pivot);
				do j--; while(list[j] > pivot);
				if(i<j) swap(list[i],list[j]);
			}
			//降序
			else{
				do i++; while(list[i]>pivot);
				do j--; while(list[j]<pivot);
				if(i<j) swap(list[i],list[j]);
			}
		}while(i<j);
		//将枢轴交换 经过上述循环，i=j，避免递归时重复枢轴
		swap(list[left],list[j]);
		//递归左右半部分
		FastSort2(list,left,j-1,isAscending);
		FastSort2(list,j+1,isAscending);
	}
}


//--改进算法 加入升降序 isAscending=true 升序 无需多加数据
template<class T>
void  FastSort3(T *list,const int left,const int right, bool isAscending)
{
	if(left<right)
	{
		//选枢轴
		int i=left;
		int j=right;	//list最后预留一位不存数据
		int pivot=list[left];
		do{
			//循环，交换升序
			if(isAscending){
				do i++; while(list[i] < pivot);
				while(list[j] > pivot) j--;
				//do j--; while(list[j] > pivot);
				if(i<j) swap(list[i],list[j]);
			}
			//降序
			else{
				do i++; while(list[i]>pivot);
				//do j--; while(list[j]<pivot);
				while(list[j] < pivot) j--;
				if(i<j) swap(list[i],list[j]);
			}
		}while(i<j);
		//将枢轴交换 经过上述循环，i=j，避免递归时重复枢轴
		swap(list[left],list[j]);
		//递归左右半部分
		FastSort2(list,left,j-1,isAscending);
		FastSort2(list,j+1,isAscending);
	}
}