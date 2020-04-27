#include <stdio.h>
#include<time.h>

int heapSize;
int length=10;

void newArray(int*Array,int length)
{
    int i;
    for(i=0; i<length; i++)
    {
        Array[i]=rand()%100+1;
    }
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printArray(int array[], int length)
{
    int i;
    for (i=0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void maxHeapify(int *Array,int i,int length)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest;

    if(l<heapSize &&Array[l]>Array[i])
        largest=l;
    else
        largest=i;
    if(r<heapSize&&Array[r]>Array[largest])
        largest=r;
    if(largest!=i)
    {
        swap(&Array[i],&Array[largest]);
        maxHeapify(Array,largest,length);
    }
}
void buildMaxHeap(int *Array,int length)
{
    int i;
    heapSize=length;
    for(i=(length-1)/2; i>=0; i--)
    {
        maxHeapify(Array,i,length);
    }
}
void Heapsort(int*Array,int length)
{
    int i;
    buildMaxHeap(Array,length);
    for(i=length-1; i>=1; i--)
    {
        swap(&Array[0],&Array[i]);
        heapSize--;
        maxHeapify(Array,0,length);
    }
}

int Partition(int *Array,int p,int r)
{
    int x=Array[r];
    int i=p-1;
    int j;
    for (j=p; j<=r-1; j++)
    {
        if(Array[j]<=x)
        {
            i++;
            swap(&Array[i],&Array[j]);
        }
    }
    swap(&Array[i+1],&Array[r]);
    return i+1;
}
int Randomized_Partition(int *Array,int p,int r)
{
    //int i=r;
    int i=(rand()%((r+1)-p))+p;
    swap(&Array[r],&Array[i]);
    return Partition(Array,p,r);
}
void Quicksort(int *Array,int p,int r)
{
    int q,i;
    if(p<r)
    {
        q=Randomized_Partition(Array,p,r);
        Quicksort(Array,p,q-1);
        Quicksort(Array,q+1,r);
    }
}
void bubbleSort(int Array[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (Array[j] > Array[j+1])
                swap(&Array[j], &Array[j+1]);
}
void selectionSort(int Array[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (Array[j] < Array[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&Array[min_idx], &Array[i]);
    }
}
void insertionSort(int Array[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = Array[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && Array[j] > key)
        {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = key;
    }
}
void Merge(int *Array, int p, int q, int r)
{
    int n1, n2, i, j, k;
    n1 = (q - p) + 1;
    n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];
    for(i = 1 ; i <= n1 ; i++)
    {
        L[i] = Array[(p + i) - 1];
    }
    for(j = 1 ; j <= n2 ; j++)
    {
        R[j] = Array[q + j];
    }
    L[n1 + 1] = 99999;    // Supposed to be infinity
    R[n2 + 1] = 99999;    // Supposed to be infinity
    i = 1;
    j = 1;
    for(k = p ; k <= r ; k++)
    {
        if(L[i] <= R[j])
        {
            Array[k] = L[i];
            i = i + 1;
        }
        else
        {
            Array[k] = R[j];
            j = j + 1;
        }
    }
    return 0;
}
void Merge_Sort(int *Array, int p, int r)
{
    int q;
    if(p < r)
    {
        q = floor((p + r)/2);
        Merge_Sort(Array, p, q);
        Merge_Sort(Array, q + 1, r);
        Merge(Array, p, q, r);
    }
    return 0;
}



int main()
{
    int i;
    int A[length];
    newArray(A,length);

    printf("Array before heap sort:\n");
    printArray(A,length);

    printf("Array after heap sort:\n");
    Heapsort(A,length);
    printArray(A,length);
    printf("\n");

    newArray(A,length);
    printf("Array before quick sort:\n");
    printArray(A,length);

    printf("Array after quick sort:\n");
    Quicksort(A,0,length-1);
    printArray(A,length);
    printf("\n");

    newArray(A,length);
    printf("Array before merge sort:\n");
    printArray(A,length);

    printf("Array after merge sort:\n");
    Merge_Sort(A,0,length-1);
    printArray(A,length);
    printf("\n");

    newArray(A,length);
    printf("Array before insertion sort:\n");
    printArray(A,length);

    printf("Array after insertion sort:\n");
    insertionSort(A,length);
    printArray(A,length);
    printf("\n");

    newArray(A,length);
    printf("Array before selection sort:\n");
    printArray(A,length);

    printf("Array after selection sort:\n");
    selectionSort(A,length);
    printArray(A,length);
    printf("\n");


    newArray(A,length);
    printf("Array before bubble sort:\n");
    printArray(A,length);

    printf("Array after bubble sort:\n");
    bubbleSort(A,length);
    printArray(A,length);
    printf("\n");

    double totalT;
    clock_t start,end;
    start=clock();
    srand(time(NULL));
    insertionSort(A,length);
    end= clock();
    totalT=((double)(end - start))/CLK_TCK;
    printf("Time: %f\n",totalT);

    return 0;
}
