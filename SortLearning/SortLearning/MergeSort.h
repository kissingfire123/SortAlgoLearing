#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include "Common.h"
#include "InsertionSort.h"


//�������У���С����  ,���� [0,nLen )
template <typename T>  
void MergeSort(T arr[], int nLen)
{
	if (nullptr == arr || nLen <2)
	{
		return;
	}
	__mergeSort(arr, 0, nLen - 1);
}


//��[arr[iLeft],arr[iRight]�����䷶Χ�ڽ��еݹ�����
template <typename T>
void __mergeSort(T arr[], int iLeft, int iRight)
{
	if (iLeft >= iRight)
	{
		return;
	}

	//�Ż�����2�����鲢���������Ƭ�ζ̵�һ������ʱ��ת���ò������򷽷�����
	if (iRight - iLeft < 16)
	{
		InsertionSort_Part(arr, iLeft,iRight);
		return;
	}

	int iMiddle = (iRight - iLeft) / 2 + iLeft;//���������ƽ������ֹ���int��Χ
	__mergeSort(arr, iLeft, iMiddle);
	__mergeSort(arr, iMiddle + 1, iRight);

	//�Ż����� 1 ���������if�ж�������������arr������ǰ��ɺ�ʡȥ����Ĳ����������if����������ʾ��ʱ����arr�������
	//������������arr�����ǽ��������
	if (arr[iMiddle] > arr[iMiddle + 1]) 
	{
		__mergeOperation(arr, iLeft, iMiddle, iRight);
	}
}



//��2������������кϲ�����
template <typename T>
void __mergeOperation(T arr[], int iLeft, int iMiddle, int iRight)
{
	assert(iLeft <= iMiddle);
	assert(iMiddle <= iRight);

	T *pSortBuffer = new T[iRight - iLeft + 1];//�鲢������Ҫ���⿪��һ�οռ���ϲ�����ʹ��
	memcpy_s(pSortBuffer, (iRight - iLeft + 1)*sizeof(T), &arr[iLeft], (iRight - iLeft + 1)*sizeof(T));

	int idxL = iLeft;
	int idxR = iMiddle+1;
	int kk = iLeft;

	///����ȷ�������±�ĺϷ���
	for (int kk = iLeft; kk <= iRight; kk++)
	{
		if (idxL > iMiddle)
		{
			arr[kk] = pSortBuffer[idxR - iLeft];
			idxR++;
		}
		else if (idxR > iRight)
		{
			arr[kk] = pSortBuffer[idxL - iLeft];
			idxL++;
		}
		else if (pSortBuffer[idxL - iLeft] < pSortBuffer[idxR - iLeft])
		{
			arr[kk] = pSortBuffer[idxL - iLeft];
			idxL++;
		}
		else  /// if (pSortBuffer[idxL - iLeft] >= pSortBuffer[idxR - iLeft])
		{
			arr[kk] = pSortBuffer[idxR - iLeft];
			idxR++;
		}
	}
	SortTestHelper::DeleteRandArr(pSortBuffer);
}










#endif