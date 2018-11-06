/********************************************************************************

2018-1학기 알고리즘 및 실습

1주차 실습 [문제 2]

2018/09/13

find_root 할때 두번째 for문 안에 j=0부터 시작해야 tree에 마지막 노드가 root노드일
경우를 커버할 수 있음 이것 때문에 애먹음.

*********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
typedef struct Node
{
	struct Node *left, *right;
	int data, ldata, rdata;
}Node;

Node *create_node(int data, int ldata, int rdata)
{
	Node *newnode;
	newnode = (Node *)calloc(1,sizeof(Node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = data;
	newnode->ldata = ldata;
	newnode->rdata = rdata;

	return newnode;
}

Node *find_root(Node **tree, int n)
{
	int i, j;
	int cnt = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (tree[i]->data == tree[j]->ldata || tree[i]->data == tree[j]->rdata) cnt++;
		}
		if (cnt == 0) return tree[i];
		else cnt = 0;
	}
}

void link_node(Node **tree, Node *root, int n)
{
	int i;

	if (root->ldata == 0 && root->rdata == 0) return;

	for (i = 0; i < n; i++)
	{
		if (tree[i]->data == root->ldata)
		{
			root->left = tree[i];
			link_node(tree, root->left, n);
		}
		if (tree[i]->data == root->rdata)
		{
			root->right = tree[i];
			link_node(tree, root->right, n);
		}
	}
	return;
}

void print_tree(Node *root, char command[])
{
	int i;
	Node *tmp = root;

	for (i = 0; i < strlen(command) + 1; i++)
	{
		printf(" %d", tmp->data);

		if (command[i] == 'L') tmp = tmp->left;
		else if (command[i] == 'R') tmp = tmp->right;
	}
	printf("\n");
	return;
}
int main()
{
	int n, i;
	int data, ldata, rdata;
	char command[101];

	scanf("%d", &n);

	Node **tree = (Node **)calloc(n,sizeof(Node *));
	Node *root;

	for (i = 0; i < n; i++) //Ʈ���� �����ϴ� ���� ���带 ���� �Է¹޴´�.
	{
		scanf("%d %d %d", &data, &ldata, &rdata);
		tree[i] = create_node(data, ldata, rdata);
	}

	root = find_root(tree, n);

	link_node(tree, root, n);

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", command);
		print_tree(root, command);
	}


	return 0;
}
