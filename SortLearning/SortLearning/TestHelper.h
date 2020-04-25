#ifndef  __TEST_HELPER_H__
#define  __TEST_HELPER_H__

#include "Common.h"


//����ʱ��(��λ����)������С�����ļ�λ
#define DECIMAL_PRECISION   3    

namespace SortTestHelper
{
	//����һ������nLen��������飬��ΧΪ[minVal,maxVal],��ʼ�������ΪnSwapTimes
	template <typename T>
	T* NewRandArr(int nLen, T minVal, T maxVal)
	{
		assert(minVal < maxVal);
		srand((unsigned int)time(NULL));
		T *pRandArr = new T[nLen];
		for (int ii = 0; ii < nLen; ii++)
		{
			pRandArr[ii] = rand() % (maxVal - minVal + 1) + minVal;
		}
		return pRandArr;
	}

	//����һ������nLen�Ľ�����������飬startValΪ��ʼֵ���½�����ʱ�Ĳ���Ϊinterval,�����������������nSwapTime��
	template <typename T>
	T* NewAlmostRandArr(int nLen, T startVal, T interval, int nSwapTimes)
	{
		srand(time(NULL));
		T *pRandArr = new T[nLen];
		for (int ii = 0; ii < nLen; ii++)
		{
			pRandArr[ii] = startVal + ii*interval;
		}
		for (int jj = 0; jj < nSwapTimes; jj++)
		{
			int Index1 = rand() % nLen;
			int Index2 = rand() % nLen;
			swap(pRandArr[Index1],pRandArr[Index2]);
		}
		return pRandArr;
	}

	//�ͷſռ�
	template <typename T>
	bool DeleteRandArr(T* &pRandArr)
	{
		if (nullptr != pRandArr)
		{
			delete[]pRandArr;
			pRandArr = nullptr;
		}
		else{
			return false;
		}
		
		return true;
	}

	//��ӡһ������
	template <typename T>
	void PrintArr(string strArrName, T arr[], int nLen,int nDataBitWidth=0)
	{
		cout << strArrName.c_str() << " is :" << endl;
		for (int ii = 0; ii < nLen; ii++)
		{
			if (0 != nDataBitWidth)//���ô�ӡʱ���λ��
			{
				cout <<setw(nDataBitWidth)<< arr[ii] << " ";
			}
			else{
				cout << arr[ii] << " ";
			}

			
			if (0 == (ii+1) % 20)
			{
				cout << endl;
			}
		}
	}

	//����һ�������� ,ע�⺯��ָ����÷�
	template <typename T>
	void  TestSortPerform(string strSortName, void (*pSortFunc)(T[], int), T arr[], int nLen)
	{
		clock_t tStartTime = clock();
		pSortFunc(arr, nLen);
		clock_t tStopTIme = clock();
		if (!IsSorted(arr, nLen))
		{
			cout << "Array haven't been sorted!" << endl;
			return;
		}
		///����һ���ĸ��㾫��
		cout << setiosflags(ios::fixed);//��֤setprecision()������С������λ��,������������С����λ��
		cout << strSortName.c_str() << ":" << setprecision(DECIMAL_PRECISION) << double(tStopTIme - tStartTime) / CLOCKS_PER_SEC << "s" << endl;
	}

	//�ж�һ�������Ƿ��Ǵ�С��������ɹ���
	template <typename T>
	bool IsSorted(T arr[],int nLen)
	{
		for (int ii = 0; ii < nLen-1; ii++)
		{
			if (arr[ii] > arr[ii + 1])
			{
				return false;
			}
		}
		return true;
	}

	template <typename T>
	T*  NewCopyArray( T*arrSrc, int nLen)
	{
		T *pNewCopyArr = new T[nLen];
		memcpy_s(pNewCopyArr, nLen*sizeof(T),arrSrc, nLen*sizeof(T));
		return pNewCopyArr;
	}
	
};
#endif