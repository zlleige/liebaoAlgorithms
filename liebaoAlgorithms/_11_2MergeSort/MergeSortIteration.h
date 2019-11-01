#ifndef _MERGESORTITERATION_H
#define _MERGESORTITERATION_H


//归并算法  归并排序调用，分别两两归并
template<class T>
void Merge(T *initList, T *mergedList, const int l, const int m, const int n)
{
	int i1, i2, iResult;
	for(i1 = l, i2 = m+1, iResult = l; i1 <= m && i2 <= n; iResult++)
	{
		if(initList[i1] <= initList[i2])
		{
			mergedList[iResult] = initList[i1];
			i1++;
		}
		else
		{
			mergedList[iResult] = initList[i2];
			i2++;
		}
	}
	copy(initList+i1, initList+m+1, mergedList+iResult);
	copy(initList+i2, initList+n+1, mergedList+iResult);
}

//依次归并  归并排序调用，分别两两归并
template<class T>
void MergePass(T *initList, T *resultList, const int n, const int s)
{
	int i;
	for(i=1; i<=n-2*s+1; i+=2*s)
		Merge(initList, resultList, i, i+s-1, i+2*s-1);

	if((i+s-1)<n)
		Merge(initList, resultList,i,i+s-1,n);
	else
		copy(initList+i, initList+n+1, resultList+i);
}

//归并排序
template<class T>
void MergeSort(T *a, const int n)
{
	T *tempList = new int[n+1]; //tempList[0]不用
	for(int l=1; l<n; l*=2)
	{
		MergePass(a,tempList,n,l);
		l *= 2;
		MergePass(tempList,a,n,l);
	}
	delete[] tempList;
}

#endif