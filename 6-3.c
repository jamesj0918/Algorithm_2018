#include <stdio.h>
#include <stdlib.h>

int find_number(int a, int b, char *arr)
{
    int mid = (a+b)/2;

    if (a == b) return a;

    if (*arr == 'Y') return find_number(mid+1, b, ++arr);
    else return find_number(a, mid, ++arr);

}

int main()
{
    int a,b,n;
    char *arr;


    scanf("%d %d %d",&a, &b, &n);
    getchar();

    arr = malloc(sizeof(char)*n);

    scanf("%s",arr);

    printf("%d",find_number(a, b, arr));


    return 0;
}