#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#pragma warning (disable:4996)

/********************************************************************************

2018-1학기 알고리즘 및 실습

2주차 실습 [문제 3]

2018/09/25

삽입정렬, 선택정렬  시간비교.

시간복잡도에 대한 보고서 첨부.
정밀한 실행시간 계산 -> windows.h 의 QueryPerformanceCounter 

*********************************************************************************/

void insertion_sort(int *arr, int n)
{
	int tmp;
	int *p, *q;


	for (p = arr + 1; p < arr + n; p++)
	{
		tmp = *p;
		for (q = p; q > arr; q--)
		{
			if (*(q - 1) < tmp) break;
			*q = *(q - 1);
		}
		*q = tmp;
	}
}
void selection_sort(int *arr, int n)
{
	int *p, *q;
	int max, tmp, *p_max = arr;
	int flag;

	for (p = arr + n - 1; p >= arr; p--)
	{
		max = *p;
		flag = 0;
		for (q = p; q >= arr; q--)
		{
			if (*q > max)
			{
				max = *q;
				p_max = q;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			tmp = *p;
			*p = *p_max;
			*p_max = tmp;
		}
	}

}
void reverse_array(int *arr, int start, int end)
{
	int temp;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

int main()
{
	int *arr1, *arr2;
	int n, i;

	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;
	double elapsed_time;

	QueryPerformanceFrequency(&frequency);

	scanf("%d", &n);

	arr1 = (int *)malloc(sizeof(int)*n);
	arr2 = (int *)malloc(sizeof(int)*n);

	srand(time(NULL));

	for (i = 0; i < n; i++)
	{
		arr1[i] = rand();
	}
	//insertion_sort(arr1, n);  //<< ���ĵ� ������ ���Խ� �ּ�ó�� ����
	//reverse_array(arr1, 0, n - 1); //<< ������ ������ ���Խ� �ּ�ó�� ����
	for (i = 0; i < n; i++) arr2[i] = arr1[i];


	QueryPerformanceCounter(&t1);
	selection_sort(arr1, n);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec

	printf("Time by selection sort: %lf ms\n", elapsed_time);

	QueryPerformanceCounter(&t1);
	insertion_sort(arr2, n);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec

	printf("Time by insertion sort: %lf ms\n", elapsed_time);



	free(arr1);
	free(arr2);

	return 0;
}
