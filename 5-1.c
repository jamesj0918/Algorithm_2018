#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

Node *merge(Node *left, Node *right, int cnt)
{
	int i;
	Node *tmp, *tmp2;

	if (left->data <= right->data)
	{
		tmp = left;
		left = left->next;
	}
	else
	{
		tmp = right;
		right = right->next;
	}
	tmp2 = tmp;

	while (1)
	{
		if (left == NULL)
		{
			tmp->next = right;
			break;
		}
		else if (right == NULL)
		{
			tmp->next = left;
			break;
		}

		if (left->data <= right->data)
		{
			tmp->next = left;
			left = left->next;
			tmp = tmp->next;
		}
		else
		{
			tmp->next = right;
			right = right->next;
			tmp = tmp->next;
		}
	}

	return tmp2;

}

void divide(Node *node, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		node = node->next;
	}
	node->next = NULL;
}

Node *create_node(int data)
{
	Node *newnode = (Node *)malloc(sizeof(Node));

	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}

Node *merge_sort(Node *node, int cnt)
{
	int n, i;
	Node *left, *right;
	if (node->next == NULL) return node;

	left = node;
	right = node;

	for (i = 0; i < cnt / 2; i++)
	{
		right = right->next;
	}


	divide(node, cnt / 2 - 1);
	left = merge_sort(left, cnt / 2);
	if (cnt % 2 == 1) right = merge_sort(right, cnt / 2 + 1);
	else right = merge_sort(right, cnt / 2);
	merge(left, right, cnt);

	if (left->data <= right->data) return left;
	else return right;

}

int main()
{
	int n, i, tmp;
	Node *node;

	scanf("%d", &n);

	node = (Node *)malloc(sizeof(Node)*n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		node[i] = *create_node(tmp);
	}
	for (i = 0; i < n - 1; i++)
	{
		node[i].next = &node[i + 1];
	}

	node = merge_sort(node, n);

	while (node != NULL)
	{
		printf(" %d", node->data);
		node = node->next;
	}

	free(node);

	return 0;
}
