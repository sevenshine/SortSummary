#pragma once
#include <iostream>

//����������
//���η���Divide and Conquer����ͬ�鲢�����ù鲢��˼·��д����
//��ȡ��һ��Ϊ������Ȼ���������������������ķŵ����棬С�ķŵ�ǰ��
//a) ����ʵ�����������ӷ���http://blog.csdn.net/morewindows/article/details/6684558
//b) �����ó��潻����ʵ�֣�ֱ�ӽ�������ͣ�����ҽ�����swap(arr[i],arr[j])	http://geeksquiz.com/quick-sort/

//ʱ�䣺O(n*logn)  �ռ䣺O(1)

void QuickSort(int arr[], int l, int r)
{
	if (l<r)
	{
		//swap(s[1],s[(l+r)/2]);	���м�����Ϊ����
		//s[l]��s[i]���ǵ�һ����
		int i=l, j=r, temp=arr[l];
		while (i<j)
		{
			while (i<j && arr[j]>=temp)	// ���������ҵ�һ��С��temp���� 
				j--;
			if (i<j)
				arr[i++]=arr[j];

			while (i<j && arr[i]<=temp)	// ���������ҵ�һ�����ڵ���temp���� 
				i++;
			if (i<j)
				arr[j--]=arr[i];
		}
		//�˳�ʱ��i=j����temp��������
		arr[i]=temp;

		QuickSort(arr, l, i-1);
		QuickSort(arr, i+1, r);
	}



}