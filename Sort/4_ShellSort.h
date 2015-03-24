#pragma once
#include <iostream>

//【希尔排序】
//实质是分组插入排序
//实现：以gap=n/2来分组，gap/=2循环到1个数

//why shell？
//希尔排序是先分组，然后基于插入排序，插入排序在元素基本有序的前提下效率很高，最高达到O(n)；
//通过分组可以增加局部元素排列有序，故大大提高排序速度

//时间：最差O(n*n)

void ShellSort(int arr[], int n)
{
	int i, gap;
	for (gap=n/2; gap>0; gap/=2)
	{
		for (i=gap; i<n; i++)
		{
			//对于每个gap里的小组，按照直接插入方法插入arr[i]
			//用k=i-gap来控制小组数据间隔
			if (arr[i]<arr[i-gap])
			{
				int temp=arr[i];
				int k=i-gap;
				while (k>=0 && arr[k]>temp)
				{
					arr[k+gap]=arr[k];
					k-=gap;
				}
				arr[k+gap]=temp;

			}
		}
	}
}