#ifndef _INSERTION_SORT_H__
#define _INSERTION_SORT_H__

#include "Common.h"

//�������У���С����  ���� [0,nLen )
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
		//�Ż��������򣬱��浱ǰ����ѭ���Ŀ���ֵarr[ii]�����αȽϣ��ø�ֵ���潻��������һ�ν�����3�θ�ֵ��
		for (jj = ii; jj > 0 && arr[jj - 1] > nCurrentTailVal; jj--)
		{
			//swap(arr[jj], arr[jj-1]);
			arr[jj] = arr[jj-1];
		}
		arr[jj] = nCurrentTailVal;//�ҵ�����Ӧ�÷ŵ�λ�ã�ֱ�Ӹ�ֵ��ȥ����ֹ��ǰ�ڲ�ѭ��
	}
}


//ָ����Χ�ڽ��в������򣬼����Ϸ���ȫ��Χ����  ,���� [iLeft,iRight],Ϊ�Ż�MergeSort׼����
//�������У���С����
template <typename T>
void InsertionSort_Part(T arr[], int iLeft, int iRight)
{
	T nCurrentTailVal = arr[iLeft+1];
	int jj = iLeft;
	for (int ii = iLeft + 1; ii <= iRight; ii++)
	{
		nCurrentTailVal = arr[ii];
		//�Ż��������򣬱��浱ǰ����ѭ���Ŀ���ֵarr[ii]�����αȽϣ��ø�ֵ���潻��������һ�ν�����3�θ�ֵ��
		for (jj = ii; jj > iLeft && arr[jj - 1] > nCurrentTailVal; jj--)
		{
			arr[jj] = arr[jj - 1];
		}
		arr[jj] = nCurrentTailVal;//�ҵ�����Ӧ�÷ŵ�λ�ã�ֱ�Ӹ�ֵ��ȥ����ֹ��ǰ�ڲ�ѭ��
	}

}


#endif