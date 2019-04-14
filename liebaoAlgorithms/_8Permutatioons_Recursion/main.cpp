#include <iostream>
#include <string>
using namespace std;

/*****
输入一个字符串，输出它所有的排列 
分层比如“abc” 依次调整一次位置，输出不同排列形式
一个循环遍历字符串长度：
->首先找所有字母依次开头的情况  长度3种 -> 递归，第(k+1)二位开始->...>k+1=m 末位时，输出
abc acb
bac bca
cab cba
*/
void Permutatioons(char *str,const int bIndex,const int eIndex);
int main()
{
	string str; 
	do{
		cout<<"输入字符串："<<endl;
		getline(cin,str);
		Permutatioons((char*)str.c_str(),0,str.length());
	}while(!str.empty());
	//char m[20]; 
	//cin.getline(m,20); 
	//Permutatioons(m,0,3);

	system("pause");
    return 0;
}

//--字符串 排列组合 "abc" 输出->abc acb,bac aca,cab cba

void Permutatioons(char *str,const int bIndex,const int eIndex)
{
	//结束标志-输出此时的字符串
	if(bIndex>=eIndex)  
	{
		for(int j=0;j<eIndex;j++)
		{
			cout<<str[j];
		}
		cout <<endl;
	}
	
	//循环，一次让每个字符为首 具体处理方式是 str[bIndex]与str[i++]交换，为a、b、c输出的
	for(int i=bIndex;i<eIndex;i++)
	{
		/*
		对于每次的交换操作
		1、a开头的
			交换 swap(a,b)->处理->换回开=》交换 swap(b,c)->处理->换回开
		2、b开头的
			交换 swap(a,b)->处理->换回开
		3、c开头的
			交换 swap(a,c)->处理->换回开
		*/
		std::swap(str[bIndex],str[i]);  //交换 
		Permutatioons(str,bIndex+1,eIndex); //层次递归 ab 
		std::swap(str[bIndex],str[i]);  //换回来
	}

}