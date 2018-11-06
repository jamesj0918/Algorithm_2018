#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int n, int search_num)
{
    int mid = n/2, left = 0, right = n - 1;

    if(search_num > arr[right]) return n;
    if(search_num <= arr[0]) return 0;

    while(1)
    {

        if(arr[mid] > search_num)
        {
            right = mid;
            mid = (left + right)/2;
        }

        else if (arr[mid] < search_num)
        {
            left = mid;
            mid = (left + right)/2;
        }
        else return mid; // arr[mid] == search_num
        if(mid == left) return left + 1;
    }

}

int binary_search_recursive(int *arr, int search_num, int left, int mid, int right)
{

    if(arr[right] <= search_num) return right;
    if(arr[left] > search_num) return -1;
    if(mid == left) return mid;

    if(arr[mid] > search_num) return binary_search_recursive(arr, search_num, left, (left+mid)/2, mid);
    else if (arr[mid] < search_num) return binary_search_recursive(arr, search_num, mid, (right+mid)/2, right);
    else return mid;
}

int main()
{
    int *arr;
    int n, search_num, i;

    scanf("%d %d" ,&n, &search_num);

    arr = malloc(sizeof(int) * n);

    for(i=0; i<n; i++) scanf("%d", &arr[i]);

    printf(" %d", binary_search_recursive(arr, search_num, 0, n/2, n-1));

    return 0;
}