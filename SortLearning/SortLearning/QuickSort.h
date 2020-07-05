#ifndef __QUICK_SORT__
#define __QUICK_SORT__

#include "Common.h"

//�������У���С����  ,���� [0,nLen )
template <typename T>
void QuickSort(T arr[], int nLen)
{
	srand(time(NULL));
	__qucikSort(arr, 0, nLen-1);
}

//�������У���С����  ,���� [idxL,idxR]
template <typename T>
void __qucikSort(T arr[], int idxL, int idxR)
{
	//�Ż�����2�����������������Ƭ�ζ̵�һ������ʱ��ת���ò������򷽷�����
	if (idxR - idxL < 16)
	{
		InsertionSort_Part(arr, idxL, idxR);
		return;
	}
	int nAnchorIdx = __partition(arr, idxL, idxR);
	__qucikSort(arr, idxL, nAnchorIdx);
	__qucikSort(arr, nAnchorIdx + 1, idxR);
}

//������[idxL,idxR]��Ԫ�ؽ���partition�������趨�ο�ê��ֵAnchor����ߵ�Ԫ��С��Anchor,�ұ�Ԫ�ش���Anchor
template <typename T>
int __partition(T arr[], int idxL, int idxR)
{
	//�Ż�����1��Ϊ���⼫�������������Ӷȣ������һ��ê��ֵ�ŵ���һ��Ԫ�ص�λ��
	int nRandIdx = (int)(idxL +  (rand() % (idxR - idxL + 1 )));
	swap(arr[idxL], arr[nRandIdx]);

	T Anchor = arr[idxL];
	int left  = idxL+1;
	int right = idxR;
	while (true)
	{
		while (arr[left]<Anchor && left <= idxR)left++;
		while (arr[right]>Anchor && idxL < right)right--;
		if (left > right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	//���ˣ����λ�ù�ϵΪright ... left
	//��arr[right]�����һ�� �� Anchror��Ԫ�أ�arr[left]�ǵ�һ����  Anchror��Ԫ��
	swap(arr[idxL], arr[right]);
	return right;
}











#endif