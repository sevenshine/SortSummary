//最简单的创建多线程实例
#include <iostream>
#include "HeapSort.h"
using namespace std;

void PrintSort(int arr[],int length)
{
	for (int i=0;i<length;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//int length=sizeof(arr)/sizeof(arr[0]);判断数组长度
void Test1()
{
	int arr[]={64, 34, 25, 12, 22, 11, 90};
	int length=sizeof(arr)/sizeof(arr[0]);
	PrintSort(arr,length);
	MakeMinHeap(arr,length);
	PrintSort(arr,length);
	MinHeapSortToDescendArray(arr,length);
	PrintSort(arr,length);
}

void Test2()
{
	int arr[]={1};
	int length=sizeof(arr)/sizeof(arr[0]);
	PrintSort(arr,length);
	HeapSort(arr,length);
	PrintSort(arr,length);
}

int main()  
{ 
	Test1();
	cout<<endl;
	Test2();
}  

