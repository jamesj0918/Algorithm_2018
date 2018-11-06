#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

/********************************************************************************

2018-1학기 알고리즘 및 실습

3주차 실습 [문제 1]

2018/9/28

Heap 개념공부, Heap 생성과 Downheap, Upheap 구현

print_max 에서 downheap 호출할떄 *last 가 아닌 last로 해서 오류 발생 -> 수정완료

*********************************************************************************/


void swap(int *heap, int index1, int index2)
{
	int tmp;
	tmp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = tmp;
}

void upheap(int *heap, int last)
{

	int tmp;
	if (last == 1) return;
	if (heap[last / 2] > heap[last]) return;
	else
	{
		swap(heap, last, last / 2);
		upheap(heap, last / 2);
	}

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

void insert_item(int *heap, int *last, int tmp)
{

	(*last)++;
	heap[*last] = tmp;
	upheap(heap, *last);
}

int print_max(int *heap, int *last)
{
	int tmp;

	tmp = heap[1];
	heap[1] = heap[*last];
	(*last)--;

	if (last == 0) return tmp;

	downheap(heap, 1, *last);

	return tmp;
}

void print_heap(int *heap, int *last)
{
	int i;

	for (i = 1; i <= *last; i++)
	{
		printf(" %d", heap[i]);
	}
}


int main()
{
	int heap[101], last = 0;
	char func;
	int flag = 0, tmp;


	while (1)
	{
		scanf("%c", &func);
		switch (func)
		{
		case 'q':
		{
			flag = 1;
			break;
		}

		case 'i':
		{
			getchar();
			scanf("%d", &tmp);
			getchar();
			insert_item(&heap, &last, tmp);
			printf("0\n");
			break;
		}

		case 'p':
		{
			if (last != 0)
			{
				print_heap(&heap, &last);
				printf("\n");
			}
			break;
		}

		case 'd':
		{
			getchar();
			printf("%d\n", print_max(heap, &last));
			break;
		}

		}
		if (flag == 1) break;
	}



	return 0;
}
