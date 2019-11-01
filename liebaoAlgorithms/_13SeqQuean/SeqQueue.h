#pragma once
#include <algorithm>
template<class T>
class SeqQueue
{
public:
	SeqQueue(int capacity=10);
	~SeqQueue();
	bool IsEmpty() const;
	void Push(const T& data); //��β��
	T& Front() const;
	T& Rear() const;
	void Pop();  //����ɾ��
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
	return _front==_rear; //��ͬһ��λ�ü�Ϊ�� ��ʼ���׺Ͷ�β ��������
}

template<class T>
void SeqQueue<T>::Push(const T& data)
{
	//if(_rear==_capacity) _rear=0; //ѭ��
	//else _rear++;
	if((_rear+1)%_capacity==_front) //������ �ӱ�����
	{
		//�ӱ�
		T* newQ=new T[2*_capacity];
		//�ж��Ƿ����
		int start=(_front+1)%_capacity; //
		if(start<2) //����
			copy(_queue+start,_queue+start+_capacity-1,newQ);
		else
		{
			//���� ��������
			copy(_queue+start,_queue+start+_capacity,newQ);
			copy(_queue,_queue+_rear+1,newQ+_capacity-start);
		}
		//������׶�βλ��
		_front=2*_capacity; //���׷������
		_rear=_capacity-2; //���׷�����ǰ��
		_capacity*=2; //��������
		delete[] _queue;
		_queue=newQ;
	} 
	_rear=(_rear+1)%_capacity; //��һ��λ��
	_queue[_rear]=data;
}

template<class T>
T& SeqQueue<T>:: Front() const
{
	if(IsEmpty()) throw("kong----");
	return _queue[(_front+1)%_capacity]; //���ײ������� ָ����һ��
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
	_front=(_front+1)%_capacity; //front�������ݣ�+1��ɾ������
	_queue[_front].~T(); //���ô������ݱ���Ĺ��캯��ɾ�� ��Ҫ�����Ҫ�й���
}

