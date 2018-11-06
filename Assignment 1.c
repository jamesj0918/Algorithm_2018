#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int merge_count = 0;

typedef struct Node
{
	int data;
	struct Node *next, *prev, *up, *down;
}Node;

Node *create_node(int data)
{
	Node *newnode = (Node *)malloc(sizeof(Node));

	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->up = NULL;
	newnode->down = NULL;

	return newnode;
}

void swap(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void quick_sort(Node **node, int left, int right)
{
	int i = left, j = right;
	int pivot = node[(left + right) / 2]->data;
	int temp;
	do
	{
		while (node[i]->data < pivot)
			i++;
		while (node[j]->data > pivot)
			j--;
		if (i <= j)
		{
			swap(&node[i]->data, &node[j]->data);
			swap(&node[i]->next->data, &node[j]->next->data);
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		quick_sort(node, left, j);

	if (i < right)
		quick_sort(node, i, right);
}

Node *init_link(int n1, int n2)
{
	Node *node1 = create_node(n1);
	Node *node2 = create_node(n2);

	node1->next = node2;
	node1->prev = NULL;
	node1->next->prev = node1;

	return node1;
}

Node *merge_node(Node *node1, Node *node2)
{
	Node *tmp1 = node1, *tmp2 = node2;
	Node *merged_node = (Node *)malloc(sizeof(Node)), *tmp_merged, *tmp_merged2;

	tmp_merged2 = merged_node;

	while (1)
	{
		if (tmp1 == NULL && tmp2 == NULL) break;
		if (tmp1 == NULL)
		{
			while (tmp2 != NULL)
			{
				tmp_merged = create_node(tmp2->data);

				tmp_merged2->next = tmp_merged;
				tmp_merged->prev = tmp_merged2;

				tmp2 = tmp2->next;

				tmp_merged2 = tmp_merged2->next;
				tmp_merged = NULL;
			}
			break;
		}
		if (tmp2 == NULL)
		{
			while (tmp1 != NULL)
			{
				tmp_merged = create_node(tmp1->data);

				tmp_merged2->next = tmp_merged;
				tmp_merged->prev = tmp_merged2;

				tmp1 = tmp1->next;

				tmp_merged2 = tmp_merged2->next;
				tmp_merged = NULL;

			}
			break;
		}

		if (tmp1->data == tmp2->data)
		{
			tmp_merged = create_node(tmp1->data);

			tmp_merged2->next = tmp_merged;
			tmp_merged->prev = tmp_merged2;

			tmp1 = tmp1->next;
			tmp2 = tmp2->next;

			tmp_merged2 = tmp_merged2 -> next;
			tmp_merged = NULL;

			continue;
		}
		else if (tmp1->data < tmp2->data)
		{
			tmp_merged = create_node(tmp1->data);

			tmp_merged2->next = tmp_merged;
			tmp_merged->prev = tmp_merged2;

			tmp1 = tmp1->next;

			tmp_merged2 = tmp_merged2->next;
			tmp_merged = NULL;

			continue;
		}
		else
		{
			tmp_merged = create_node(tmp2->data);

			tmp_merged2->next = tmp_merged;
			tmp_merged->prev = tmp_merged2;

			tmp2 = tmp2->next;

			tmp_merged2 = tmp_merged2->next;
			tmp_merged = NULL;

			continue;
		}
	}
	merged_node->next->down = node1->down;
	merged_node->next->up = node1->up;

	return (merged_node->next);
}

Node *compare_node(Node *node1, Node *node2)
{
	Node *tmp1 = node1, *tmp2 = node2;

	while (tmp1 != NULL && tmp2 != NULL)
	{
		if (tmp1->data == tmp2->data)
		{
			merge_count++;
			node1 = merge_node(node1, node2);
			break;
		}
		else if (tmp1->data < tmp2->data) tmp1 = tmp1->next;
		else tmp2 = tmp2->next;
	}
	return node1;
}

int main()
{
	int n, i;
	int n1, n2;

	Node **node;
	Node *tmp, *tmp2;

	scanf("%d", &n);

	node = (Node **)malloc(sizeof(Node *)*n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &n1, &n2);

		if (n1 > n2) swap(&n1, &n2);

		node[i] = init_link(n1, n2);
	}

	quick_sort(node, 0, n - 1); //입력 받을때 부터 정렬한다.

	for (i = 0; i < n - 1; i++)
	{
		node[i]->down = node[i + 1]; //Down연결 해준다
		node[i + 1]->up = node[i]; //Up 연결 해준다
	}
	node[n - 1]->down = node[0]; // 마지막 노드의 down은 첫 노드로 연결시켜서 원형으로 구현
	node[n - 1]->up = node[n - 2];
	node[0]->up = node[n - 1];

	tmp = node[0];

	while (1)
	{
		while (1)
		{
			merge_count = 0;
			tmp2 = tmp->down;
			if (tmp2 == node[0]) break;
			while (1)
			{
				merge_count = 0;
				*tmp = *compare_node(tmp, tmp2);

				if (merge_count > 0)
				{
					tmp2->up->down = tmp2->down;
					tmp2->down->up = tmp2->up;
				}

				tmp2 = tmp2->down;
				if (tmp2 == node[0]) break;
			}
			if (merge_count == 0) break;
		}

		tmp = tmp->down;
		if (tmp == node[0]) break;
	}

	tmp = node[0];

	while (1)
	{
		tmp2 = tmp;
		while (tmp2 != NULL)
		{
			printf(" %d", tmp2->data);
			tmp2 = tmp2->next;
		}
		tmp = tmp->down;
		if (tmp == node[0]) break;
		printf("\n");
	}

	return 0;
}
