#pragma once
#include <iostream>

//��ϣ������
//ʵ���Ƿ����������
//ʵ�֣���gap=n/2�����飬gap/=2ѭ����1����

//why shell��
//ϣ���������ȷ��飬Ȼ����ڲ������򣬲���������Ԫ�ػ��������ǰ����Ч�ʺܸߣ���ߴﵽO(n)��
//ͨ������������Ӿֲ�Ԫ���������򣬹ʴ����������ٶ�

//ʱ�䣺���O(n*n)

void ShellSort(int arr[], int n)
{
	int i, gap;
	for (gap=n/2; gap>0; gap/=2)
	{
		for (i=gap; i<n; i++)
		{
			//����ÿ��gap���С�飬����ֱ�Ӳ��뷽������arr[i]
			//��k=i-gap������С�����ݼ��
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