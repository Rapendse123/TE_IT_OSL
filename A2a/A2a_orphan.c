//#include <stdio.h>
//#include <sys/types.h>
//#include <unistd.h>
//#include <stdlib.h>
//
//// fucntion to pass to qsort for sorting in ascending order
//int asc(const void *i, const void *j) {
//    return (*(int *) i - *(int *) j);
//}
//
//// fucntion to pass to qsort for sorting in descending order
//int desc(const void *i, const void *j) {
//    return (*(int *) j - *(int *) i);
//}
//
//// fork function
//void forktest(int arr[], int n) {
//    int cpid = fork();
//
//    if (cpid < 0) {
//        printf("\nFork unsuccessful.");
//    } else if (cpid == 0) {
//        printf("\n\nIn Child process.");
//
//        printf("\n\nChild process ID is : %d", getpid());
//        printf("\nParent process ID is : %d", getppid());
//        printf("\n\n");
//
//        sleep(5);
//        // At this time parent process has finished, so it will show different process id.
//        printf("\n\nIn Child process in Orphan State.");
//
//        //quick sort
//        qsort(arr, n, sizeof(int), desc);
//
//        printf("\n\nSorted elements in array in descending order using quick sort : ");
//        for (int i = 0; i < n; i++) {
//            printf("%d ", arr[i]);
//        }
//
//        printf("\n\nChild process ID is : %d", getpid());
//        printf("\nParent process ID is : %d\n", getppid());
//    } else {
//        printf("\n\nIn Parent process.");
//
//        //quick sort
//        qsort(arr, n, sizeof(int), asc);
//
//        printf("\n\nSorted elements in array in ascending order using quick sort : ");
//        for (int i = 0; i < n; i++) {
//            printf("%d ", arr[i]);
//        }
//        printf("\n\nChild process ID is : %d", getpid());
//        printf("\nParent process ID is : %d\n", getppid());
//
//    }
//}
//
//int main() {
//    int n = 0;
//    printf("\n\t***Demonstration of Orphan State***\t\n");
//    printf("\nEnter size of array : ");
//    scanf("%d", &n);
//
//    int arr[n];
//    printf("\nEnter numbers in the array : \n");
//    for (int i = 0; i < n; i++) {
//        scanf(" %d", &arr[i]);
//    }
//
//    forktest(arr, n);
//    return 0;
//}
