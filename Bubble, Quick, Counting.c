#include <stdio.h>
#include <stdlib.h>

void improvedBubbleSort(int A[], int num)
{
    int i,j,flag,temp;
    for(i=0;i<num-1;i++)
    {
        flag=0;
        for(j=0;j<=num-i-2;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}
  

void quickSort(int arr[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int getMax(int a[], int n) 
{  
   int max = a[0];  
   for(int i = 1; i<n; i++) 
   {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max;
}  
  
void countingSort(int a[], int n)
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1]; 
   for (int i = 0; i <= max; ++i)   
   {  
     count[i] = 0;
   }  
   for (int i = 0; i < n; i++)
   {   
     count[a[i]]++;  
   }  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; 
  for (int i = n - 1; i >= 0; i--)
   {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--;
    }  
   for(int i = 0; i<n; i++) 
   {  
      a[i] = output[i]; 
   }  
}  
  
void printArray(int a[], int n)
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
}  
  

int main(int n, char* args[])
{
    FILE *fp;
    fp = fopen(args[1], "r");
    int arr[100];
    int cnt = 0;
    if(fp==NULL)
    {
        printf("File doesn't exist");
        exit(0);
    }
    else
    {
        printf("---Reading from file---\n");
        while(fscanf(fp, "%d",&arr[cnt]) != EOF)
        {
            printf("%d\n",arr[cnt]);
            cnt++;
        }
        fclose(fp);
        while(1)
        {
            int choice;
            printf("\nEnter your choice:\n1:Bubble Sort\n2:Quick Sort\n3:Counting Sort\n4:Exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: improvedBubbleSort(arr,cnt);
                        printArray(arr,cnt);
                        break;
                case 2: quickSort(arr,0,cnt);
                        printArray(arr,cnt);
                        break;
                case 3: countingSort(arr,cnt);
                        printArray(arr,cnt);
                        break;
                default: return 0;
            }
        }

    }
	return 0;
}
