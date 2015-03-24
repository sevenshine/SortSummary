#pragma once
#include <iostream>

void swap(int &left, int &right)
{
	int temp=left;
	left=right;
	right=temp;
}

//【冒泡排序】
//1、最后排好序的元素的控制，j<length-i-1
//2、优化算法：在遍历一圈后未发生交换则退出遍历
//3、时间复杂度：O(n*n)；优化后最好，O(n)，最差，O(n*n)
//4、空间复杂度：O(1)
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

//在一圈遍历中放置swapped判断是否有过交换
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


