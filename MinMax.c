#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

// Recursive function to find max and min
void maxmin(int arr[], int low, int high, int *maxi, int *mini)
{
    // If only one element
    if (low == high)
    {
        *maxi = *mini = arr[low];
        return;
    }

    // If two elements
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            *maxi = arr[low];
            *mini = arr[high];
        }
        else
        {
            *maxi = arr[high];
            *mini = arr[low];
        }
        return;
    }

    // If more than two elements
    int mid = (low + high) / 2;
    int max1, min1, max2, min2;

    maxmin(arr, low, mid, &max1, &min1);
    maxmin(arr, mid + 1, high, &max2, &min2);

    *maxi = max(max1, max2);
    *mini = min(min1, min2);
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter elements: ");
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxi, mini;
    maxmin(arr, 0, n - 1, &maxi, &mini);

    printf("Array: ");
    printArray(arr, n);
    printf("Maximum: %d\n", maxi);
    printf("Minimum: %d\n", mini);

    return 0;
}
