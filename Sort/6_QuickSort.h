#pragma once
#include <iostream>

//【快速排序】
//分治法（Divide and Conquer），同归并，故用归并的思路来写程序
//先取第一个为基数，然后调整，将后面比这个数大的放到后面，小的放到前面
//a) 具体实现如下面的填坑法：http://blog.csdn.net/morewindows/article/details/6684558
//b) 或者用常规交换法实现，直接将基数不停的左右交换，swap(arr[i],arr[j])	http://geeksquiz.com/quick-sort/

//时间：O(n*logn)  空间：O(1)

void QuickSort(int arr[], int l, int r)
{
	if (l<r)
	{
		//swap(s[1],s[(l+r)/2]);	以中间数作为基数
		//s[l]即s[i]就是第一个坑
		int i=l, j=r, temp=arr[l];
		while (i<j)
		{
			while (i<j && arr[j]>=temp)	// 从右向左找第一个小于temp的数 
				j--;
			if (i<j)
				arr[i++]=arr[j];

			while (i<j && arr[i]<=temp)	// 从左向右找第一个大于等于temp的数 
				i++;
			if (i<j)
				arr[j--]=arr[i];
		}
		//退出时，i=j；将temp填到这个坑中
		arr[i]=temp;

		QuickSort(arr, l, i-1);
		QuickSort(arr, i+1, r);
	}



}