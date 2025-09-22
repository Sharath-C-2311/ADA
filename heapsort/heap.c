#include <stdio.h>
#include <stdlib.h>

int count = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int i, int n)
{
    int large = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    count++;
    if (left <= n && arr[left] > arr[large])
    {
        large = left;
    }
    if (right <= n && arr[right] > arr[large])
    {
        large = right;
    }
    if (large != i)
    {
        swap(&arr[i], &arr[large]);
        heapify(arr, large, n);
    }
}

void heapsort(int *arr, int n)
{

    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, i, n);
    }

    for (int i = n; i > 1; i--)
    {
        swap(&arr[1], &arr[i]);
        heapify(arr, 1, i - 1);
    }
}

void tester()
{
    int n;
    int arr[40];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("\nEnter elements : ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("before heapsort sorting : ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    heapsort(arr, n);
    printf("After heapsort sorting : ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void plotter()
{
    FILE *f1, *f2, *f3;
    f1 = fopen("hb.txt", "a");
    f2 = fopen("ha.txt", "a");
    f3 = fopen("hw.txt", "a");

    for (int n = 10; n <= 100; n += 10)
    {
        int *arr = (int *)malloc(sizeof(int) * (n + 1));

        // best
        for (int i = 1; i <= n; i++)
        {
            arr[i] = n;
        }
        count = 0;
        heapsort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);

        // average
        for (int i = 1; i <= n; i++)
        {
            arr[i] = rand() % n;
        }
        count = 0;
        heapsort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);

        // worst
        for (int i = 1; i <= n; i++)
        {
            arr[i] = i;
        }
        count = 0;
        heapsort(arr, n);
        fprintf(f3, "%d\t%d\n", n, count);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main()
{
    plotter();
}
