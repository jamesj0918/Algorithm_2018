#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

/********************************************************************************

2018-1학기 알고리즘 및 실습

2주차 실습 [문제 1]

2018/09/20

선택정렬 내가 구현한 코드. 추후 인터넷에있는 코드와 비교 해볼것.

*********************************************************************************/

void selection_sort(int *arr, int n)
{
	int *p ,*q;
	int min, tmp, *p_min= arr;
	int flag;


	for (p = arr; p < arr + n; p++)
	{
		min = *p;
		flag = 0;
		for (q = p; q < arr + n; q++)
		{
			if (*q < min)
			{
				min = *q;
				p_min = q;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			tmp = *p;
			*p = *p_min;
			*p_min = tmp;
		}
	}

}


int main()
{
	int *arr;
	int n, i;

	scanf("%d", &n);

	arr = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	selection_sort(arr, n);

	for (i = 0; i < n; i++) printf(" %d", arr[i]);



	return 0;
}
