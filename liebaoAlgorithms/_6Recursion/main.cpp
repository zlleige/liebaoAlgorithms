#include <iostream>
using namespace std;
long factorialCount(int n);
long factorialCount2(int n);
int main()
{
    cout<<factorialCount(4)<<endl;
	cout<<factorialCount2(4)<<endl;
	system("pause");
    return 0;
}

//阶乘计算 n!=n*(n-1)!  终止条件：n=0
/*
4！=4*3!;
3！=3*2!;
2！=2*1!;
1！=1*0!;
0！=1; 
*/
long factorialCount(int n) //
{
	if(n==0) return 1; //结束条件
	else return n*factorialCount(n-1);
}

//非递归
//递归均可迭代
long factorialCount2(int n)
{
	long sum=1;
	for(int i=1;i<=n;i++)
	{
		sum*=i;
	}
	return sum;
}
