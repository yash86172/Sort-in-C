#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n)
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
} 

void insertionSort(int arr[], int n)
{
    int i,key,j;
    for (i = 1; i < n; i++)
   {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int n,i;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    while(1)
        {
            int choice;
            printf("\nEnter your choice:\n1:Insertion Sort\n2:Selection Sort\n3:Exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: insertionSort(arr,n);
                        printArray(arr,n);
                        break;
                case 2: selectionSort(arr,n);
                        printArray(arr,n);
                        break;
                default: return 0;
            }
        
        }
	return 0;
}
