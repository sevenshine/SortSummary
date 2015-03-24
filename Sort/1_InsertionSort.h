#pragma once
#include <iostream>

//【插入排序】
//1、从后向前比较，然后向后移位
//2、用列表表示a[i],a[j],key关系，注意边界
//3、代入特殊数组验证正确性;注意出错处理均未做处理

//时间复杂度：最差O(n*n)，最好O(n)  空间：O(1)	
void InsertionSort(int arr[], int length)
{
	int i, j, key; 
	for (i=1;i<length;i++)
	{
		key=arr[i];
		j=i-1;
		while (j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}