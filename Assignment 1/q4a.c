#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");


    int temp;
    for (int i=0;i<n;i++){
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    printf("Reversed array is: ");
    for(int i=0; i<n;i++){
        printf ("%d ", arr[i]);
    }
    return 0;
}