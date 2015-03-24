#pragma once
#include <iostream>

void swap(int &left, int &right)
{
	int temp=left;
	left=right;
	right=temp;
}

//������Ѳ���ɾ��Ԫ�ء�
//����С�ѽ�����

//�����½��i����ʽͬ��������
//����Ԫ��num����num��������a[]ĩβ��Ȼ�����ϵ��������
void MinHeapFixUp(int a[], int i)	
{
	int j;
	int temp=a[i];
	
	//������±�
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
	//������Ԫ����������ĩ��
	a[n]=num;
	MinHeapFixUp(a,n);
}

//��ɾ����Ԫ��a[0]��ĩβԪ��ȡ����Ȼ�����µ�����
//��i��Ԫ�����µ�������Ҫ���������j=i*2+1
void MinHeapFixDown(int a[], int i, int n)
{
	int j;
	int temp=a[i];

	j=2*i+1;
	while (j<n)
	{
		//������������ѡ��С������
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

//��������������顿
//Ҷ�ӽ���Ѿ��Ƕ���ѣ�ֻ��Ҫ����������µ����Ϳ��Ը����齨��
//���һ��Ҷ�ӽ���±�n-1,���ĸ����Ϊ(n-1-1)/2=n/2-1
void MakeMinHeap(int a[], int n)
{
	for (int i=n/2-1; i>=0; i--)
		MinHeapFixDown(a, i, n);
}

//�����������
//�ݼ�����(a,i)���Կ�������ݼ�
//��С��ȡ����0����СԪ�طŵ����a[i],�����ݼ�����
void MinHeapSortToDescendArray(int a[], int n)
{
	for (int i=n-1; i>=1; i--)
	{
		swap(a[0],a[i]);
		MinHeapFixDown(a,0,i);
	}
}

//��С��������ǵݼ�����
void HeapSort(int a[], int n)
{
	MakeMinHeap(a,n);
	MinHeapSortToDescendArray(a,n);
}