// incomplete

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[minIdx] > arr[j])
                minIdx = j;

        swap(arr[minIdx], arr[i]);
    }
}

void merge(int arr[], int start, int mid, int end)
{
    int merged[end - start + 1];
    int append = 0;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            merged[append++] = arr[i++];
        else
            merged[append++] = arr[j++];
    }

    while (i <= mid)
        merged[append++] = arr[i++];
    while (j <= end)
        merged[append++] = arr[j++];

    for (i = 0; i < end - start + 1; i++)
        arr[i + start] = merged[i];
}

void mergeSort(int arr[], int start, int end)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}