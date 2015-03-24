#pragma once
#include <iostream>

//【归并排序】分治法（Divide and Conquer）
//1、归并函数书写，参数命名规范；明白递归过程，见印象笔记
//2、特殊语句处理，简洁明了temp[k++]=arr[i++];
//3、临时数组构造：
//a)全局变量使用，用来构造临时数组，不能应用与大量数据const int SIZE=100; int temp[SIZE];
//b)new出动态数组
//c)不能直接构造int length=last-first+1;int temp[length]；  数组在编译前要确定大小

//时间复杂度：O(n*logn);空间复杂度：O(n)

void Merge(int arr[],int first, int mid, int last, int temp[])
{
	int i=first,j=mid+1;
	int k=0;

	while (i<=mid && j<=last)
	{
		if (arr[i]<arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}

	while (i<=mid)
		temp[k++]=arr[i++];
	while (j<=last)
		temp[k++]=arr[j++];

	for (i=0;i<k;i++)
	{
		arr[first+i]=temp[i];
	}
}



void MergeSortRecursive(int arr[], int first, int last, int temp[])
{
	if (first<last)
	{
		//Same as (l+r)/2, but avoids overflow for large l and h
		int mid=first+(last-first)/2;
		MergeSortRecursive(arr,first,mid, temp);
		MergeSortRecursive(arr,mid+1,last, temp);
		Merge(arr,first,mid,last,temp);
	}
}


//new引入注意点：
//1、为空判断if (p==NULL)
//2、new和delete并存，delete[] p; 
//传入0、n-1，即first和last指针位置
bool MergeSort(int arr[], int n)
{
	int *p=new int[n];
	if (p==NULL)
		return false;
	MergeSortRecursive(arr,0,n-1,p);
	delete[] p; 
	return true;
}

