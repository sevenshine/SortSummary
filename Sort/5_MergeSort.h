#pragma once
#include <iostream>

//���鲢���򡿷��η���Divide and Conquer��
//1���鲢������д�����������淶�����׵ݹ���̣���ӡ��ʼ�
//2��������䴦���������temp[k++]=arr[i++];
//3����ʱ���鹹�죺
//a)ȫ�ֱ���ʹ�ã�����������ʱ���飬����Ӧ�����������const int SIZE=100; int temp[SIZE];
//b)new����̬����
//c)����ֱ�ӹ���int length=last-first+1;int temp[length]��  �����ڱ���ǰҪȷ����С

//ʱ�临�Ӷȣ�O(n*logn);�ռ临�Ӷȣ�O(n)

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


//new����ע��㣺
//1��Ϊ���ж�if (p==NULL)
//2��new��delete���棬delete[] p; 
//����0��n-1����first��lastָ��λ��
bool MergeSort(int arr[], int n)
{
	int *p=new int[n];
	if (p==NULL)
		return false;
	MergeSortRecursive(arr,0,n-1,p);
	delete[] p; 
	return true;
}

