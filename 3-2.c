#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

/********************************************************************************

2018-1학기 알고리즘 및 실습

3주차 실습 [문제 2]

2018/10/7

상향식 힙생성 구현 > 3-1 의 downheap을 가져와서 그대로 사용

시간복잡도가 O(n)인 이유에 대해서 좀더 고민

*********************************************************************************/

void swap(int *heap, int index1, int index2)
{
	int tmp;
	tmp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = tmp;
}

void downheap(int *heap, int current, int last)
{
	if (last < current * 2) return;
	else if (last > current * 2)
	{
		if (heap[current * 2] >= heap[current * 2 + 1])
		{
			if (heap[current] < heap[current * 2])
			{
				swap(heap, current, current * 2);
				downheap(heap, current * 2, last);
			}
			else return;
		}
		else if (heap[current * 2] < heap[current * 2 + 1])
		{
			if (heap[current] < heap[current * 2 + 1])
			{
				swap(heap, current, current * 2 + 1);
				downheap(heap, current * 2 + 1, last);
			}
			else return;
		}
	}
	else if (last == current * 2)
	{
		if (heap[current] < heap[current * 2])
		{
			swap(heap, current, current * 2);
			downheap(heap, current * 2, last);
		}
		else return;
	}
	else printf("error");
}

void print_heap(int *heap, int *last)
{
	int i;

	for (i = 1; i <= *last; i++)
	{
		printf(" %d", heap[i]);
	}
}

void *build_heap(int *heap, int current, int last)
{
	if (last < current * 2) return;

	build_heap(heap, current * 2, last);
	build_heap(heap, current * 2 + 1, last);
	downheap(heap, current, last);

	return;
}

int main()
{
	int heap[101], last = 0;
	char func;
	int flag = 0, tmp, n, i;


	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &heap[i]);
	}

	build_heap(&heap, 1, n);

	print_heap(&heap, &n);
	return 0;
}
