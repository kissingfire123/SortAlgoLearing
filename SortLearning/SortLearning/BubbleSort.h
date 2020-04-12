#ifndef  __BUBBLE_SORT__
#define  __BUBBLE_SORT__
#include "Common.h"


//�������У���С����
template <typename T>
void BubbleSort(T arr[], int nLen)
{
	if (nullptr == arr || nLen <2)
	{
		return;
	}
	//�Ż�1�������һ��û�з������������������ǰ���
	bool nSwappedFlag = false;
	//�Ż�2�����ڵ�ii�֣���¼����Ǹ�����������λ��idx����һ��ii��ֱ�Ӵ�idx��ʼ������ֲ������е��ظ�����. eg:ԭʼ6,4,7,5,1,3,2
	int  nLastLoopSwapIdx = 0;
	int  nSwapTimes = nLen - 1;
	for (int ii =nLen - 1; ii > 0; ii--)
	{
		nSwappedFlag = false; 
		for (int jj = 0; jj < nSwapTimes /*ii*/; jj++)//nSwapTimes�滻ii�������ڲ�ѭ��
		{
			if (arr[jj] > arr[jj + 1])
			{
				swap(arr[jj], arr[jj + 1]);
				nSwappedFlag = true;
				nLastLoopSwapIdx = jj;
			}
		}
		nSwapTimes = nLastLoopSwapIdx;
		if (!nSwappedFlag)
		{
			return;
		}
	}
}


#endif