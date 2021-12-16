//#include <stdio.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//#include <stdlib.h>
//
//void merge(int arr[], int l, int m, int r) {
//    int i, j, k;
//    int n1 = m - l + 1; //For the size of temporary array on left (after splitting)
//    int n2 = r - m; //For the size of temporary array on right (after splitting)
//
//    // create temporary arrays
//    int Left[n1], Right[n2];
//
//    // Copy data to temp arrays Left[] and Right[]
//    for (i = 0; i < n1; i++)
//        Left[i] = arr[l + i];
//    for (j = 0; j < n2; j++)
//        Right[j] = arr[m + 1 + j];
//
//    // Merge the temp arrays back into original
//    i = 0; // Startying index of first array
//    j = 0; // Starting index of second array
//    k = l; // Starting index of merged array
//    while (i < n1 && j < n2) {
//        if (Left[i] <= Right[j]) {
//            arr[k] = Left[i];
//            i++;
//        } else {
//            arr[k] = Right[j];
//            j++;
//        }
//        k++;
//    }
//
//    // Copy the remaining elements of Left[]
//    while (i < n1) {
//        arr[k] = Left[i];
//        i++;
//        k++;
//    }
//
//    // Copy the remaining elements of Right[]
//    while (j < n2) {
//        arr[k] = Right[j];
//        j++;
//        k++;
//    }
//}
//
///* l is the first index and r is the last index of the array to be sorted */
//void mergeSort(int arr[], int l, int r) {
//    if (l < r) {
//        // Same as (l+r)/2, but avoids overflow for
//        // large l and h
//        int m = l + (r - l) / 2;
//
//        // Sort first and second halves
//        mergeSort(arr, l, m);
//        mergeSort(arr, m + 1, r);
//        merge(arr, l, m, r);
//    }
//}
//
//int main(void) {
//    int n, pid;
//    printf("Enter the number of integers you want to sort : \n");
//    scanf("%d", &n);
//    int a[n];
//    for (int i = 0; i < n; i++) {
//        printf("Enter the element : ");
//        scanf("%d", &a[i]);
//    }
//    printf("Sorting in child and parent processes :\n");
//    pid = fork();
//    if (pid == 0) {
//        printf("Child process executed with id %d \n Bubble sort in ascending order :\n ", getpid());
//        printf("\n");
//        int temp;
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                if (a[j] < a[i]) {
//                    temp = a[i];
//                    a[i] = a[j];
//                    a[j] = temp;
//                }
//            }
//        }
//        printf("Printing Sorted Element List in Ascending Order : \n");
//        for (int i = 0; i < n; i++) {
//            printf("%d  ", a[i]);
//        }
//        printf("\n");
//        printf("Exiting Child process \n");
//    } else if (pid > 0) {
//        //wait(NULL);
//        printf("Parent process executed with id %d \n Merge sort in ascending order :\n ", getpid());
//        printf("\n");
//        mergeSort(a, 0, n - 1);
//        printf("Printing Sorted Element List : \n");
//        for (int i = 0; i < n; i++) {
//            printf("%d  ", a[i]);
//        }
//        printf("\n");
//        printf("Exiting Parent Process \n");
//
//    } else if (pid < 0) {
//        printf("Unfortunately Child could not be born !");
//    }
//}