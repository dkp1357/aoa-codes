#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

void printArray(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// returns 1 if a queen can be placed at `k` row and `i` column 
int place(int k, int i, int x[], int n)
{
    for (int j = 0; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return 0;
        }
    }
    return 1;
}

void nQueens(int k, int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (place(k, i, x, n) == 1)
        {
            x[k] = i;
            if (k == n-1)
            {
                count++;
                printArray(x, n);
                printf("\n");
            }
            else 
            {
                nQueens(k+1, x, n);
            }
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);

    int x[n];
    printf("\n");
    nQueens(0, x, n);
    printf("\nno of answers: %d", count);
    return 0;
}
