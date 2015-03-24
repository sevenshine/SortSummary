#pragma once
#include <iostream>

//����������
//1���Ӻ���ǰ�Ƚϣ�Ȼ�������λ
//2�����б��ʾa[i],a[j],key��ϵ��ע��߽�
//3����������������֤��ȷ��;ע��������δ������

//ʱ�临�Ӷȣ����O(n*n)�����O(n)  �ռ䣺O(1)	
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