#ifndef _HEAP_H
#define _HEAP_H
/* 用数组构建一个堆，推排序则是将数组插入的操作



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
	void Pop();        //删除根
	const T& Top()const; //返回根

private:
	int _size;    //当前堆的大小
	int _capacity; //当前堆的容量
	bool _isBig;
	T * _heap;     //数组

	void trickUp(int index); //向上渗透  从index开始向上比较交换父节点和子节点
	void trickDown(int index);  //向上渗透  从index开始向上比较交换父节点和子节点
};

template<class T>
MyHeap<T>::MyHeap(int capacity,bool isBig)
{
	if(capacity < 0) throw("容量不能为负数");
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
插入操作，将元素插到最后，然后向上渗透，比较是否大于父节点，有则交换
**/
template<class T>
void MyHeap<T>::Push(const T& data)
{
	if(_size>=_capacity) //动态数组
	{
		_capacity*=2;
		T *tmp=_heap;
		_heap=new T[_capacity];
		delete[] tmp;
		tmp=NULL;
	}
	_heap[_size]=data; //插入到最后 
	trickUp(_size++);  //向上渗透
}

//向上渗透 用于插入操作  比较是否大于父节点，有则交换
template<class T>
void MyHeap<T>::trickUp(int index)
{
	int parent=(index-1)/2; //index 父节点
	T temp=_heap[index];    //暂存数据
	while(index>0 && _heap[parent]< temp)
	{
		_heap[index]=_heap[parent]; //下移数据
		index=parent;
		parent=(index-1)/2;
	}
	_heap[index]=temp; //jieshu
}

//比较左右子节点与当前节点，小于则交换
template<class T>
void MyHeap<T>::trickDown(int index)
{
	//如果_size>=2 才有必要比较 
	if(_size < 2) return; //之后必有子节点
	int maxChild; //用于记录最大的子节点
	T top =_heap[index]; //暂存现在的根 
	while(index< _size/2) // _size>=2 才有必要比较 最后一个非叶子节点=_size/2-1
	{
		int left =2 *index+1; //z左右子节点
		int right = left+1;
		if(right < _size && _heap[right]>_heap[left]) //很巧妙 如果右子节点存在并且大于左
			maxChild = right;
		else
			maxChild = left;
		if(top >= _heap[maxChild]) break;  //直到
		_heap[index]=_heap[maxChild]; //向上填充
		index=maxChild;
	}
	_heap[index]=top; //替换完成
}

//将最后一个元素放到根（0），然后向下渗透，比较左右子节点与当前节点，小于则交换
template<class T>
void MyHeap<T>::Pop()        //删除根
{
	_heap[0]=_heap[--_size]; //最后一个元素放到根（0）
	trickDown(0); //向下渗透
}

template<class T>
const T& MyHeap<T>::Top() const //返回根
{
	return _heap[0];
}

#endif


/** //使用说明
#if 0 //测试猎豹堆
	MyHeap<int> heap1(100);
	cout<<"是否为空："<<heap1.IsEmpty()<<endl;
	heap1.Push(1);
	heap1.Push(5);
	heap1.Push(2);
	heap1.Push(7);
	heap1.Push(3);
	heap1.Push(6);
	heap1.Push(4);
	cout<<"MAX："<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"删除后："<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"删除后："<<heap1.Top()<<endl;
	heap1.Pop();
	cout<<"删除后："<<heap1.Top()<<endl;
#endif


#if 0 //猎豹堆排序 思路：把数据加入堆，然后再弹出
	MyHeap<int> heap2(100);
	int arr[] ={1,2,3,9,7,5,3,63,1,35,34,6};
	int len = sizeof(arr)/sizeof(int);
	for(int i=0;i<len;i++) //加入堆
	{
		heap2.Push(arr[i]);
	}
	for(int i=0;i<len;i++) //加入堆
	{
		arr[i]=heap2.Top();
		heap2.Pop();
	}
	PrintData(arr,len);
	cout<<endl;
#endif

*/


