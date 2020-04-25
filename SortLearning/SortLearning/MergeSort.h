#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include "Common.h"

//�������У���С����
template <typename T>
void MergeSort(T arr[], int nLen)
{
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
	int iMiddle = (iRight - iLeft) / 2 + iLeft;//���������ƽ������ֹ���int��Χ
	__mergeSort(arr, iLeft, iMiddle);
	__mergeSort(arr, iMiddle + 1, iRight);

	__mergeOperation(arr, iLeft, iMiddle, iRight);
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