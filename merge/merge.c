#include <stdio.h>
#include <stdlib.h>

int c = 0;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int a[n1], b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[m + i + 1];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
        c++;
    }
    while (i < n1)
    {
        arr[k++] = a[i++];
    }
    while (j < n2)
    {
        arr[k++] = b[j++];
    }
}

void mergesort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void worst(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        int n1 = m - l + 1;
        int n2 = r - m;
        int a[n1], b[n2];
        for (int i = 0; i < n1; i++)
        {
            a[i] = arr[2 * i];
        }
        for (int i = 0; i < n2; i++)
        {
            b[i] = arr[2 * i + 1];
        }
        worst(a, l, m);
        worst(b, m + 1, r);
        int i = 0, j = 0;
        for (i = 0; i < n1; i++)
        {
            arr[i] = a[i];
        }
        while (j < n2)
        {
            arr[i + j] = b[j];
            j++;
        }
    }
}

void plotter()
{

    FILE *f1 = fopen("me_best.txt", "a");
    FILE *f2 = fopen("me_worst.txt", "a");
    FILE *f3 = fopen("me_avg.txt", "a");
    int *arr;
    for (int i = 4; i <= 1024; i *= 2)
    {
        arr = (int *)malloc(sizeof(int) * i);
        for (int j = 0; j < i; j++)
        {
            arr[j] = j;
        }
        mergesort(arr, 0, i - 1);
        fprintf(f1, "%d\t%d\n", i, c);
        c = 0;
        for (int j = 0; j < i; j++)
        {
            arr[j] = j + 1;
        }
        worst(arr, 0, i - 1);
        mergesort(arr, 0, i - 1);
        fprintf(f2, "%d\t%d\n", i, c);
        c = 0;
        for (int j = 0; j < i; j++)
        {
            arr[j] = rand() % 100;
        }
        mergesort(arr, 0, i - 1);
        fprintf(f3, "%d\t%d\n", i, c);
        c = 0;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
}

void main()
{
    int n, arr[100];
    printf("\nEnter number of elements : ");
    scanf("%d", &n);
    printf("\nenter element : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nBefore mergesort sort : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    mergesort(arr, 0, n - 1);
    printf("\nAfter mergesort sort :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}