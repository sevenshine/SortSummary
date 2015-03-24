#pragma once
#include <iostream>

void swap(int &left, int &right)
{
	int temp=left;
	left=right;
	right=temp;
}

//��ð������
//1������ź����Ԫ�صĿ��ƣ�j<length-i-1
//2���Ż��㷨���ڱ���һȦ��δ�����������˳�����
//3��ʱ�临�Ӷȣ�O(n*n)���Ż�����ã�O(n)����O(n*n)
//4���ռ临�Ӷȣ�O(1)
void BubbleSort(int arr[], int length)
{
	int i,j;
	for (i=0; i<length; i++)
	{
		for(j=0;j<length-i-1;j++)
		{
			if (arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
}

//��һȦ�����з���swapped�ж��Ƿ��й�����
void BubbleSort_Opt(int arr[], int length)
{
	int i,j;
	bool swapped;
	for (i=0; i<length; i++)
	{
		swapped=false;
		for(j=0;j<length-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swapped=true;
			}
		}
		if (swapped == false)
			break;
	}
}


