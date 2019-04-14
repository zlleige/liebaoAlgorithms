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

//--初始算法-挖坑填数--传智
template<class T>
void FastSort(T *list,const int left,const int right);

//--初始算法-挖坑填数
template<class T>
void FastSort1(T *list,const int left,const int right,bool isAscending);

//--希尔排序
template<class T>
void ShellSort(T *list,const int len);

//--希尔排序-isAscending=TRUE 升序
template<class T>
void ShellSort(T *list,const int len, bool isAscending);

//--插入排序 分析：从左至右循环（从1开始），暂存temp，和temp前面的比较，移位操作
template<class T>
void InsertSort(T *list,const int count);

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
	ShellSort(a,len);
    PrintList(a,len);  //升序
	ShellSort(a,len,false); //降序
    PrintList(a,len);
#endif

	//生成随机数组
	int arr[MAX]={0};
	srand((unsigned int)time(NULL));
	for(int i=0;i<MAX;i++)
	{
		int randNum=rand() % MAX;
		arr[i]=randNum;
	}
	cout<<"随机数生成。。。"<<endl;
	//PrintList(arr,MAX);

	//ShellSort(arr,MAX);
    //PrintList(arr,MAX);  //升序
	//ShellSort(arr,MAX,false); //降序
    //PrintList(arr,MAX);

	long tshell_s=getSystemTime();
	ShellSort(arr,MAX);
	long tshell_e=getSystemTime();
	cout<<"希尔排序"<<MAX<<"个需要时间："<<tshell_e-tshell_s <<"ms"<<endl;

	//生成插入排序数据
	srand((unsigned int)time(NULL));
	for(int i=0;i<MAX;i++)
	{
		int randNum=rand() % MAX;
		arr[i]=randNum;
	}
	long tInsert_s=getSystemTime();
	InsertSort(arr,MAX);
	long tInser_e=getSystemTime();
	cout<<"插入排序"<<MAX<<"个需要时间："<<tInser_e-tInsert_s <<"ms"<<endl;

	system("pause");
	return 0;
}

//--希尔排序-从小到大
template<class T>
void ShellSort(T *list,const int len)
{
	//分组数
	int increasement=len;
	do{
		increasement=increasement/3+1;
		//循环对各个组进行几次插入排序
		for(int j=0;j<increasement;j++)
		{
			//插入排序--循环所有数据，插入到前面的数据
			int left=0;  //待插入之前的数据位置
			for(int i=j+increasement;i<len;i+=increasement) //i=increasemen 第二个数开始查
			{
				//插入此前的队列
				left=i-increasement; 
				T temp=list[i]; //标记当前待插入数据
				while(left>=0 && list[left]>temp) //移动
				{
					list[left+increasement]=list[left];
					left-=increasement; //left初始为1时，只移动一位，之后left=0，left>0的条件继推出
				}
				//判断是否移动了数据 移动之后，需要将数据插入
				if(left<i) list[left+increasement]=temp;
			}
		}
	}while(increasement>1); //=1时退出 第一次increasement/3+1; 第二次必为1（整体插入） 总共会执行两次
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
//--希尔排序-isAscending=TRUE 升序
template<class T>
void ShellSort(T *list,const int len, bool isAscending)
{
	//分组数
	int increasement=len;
	//循环2次插入排序
	do{
		increasement=increasement/3+1;
		//插入排序--循环所有数据，插入到前面的数据
		int left=0;  //待插入之前的数据位置
		//循环对各个组进行几次插入排序
		for(int j=0;j<increasement;j++)
		{
			for(int i=2*increasement;i<len;i+=increasement)//i=2*increasemen 第二个数开始查
			{
				//插入此前的队列
				left=i; 
				T temp=list[left]; //标记当前待插入数据
				if(isAscending)
				{
					while(left>0 && list[left-increasement]>temp) //移动
					{
						list[left]=list[left-increasement];
						left-=increasement; //left初始为1时，只移动一位，之后left=0，left>0的条件继推出
					}
				}
				else{
					while(left>0 && list[left-increasement]<temp) //移动
					{
						list[left]=list[left-increasement];
						left-=increasement; //left初始为1时，只移动一位，之后left=0，left>0的条件继推出
					}
				}
				//判断是否移动了数据 移动之后，需要将数据插入
				if(left<i) list[left]=temp;
			}
		}
	}while(increasement>1); ////=1时退出 第一次increasement/3+1; 第二次必为1（整体插入） 总共会执行两次
}