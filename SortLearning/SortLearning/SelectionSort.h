#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

//ѡ������
//�������У���С����  ,���� [0,nLen )
template <typename T>
void SelectionSort(T arr[], int nLen)
{
	if (nullptr == arr || nLen <2)
	{
		return;
	}
	for (int ii = 0; ii < nLen-1; ii++)
	{
		T nTargetMin = arr[ii];//һ��ѡ���е���Сֵ,�Ż��㷨����
		int nTargetIndex = ii;//һ��ѡ���е���Сֵ��Ӧ�������ţ���������Targetֵ��������Ŀ���Ǳ���Ƶ����swap����
		for (int jj = ii + 1; jj < nLen; jj++)
		{
			if (arr[jj] < nTargetMin)
			{
				nTargetMin = arr[jj];
				nTargetIndex = jj;
			}
		}
		swap(arr[ii], arr[nTargetIndex]);
	}
}






#endif