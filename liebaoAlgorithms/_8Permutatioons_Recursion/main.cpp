#include <iostream>
#include <string>
using namespace std;

/*****
����һ���ַ�������������е����� 
�ֲ���硰abc�� ���ε���һ��λ�ã������ͬ������ʽ
һ��ѭ�������ַ������ȣ�
->������������ĸ���ο�ͷ�����  ����3�� -> �ݹ飬��(k+1)��λ��ʼ->...>k+1=m ĩλʱ�����
abc acb
bac bca
cab cba
*/
void Permutatioons(char *str,const int bIndex,const int eIndex);
int main()
{
	string str; 
	do{
		cout<<"�����ַ�����"<<endl;
		getline(cin,str);
		Permutatioons((char*)str.c_str(),0,str.length());
	}while(!str.empty());
	//char m[20]; 
	//cin.getline(m,20); 
	//Permutatioons(m,0,3);

	system("pause");
    return 0;
}

//--�ַ��� ������� "abc" ���->abc acb,bac aca,cab cba

void Permutatioons(char *str,const int bIndex,const int eIndex)
{
	//������־-�����ʱ���ַ���
	if(bIndex>=eIndex)  
	{
		for(int j=0;j<eIndex;j++)
		{
			cout<<str[j];
		}
		cout <<endl;
	}
	
	//ѭ����һ����ÿ���ַ�Ϊ�� ���崦��ʽ�� str[bIndex]��str[i++]������Ϊa��b��c�����
	for(int i=bIndex;i<eIndex;i++)
	{
		/*
		����ÿ�εĽ�������
		1��a��ͷ��
			���� swap(a,b)->����->���ؿ�=������ swap(b,c)->����->���ؿ�
		2��b��ͷ��
			���� swap(a,b)->����->���ؿ�
		3��c��ͷ��
			���� swap(a,c)->����->���ؿ�
		*/
		std::swap(str[bIndex],str[i]);  //���� 
		Permutatioons(str,bIndex+1,eIndex); //��εݹ� ab 
		std::swap(str[bIndex],str[i]);  //������
	}

}