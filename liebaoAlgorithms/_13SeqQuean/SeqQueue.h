#pragma once
#include <algorithm>
template<class T>
class SeqQueue
{
public:
	SeqQueue(int capacity=10);
	~SeqQueue();
	bool IsEmpty() const;
	void Push(const T& data); //队尾插
	T& Front() const;
	T& Rear() const;
	void Pop();  //堆首删除
private: 
	int _capacity;
	int _front;
	int _rear;
	T* _queue;
};

template<class T>
SeqQueue<T>::SeqQueue(int capacity):_capacity(capacity)
{
	if(capacity<1) throw("err----");
	_front=0;
	_rear=0;
	_queue=new T[_capacity];
}

template<class T>
SeqQueue<T>::~SeqQueue()
{
	if(_queue)
		delete[]  _queue;
}

template<class T>
bool SeqQueue<T>::IsEmpty() const
{
	return _front==_rear; //在同一个位置即为空 初始队首和队尾 不放数据
}

template<class T>
void SeqQueue<T>::Push(const T& data)
{
	//if(_rear==_capacity) _rear=0; //循环
	//else _rear++;
	if((_rear+1)%_capacity==_front) //数组满 加倍操作
	{
		//加倍
		T* newQ=new T[2*_capacity];
		//判断是否回绕
		int start=(_front+1)%_capacity; //
		if(start<2) //回绕
			copy(_queue+start,_queue+start+_capacity-1,newQ);
		else
		{
			//回绕 拷贝两次
			copy(_queue+start,_queue+start+_capacity,newQ);
			copy(_queue,_queue+_rear+1,newQ+_capacity-start);
		}
		//处理队首队尾位置
		_front=2*_capacity; //队首放在最后
		_rear=_capacity-2; //队首放在最前面
		_capacity*=2; //更新容量
		delete[] _queue;
		_queue=newQ;
	} 
	_rear=(_rear+1)%_capacity; //下一个位置
	_queue[_rear]=data;
}

template<class T>
T& SeqQueue<T>:: Front() const
{
	if(IsEmpty()) throw("kong----");
	return _queue[(_front+1)%_capacity]; //队首不放数据 指向下一个
}

template<class T>
T& SeqQueue<T>:: Rear() const
{
	if(IsEmpty()) throw("kong----");
	return _queue[_rear];
}

template<class T>
void SeqQueue<T>:: Pop()
{
	if(IsEmpty()) throw("kong----");
	_front=(_front+1)%_capacity; //front不存数据，+1即删除数据
	_queue[_front].~T(); //调用存入数据本身的构造函数删除 需要外界类要有构造
}

