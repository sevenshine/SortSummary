#pragma once
#include <iostream>

//【选择排序】
//a0,a1...ai-1是已经排好序的；ai,ai+1...an中找到最小的做标记，swap(arr[min],arr[i])
//时间复杂度：O(n*n)；空间：O(1)
//不稳定性：egg，5 8 5 2 3；其中5与2swap后序列变换后两个5顺序变换，所以不稳定
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