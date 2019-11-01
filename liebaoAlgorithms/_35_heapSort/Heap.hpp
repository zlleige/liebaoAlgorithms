#ifndef _HEAP_H
#define _HEAP_H
/* �����鹹��һ���ѣ����������ǽ��������Ĳ���



**/

#include <iostream>

template<class T>
class MyHeap
{
public:
	MyHeap(int capacity,bool isBig=false);
	~MyHeap();
	bool IsEmpty(); 
	void Push(const T& data);
	void Pop();        //ɾ����
	const T& Top()const; //���ظ�

private:
	int _size;    //��ǰ�ѵĴ�С
	int _capacity; //��ǰ�ѵ�����
	bool _isBig;
	T * _heap;     //����

	void trickUp(int index); //������͸  ��index��ʼ���ϱȽϽ������ڵ���ӽڵ�
	void trickDown(int index);  //������͸  ��index��ʼ���ϱȽϽ������ڵ���ӽڵ�
};

template<class T>
MyHeap<T>::MyHeap(int capacity,bool isBig)
{
	if(capacity < 0) throw("��������Ϊ����");
	_capacity=capacity;
	_heap=new T[capacity];
	_isBig=isBig;
	_size=0;
}

template<class T>
MyHeap<T>::~MyHeap()
{
	if(_heap)
	{
		delete[] _heap;
		_heap=NULL;
	}
}

template<class T>
bool MyHeap<T>::IsEmpty()
{
	return _size <= 0;
}

/*
�����������Ԫ�ز嵽���Ȼ��������͸���Ƚ��Ƿ���ڸ��ڵ㣬���򽻻�
**/
template<class T>
void MyHeap<T>::Push(const T& data)
{
	if(_size>=_capacity) //��̬����
	{
		_capacity*=2;
		T *tmp=_heap;
		_heap=new T[_capacity];
		delete[] tmp;
		tmp=NULL;
	}
	_heap[_size]=data; //���뵽��� 
	trickUp(_size++);  //������͸
}

//������͸ ���ڲ������  �Ƚ��Ƿ���ڸ��ڵ㣬���򽻻�
template<class T>
void MyHeap<T>::trickUp(int index)
{
	int parent=(index-1)/2; //index ���ڵ�
	T temp=_heap[index];    //�ݴ�����
	while(index>0 && _heap[parent]< temp)
	{
		_heap[index]=_heap[parent]; //��������
		index=parent;
		parent=(index-1)/2;
	}
	_heap[index]=temp; //jieshu
}

//�Ƚ������ӽڵ��뵱ǰ�ڵ㣬С���򽻻�
template<class T>
void MyHeap<T>::trickDown(int index)
{
	//���_size>=2 ���б�Ҫ�Ƚ� 
	if(_size < 2) return; //֮������ӽڵ�
	int maxChild; //���ڼ�¼�����ӽڵ�
	T top =_heap[index]; //�ݴ����ڵĸ� 
	while(index< _size/2) // _size>=2 ���б�Ҫ�Ƚ� ���һ����Ҷ�ӽڵ�=_size/2-1
	{
		int left =2 *index+1; //z�����ӽڵ�
		int right = left+1;
		if(right < _size && _heap[right]>_heap[left]) //������ ������ӽڵ���ڲ��Ҵ�����
			maxChild = right;
		else
			maxChild = left;
		if(top >= _heap[maxChild]) break;  //ֱ��
		_heap[index]=_heap[maxChild]; //�������
		index=maxChild;
	}
	_heap[index]=top; //�滻���
}

//�����һ��Ԫ�طŵ�����0����Ȼ��������͸���Ƚ������ӽڵ��뵱ǰ�ڵ㣬С���򽻻�
template<class T>
void MyHeap<T>::Pop()        //ɾ����
{
	_heap[0]=_heap[--_size]; //���һ��Ԫ�طŵ�����0��
	trickDown(0); //������͸
}

template<class T>
const T& MyHeap<T>::Top() const //���ظ�
{
	return _heap[0];
}

#endif


/** //ʹ��˵��
#if 0 //�����Ա���
	MyHeap<int> heap1(100);
	cout<<"�Ƿ�Ϊ�գ�"<<heap1.IsEmpty()<<endl;
	heap1.Push(1);
	heap1.Push(5);
	heap1.Push(2);
	heap1.Push(7);
	heap1.Push(3);
	heap1.Push(6);
	heap1.Push(4);
	cout<<"MAX��"<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"ɾ����"<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"ɾ����"<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"ɾ����"<<heap1.Top()<<endl;
#endif


#if 0 //�Ա������� ˼·�������ݼ���ѣ�Ȼ���ٵ���
	MyHeap<int> heap2(100);
	int arr[] ={1,2,3,9,7,5,3,63,1,35,34,6};
	int len = sizeof(arr)/sizeof(int);
	for(int i=0;i<len;i++) //�����
	{
		heap2.Push(arr[i]);
	}
	for(int i=0;i<len;i++) //�����
	{
		arr[i]=heap2.Top();
		heap2.Pop();
	}
	PrintData(arr,len);
	cout<<endl;
#endif

*/


