#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int list[MAX_SIZE];
int k = 0;
int count = 0;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// s = sum 
void sumOfSubsets(int idx, int s, int arr[], int n, int t)
{
    if (idx == n) {
        if (s == t) {
            count++;
            printf("\n");
            printArray(list, k);
        }
        return;
    }

    // take
    list[k] = arr[idx];
    k++;
    sumOfSubsets(idx+1, s+arr[idx], arr, n, t);
    // not take
    k--;
    sumOfSubsets(idx+1, s, arr, n, t);
}

int main()
{
    int n;
    printf("enter number of elements: ");
    scanf("%d", &n);  

    int arr[n];
    printf("enter elements: "); 
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int t;
    printf("enter target: ");
    scanf("%d", &t);

    sumOfSubsets(0, 0, arr, n, t);
    printf("\nno of answers: %d", count);
    return 0;
}
