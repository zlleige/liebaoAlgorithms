#pragma once

template<class T>
class MyStack
{
public:
	explicit MyStack(const int capacity=10); //��ֹ�Զ�����ת��
	~MyStack(void);
	void Push(const T& data);
	void Pop();
	T& Top() const;
	bool IsEmpty();


//private:
public:
	int _top; //ָ��ջ��
	int _capacity; //����
	T* _stack; //����
};

template<class T>
MyStack<T>::MyStack(const int capacity):_capacity(capacity)
{
	if(capacity < 1) throw("capacity must ---");
	_stack=new T[capacity];
	_top=-1;
}

template<class T>
MyStack<T>::~MyStack(void)
{
	delete[] _stack;
}

template<class T>
void MyStack<T>::Push(const T& data)
{
	if(_top>=_capacity-1) //������
	{
		_capacity*=2;
		T* tmp=_stack;
		_stack=new T[_capacity];
		delete[] tmp;
	}
	_stack[++_top]=data; //��ʼָ��-1
}

template<class T>
void MyStack<T>::Pop()
{
	if(_top < 0) return; 
	//T* tmp=_stack+_top;
	//delete tmp;
	//_top--;
	_stack[_top--].~T();
}

template<class T>
T& MyStack<T>::Top() const
{
	if(_top < 0) throw("stack is empty!");
	return _stack[_top];
}

template<class T>
bool MyStack<T>::IsEmpty()
{
	return _top < 0;
}