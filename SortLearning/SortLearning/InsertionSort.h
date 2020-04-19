#ifndef _INSERTION_SORT_H__
#define _INSERTION_SORT_H__

#include "Common.h"

//�������У���С����
template <typename T>
void InsertionSort(T arr[], int nLen)
{
	if (nullptr == arr || nLen <2)
	{
		return;
	}
	T nCurrentTailVal = arr[1];
	int jj = 0;
	for (int ii = 1; ii < nLen; ii++)
	{
		nCurrentTailVal = arr[ii];
		//�Ż�ѡ�����򣬱��浱ǰ����ѭ���Ŀ���ֵarr[ii]�����αȽϣ��ø�ֵ���潻��������һ�ν�����3�θ�ֵ��
		//����������ͬ��������ǰ��ֹѭ��
		for (jj = ii; jj > 0 && nCurrentTailVal < arr[jj-1]; jj--)
		{
			//swap(arr[jj], arr[jj-1]);
			arr[jj] = arr[jj-1];
		}
		arr[jj] = nCurrentTailVal;//�ҵ�����Ӧ�÷ŵ�λ�ã�ֱ�Ӹ�ֵ��ȥ����ֹ��ǰ�ڲ�ѭ��
	}
}



#endif