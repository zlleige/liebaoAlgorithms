#include <iostream>
#include "SeqStack.h"
using namespace std;

int main()
{
	MyStack<int> mystack(5);
	mystack.Push(12);
	mystack.Push(15);
	mystack.Push(2);
	mystack.Push(5);
	mystack.Push(8);
	mystack.Push(56);
	mystack.Push(5);
	mystack.Push(8);
	mystack.Push(56);
	mystack.Push(5);
	mystack.Push(8);
	mystack.Push(56);
	mystack.Push(5);
	mystack.Push(8);
	mystack.Push(56);
	mystack.Push(5);
	mystack.Push(8);
	mystack.Push(56);

	//cout<<"_top: "<<mystack._top<<"  valeu:" << mystack.Top()<<"  capacity:"<<mystack._capacity<<endl;

	mystack.Pop();
	cout<< mystack.Top()<<endl;
	system("pause");

	return 0;
}