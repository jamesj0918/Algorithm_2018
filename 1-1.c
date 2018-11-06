/********************************************************************************

2018-1학기 알고리즘 및 실습

1주차 실습 [문제 1]

2018/09/06

*********************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)

typedef struct Node
{
	struct Node *prev, *next;
	char elem;
}Node;

Node *create_node()
{
	Node *newnode;
	newnode = (Node *)malloc(sizeof(Node));
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void add(int position, Node *head, Node *tail, char c)
{
	int i;
	Node *tmp = head;
	Node *newnode = create_node();
	for (i = 0; i < position; i++)
	{
		tmp = tmp->next;
		if (tmp == NULL)
		{
			printf("invalid position\n");
			return;
		}
	}

	tmp->prev->next = newnode;
	newnode->prev = tmp->prev;
	tmp->prev = newnode;
	newnode->next = tmp;
	newnode->elem = c;

	tmp = NULL;
	free(tmp);
}

void print(Node *head, Node *tail)
{
	Node *tmp;

	for (tmp = head->next; tmp != tail->next; tmp = tmp->next)
	{
		printf("%c", tmp->elem);
	}
	printf("\n");
	tmp = NULL;
	free(tmp);
}

void init(Node *head, Node *tail)
{
	head->next = tail;
	tail->prev = head;
}

void get_entry(int position, Node *head, Node *tail)
{
	int i;
	Node *tmp = head;

	for (i = 0; i < position; i++)
	{
		tmp = tmp->next;
		if (tmp == NULL || tmp == tail)
		{
			printf("invalid position\n");
			return;
		}
	}

	printf("%c\n", tmp->elem);
	tmp = NULL;
	free(tmp);
}

void delete_node(int position, Node *head, Node *tail)
{
	int i;
	Node *tmp = head;

	for (i = 0; i < position; i++)
	{
		tmp = tmp->next;
		if (tmp == NULL || tmp == tail)
		{
			printf("invalid position\n");
			return;
		}
	}

	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp = NULL;
	free(tmp);

}

int main(int argc, char const *argv[])
{
	Node *head, *tail;
	int n, i, position;
	char c, tmp;

	head = create_node();
	tail = create_node();

	init(head, tail);
	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; i++)
	{
		scanf("%c", &c);
		getchar();
		switch (c)
		{
		case 'A':
			scanf("%d", &position);
			getchar();
			scanf("%c", &tmp);
			getchar();
			if (position <= 0)
			{
				printf("invalid position\n");
				break;
			}
			add(position, head, tail, tmp);
			break;
		case 'P':
			print(head, tail);
			break;
		case 'G':
			scanf("%d", &position);
			getchar();
			if (position <= 0)
			{
				printf("invalid position\n");
				break;
			}
			get_entry(position, head, tail);
			break;
		case 'D':
			scanf("%d", &position);
			getchar();
			if (position <= 0)
			{
				printf("invalid position\n");
				break;
			}
			delete_node(position, head, tail);
			break;
		default:
			printf("invalid input");
			break;
		}
	}


	free(head);
	free(tail);

	return 0;
}
