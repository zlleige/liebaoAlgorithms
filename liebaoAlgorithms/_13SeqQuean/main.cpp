#include <iostream>
#include "SeqQueue.h"

using namespace std;

int main()
{
	SeqQueue<char> myqueue(3);
	myqueue.Push('a');
	myqueue.Push('b');
	myqueue.Push('c');
	myqueue.Push('d');
	cout<<"���ף�"<<myqueue.Front()<<"  ��β��"<<myqueue.Rear()<<endl;
	myqueue.Pop();
	cout<<"���ף�"<<myqueue.Front()<<"  ��β��"<<myqueue.Rear()<<endl;
	myqueue.Pop();
	cout<<"���ף�"<<myqueue.Front()<<"  ��β��"<<myqueue.Rear()<<endl;

	system("pause");
	return 0;
}
