#pragma once
#include <iostream>

//��ѡ������
//a0,a1...ai-1���Ѿ��ź���ģ�ai,ai+1...an���ҵ���С������ǣ�swap(arr[min],arr[i])
//ʱ�临�Ӷȣ�O(n*n)���ռ䣺O(1)
//���ȶ��ԣ�egg��5 8 5 2 3������5��2swap�����б任������5˳��任�����Բ��ȶ�
void swap(int &left, int &right)
{
	int temp=left;
	left=right;
	right=temp;
}

void SelectionSort(int arr[], int length)
{
	int i,j,min;
	for (i=0;i<length-1;i++)
	{
		min=i;
		for (j=i;j<length;j++)
		{
			if (arr[min]>arr[j])
				min=j;
		}
		if (min!=i)
			swap(arr[min],arr[i]);	
	}
}