#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//global declarations
void menu()
{
    printf(" \n \t ------------------------------------------ \n");
    printf(" \n \t ------------------------------------------- \n");
    printf(" \n \t \t YOUR SORTING OPERATIONS MENU \n");
    printf(" \n \t ------------------------------------------ \n");
    printf(" \n \t ------------------------------------------- ");
    printf(" \n \t \t \t \t \t @NITHISH RAINA \n");
    printf(" \n \t 1.PERFORM BUBBLE SORT \n \t 2.PERFORM INSERTION SORT \n \t 3.PERFORM SELECTION SORT \n \t 4.PERFORM QUICK SORT \n \t 5.PERFORM MERGE SORT \n \t 6.PERFORM COUNT SORT \n \t 7.DISPLAY YOUR ARRAY \n \t 8.EXIT THE MENU \n");
}
void display(int a[], int n)
{
    if (n == 0)
    {
        printf("\n\t NO ELEMENTS TO BE DISPLAYED \n");
    }
    printf("\n \t DISPLAYING YOUR ARRAY \n");
    printf("\n \t ---------------------------------------- \n\t ");
    for (int i = 0; i < n; i++)
    {
        printf("%d   ", a[i]);
    }
}
void bubbleSort(int a[], int n)
{
    clock_t start = clock();
    clock_t end = clock();
    double time_taken_b = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    display(a, n);
    printf("\n\n\t THE TIME TAKEN FOR THIS ALGORITHM IS %f\n", time_taken_b);
}

void insertionSort(int a[], int n)
{
    clock_t start = clock();
    clock_t end = clock();
    double time_taken_i = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

    for (int i = 1; i < n; i++)
    {
        int ele = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > ele)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = ele;
    }
    display(a, n);
    printf("\n\n\t THE TIME TAKEN FOR THIS ALGORITHM IS %f\n", time_taken_i);
}

void selectionSort(int a[], int n)
{
    int temp;
    clock_t start = clock();
    clock_t end = clock();
    double time_taken_s = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
    }
    display(a, n);
    printf("\n\n\t THE TIME TAKEN FOR THIS ALGORITHM IS %f\n", time_taken_s);
}

int pivotIndex(int a[], int low, int high)
{
    int pivot_ele = a[low];
    int i = low;
    int j = high;
    int temp;
    while (i < j)
    {
        //printf("\n\nENTERING THIS LOOP \n");
        do
        {
            i++;
        }
        while (a[i] <= pivot_ele);

        do
        {
            j--;
        }
        while (a[j] > pivot_ele);

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    //printf("SWAPPING HERE\n");
    temp = a[j];
    a[j] = a[low];
    a[low] = temp;
    return j;
}
void quickSort(int a[], int low, int high, int n)
{
    // printf("CALLING QUCK SORT FUNCTION \n");
    int index;
    if (low < high)
    {
        index = pivotIndex(a, low, high);
        quickSort(a, low, index - 1, n);
        quickSort(a, index + 1, high, n);
    }
}
void merge(int a[], int low, int mid, int high)
{
    int new[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            new[k] = a[i];
            i++;
        }
        else
        {
            new[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        new[k] = a[i];
        i++;
    }
    while (j <= high)
    {
        new[k] = a[j];
        j++;
    }
    k++;
    //copying to the original array
    for (int i = low; i <= high; i++)
    {
        a[i] = new[i];
    }
}
void mergeSort(int a[], int low, int high, int n)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid, n);
        mergeSort(a, mid + 1, high, n);
        merge(a, low, mid, high);
    }
    else 
    {
        cout<<"\n \t COULDN'T SORT YOUR ARRAY "<<endl;
    }
    //display(a, n);
}
int main()
{
    int n, a[100], ch;
    printf("\n\t ENTER THE SIZE OF THE ARRAY \n");
    printf("\n\t----------------------------------\n\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\n\t ENTER THE ELEMENT OF %d\n\t ", i + 1);
        scanf("%d", &a[i]);
    }
    do
    {

        menu();
        printf("\n \t ENTER YOUR CHOICE \n");
        printf("\n \t---------------------------------- \n\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("\n\t CALLING BUBBLE SORT \n");
            bubbleSort(a, n);
            break;
        }
        case 2:
        {
            printf("\n\t CALLING INSERTION SORT \n");
            insertionSort(a, n);
            break;
        }
        case 3:
        {
            printf("\n\t CALLING SELECTION SORT \n");
            selectionSort(a, n);
            break;
        }
        case 4:
        {
            printf("\n\t CALLING QUICK SORT \n");
            clock_t start = clock();
            clock_t end = clock();
            double time_taken_q = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
            int low = 0;
            int high = n - 1;
            quickSort(a, low, high, n);
            display(a, n);
            printf("\n\n\t THE TIME TAKEN FOR THIS ALGORITHM IS %f\n", time_taken_q);
            break;
        }
        case 5:
        {
            printf("\n\t CALLING MERGE SORT \n");
            clock_t start = clock();
            clock_t end = clock();
            double time_taken_m = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
            int low = 0;
            int high = n - 1;
            mergeSort(a, low, high, n);
            display(a, n);
            printf("\n\n\t THE TIME TAKEN FOR THIS ALGORITHM IS %f\n", time_taken_m);
            break;
        }
        case 6:
        {
            printf("\n \t NOT BUILDED YET \n");
            break;
        }
        case 7:
        {
            display(a, n);
            break;
        }
        case 8:
        {
            printf("\n \t EXITING MENU \n");
            printf("\n\t REFER  ----->  https://random.org FOR GETTING RANDOM LARGE AMOUNT OF NUMBERS \n");
            exit(1);
        }
        default:
        {
            printf("\n \t ENTER A VALID CHOICE FROM THESE OPTIONS(1/8) \n");
            break;
        }
        }

    } 
    while(ch != 8 );
    return ( 0 == 0 );
}