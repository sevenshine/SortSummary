#pragma once
#include <iostream>

void swap(int &left, int &right)
{
	int temp=left;
	left=right;
	right=temp;
}

//【二叉堆插入删除元素】
//【最小堆建立】

//插入新结点i，方式同插入排序
//插入元素num，将num置于数组a[]末尾，然后向上调整二叉堆
void MinHeapFixUp(int a[], int i)	
{
	int j;
	int temp=a[i];
	
	//父结点下标
	j=(i-1)/2;
	while (j>=0 && i!=0)
	{
		if (a[j]<=temp)
			break;

		a[i]=a[j];
		i=j;
		j=(i-1)/2;
	}
	a[i]=temp;
}

void MinHeapAddNumber(int a[], int n, int num)
{
	//将插入元素置于数组末端
	a[n]=num;
	MinHeapFixUp(a,n);
}

//被删除的元素a[0]被末尾元素取代，然后向下调整堆
//第i个元素向下调整，需要左子树结点j=i*2+1
void MinHeapFixDown(int a[], int i, int n)
{
	int j;
	int temp=a[i];

	j=2*i+1;
	while (j<n)
	{
		//在左右子树中选择小的子树
		if (j+1<n && a[j+1]<a[j])
			j++;
		
		if (a[j]>=temp)
			break;

		a[i]=a[j];
		i=j;
		j=2*i+1;
	}
	a[i]=temp;
}

void MinHeapDeleteNumber(int a[],int n)
{
	swap(a[0],a[n-1]);
	MinHeapFixDown(a, 0, n-1);
}

//【建立二叉堆数组】
//叶子结点已经是二叉堆，只需要将父结点向下调整就可以给数组建堆
//最后一个叶子结点下标n-1,它的父结点为(n-1-1)/2=n/2-1
void MakeMinHeap(int a[], int n)
{
	for (int i=n/2-1; i>=0; i--)
		MinHeapFixDown(a, i, n);
}

//【二叉堆排序】
//递减数组(a,i)可以控制数组递减
//最小堆取出第0个最小元素放到最后a[i],建立递减数组
void MinHeapSortToDescendArray(int a[], int n)
{
	for (int i=n-1; i>=1; i--)
	{
		swap(a[0],a[i]);
		MinHeapFixDown(a,0,i);
	}
}

//最小堆排序后是递减数组
void HeapSort(int a[], int n)
{
	MakeMinHeap(a,n);
	MinHeapSortToDescendArray(a,n);
}