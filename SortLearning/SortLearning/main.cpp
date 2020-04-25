#include "Common.h"
#include "TestHelper.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

#define SORT_KINDS_NUM 4 

int main()
{
	int nArrayLen = 10000;
	int nSwapTimes = 20;
	int * ppTestArray[3 * SORT_KINDS_NUM] = { 0 };  //��3�����͵Ĳ������ݣ������� SORT_KINDS_NUM �ִ����Ե����򷽷�

	//SortTestHelper::PrintArr("RandomArr", (int*)pRandArr1, nArrayLen, 4);  //For ����
	//�������
	//����һ���������
	ppTestArray[0] = SortTestHelper::NewRandArr<int>(nArrayLen, 0, nArrayLen);
	for (int ii = 1; ii < SORT_KINDS_NUM; ii++)
	{
		ppTestArray[ii] = SortTestHelper::NewCopyArray<int>(ppTestArray[0], nArrayLen);
	}
	cout << endl << "Sort a array which is complete random :" <<"  DataLen="<<nArrayLen<<endl;
	//SortTestHelper::TestSortPerform("Bubble Sort", BubbleSort,    ppTestArray[0], nArrayLen);
	SortTestHelper::TestSortPerform("Select Sort", SelectionSort, ppTestArray[1], nArrayLen);
	SortTestHelper::TestSortPerform("Insert Sort", InsertionSort, ppTestArray[2], nArrayLen);
	SortTestHelper::TestSortPerform("Merge  Sort", MergeSort,     ppTestArray[3], nArrayLen);

	//����һ���������������
	cout << endl << "Sort a array which is nearly sorted :" << "  DataLen=" << nArrayLen << endl;
	ppTestArray[SORT_KINDS_NUM] = SortTestHelper::NewAlmostRandArr<int>(nArrayLen, 0, 1, nSwapTimes);
	for (int ii = SORT_KINDS_NUM + 1; ii < 2*SORT_KINDS_NUM; ii++)
	{
		ppTestArray[ii] = SortTestHelper::NewCopyArray<int>(ppTestArray[SORT_KINDS_NUM], nArrayLen);
	}
	//SortTestHelper::TestSortPerform("Bubble Sort", BubbleSort,    ppTestArray[SORT_KINDS_NUM],     nArrayLen);
	SortTestHelper::TestSortPerform("Select Sort", SelectionSort, ppTestArray[SORT_KINDS_NUM + 1], nArrayLen);
	SortTestHelper::TestSortPerform("Insert Sort", InsertionSort, ppTestArray[SORT_KINDS_NUM + 2], nArrayLen);
	SortTestHelper::TestSortPerform("Merge  Sort", MergeSort,     ppTestArray[SORT_KINDS_NUM + 3], nArrayLen);

	//����һ���д����ظ�Ԫ�ص�����
	cout << endl << "Sort a array which contains many same element :" << "  DataLen=" << nArrayLen << endl;
	ppTestArray[2 * SORT_KINDS_NUM] = SortTestHelper::NewRandArr<int>(nArrayLen, 0, 5);
	for (int ii = 2 * SORT_KINDS_NUM + 1; ii < 3 * SORT_KINDS_NUM; ii++)
	{
		ppTestArray[ii] = SortTestHelper::NewCopyArray<int>(ppTestArray[2 * SORT_KINDS_NUM], nArrayLen);
	}

	//SortTestHelper::TestSortPerform("Bubble Sort", BubbleSort,    ppTestArray[2 * SORT_KINDS_NUM],     nArrayLen);
	SortTestHelper::TestSortPerform("Select Sort", SelectionSort, ppTestArray[2 * SORT_KINDS_NUM + 1], nArrayLen);
	SortTestHelper::TestSortPerform("Insert Sort", InsertionSort, ppTestArray[2 * SORT_KINDS_NUM + 2], nArrayLen);
	SortTestHelper::TestSortPerform("Merge  Sort", MergeSort,     ppTestArray[2 * SORT_KINDS_NUM + 3], nArrayLen);

	for (int ii = 0; ii < 3 * SORT_KINDS_NUM; ii++)
	{
		SortTestHelper::DeleteRandArr <int>(ppTestArray[ii]);
	}

	cout << endl << "There are all results above ..." << endl;
	getchar();
	return 0;
}

///         �������Խ���������Լ��ľɵ��ԣ�Ӧ���ǻ�ƫ����i3-2330M��hp���ԣ��Լ�����ssd���ڴ棩��8��ǰ�����[����]
//���н�����£� V1.0.1
/*
Sort a array which is complete random : DataLen = 1000
Bubble Sort : 0.052s
Select Sort : 0.002s
Insert Sort : 0.054s

Sort a array which is nearly sorted : DataLen = 1000
Bubble Sort : 0.005s
Select Sort : 0.002s
Insert Sort : 0.004s

Sort a array which contains many same element : DataLen = 1000
Bubble Sort : 0.046s
Select Sort : 0.002s
Insert Sort : 0.04s
*/



//���н�����£� V1.0.2
//�Ż��˲�������
/*
Sort a array which is complete random : DataLen = 1000
Bubble Sort : 0.056s
Select Sort : 0.002s
Insert Sort : 0.001s

Sort a array which is nearly sorted : DataLen = 1000
Bubble Sort : 0.003s
Select Sort : 0.002s
Insert Sort : 0.001s

Sort a array which contains many same element : DataLen = 1000
Bubble Sort : 0.033s
Select Sort : 0.002s
Insert Sort : 0.001s
*/


//���н�����£� V1.0.3
//�����˹鲢����(δ�Ż��Ĺ鲢)
/*���ݳ���1000
Sort a array which is complete random : DataLen = 1000
Bubble Sort : 0.056s
Select Sort : 0.002s
Insert Sort : 0.001s
Merge  Sort : 0.002s

Sort a array which is nearly sorted : DataLen = 1000
Bubble Sort : 0.004s
Select Sort : 0.002s
Insert Sort : 0s
Merge  Sort : 0.002s

Sort a array which contains many same element : DataLen = 1000
Bubble Sort : 0.035s
Select Sort : 0.002s
Insert Sort : 0.001s
Merge  Sort : 0.003s
*/
/* ���ݳ���10000
Sort a array which is complete random :  DataLen=10000
Bubble Sort:4.498s
Select Sort:0.206s
Insert Sort:0.106s
Merge  Sort:0.02s

Sort a array which is nearly sorted :  DataLen=10000
Bubble Sort:0.183s
Select Sort:0.197s
Insert Sort:0.000s
Merge  Sort:0.019s

Sort a array which contains many same element :  DataLen=10000
Bubble Sort:3.72s
Select Sort:0.195s
Insert Sort:0.099s
Merge  Sort:0.02s
*/  

//���н�����£� V1.0.4
//�����˹鲢����(�Ż���Ĺ鲢)
/* ���ݳ���10000
Sort a array which is complete random : DataLen = 10000
Select Sort : 0.194s
Insert Sort : 0.105s
Merge  Sort : 0.006s

Sort a array which is nearly sorted : DataLen = 10000
Select Sort : 0.191s
Insert Sort : 0.001s
Merge  Sort : 0.002s

Sort a array which contains many same element : DataLen = 10000
Select Sort : 0.195s
Insert Sort : 0.078s
Merge  Sort : 0.004s

There are all results above ...
*/