//#include <stdio.h>
//#include <sys/types.h>
//#include <unistd.h>
//
//void forktest(int a[], int n) {
//    int cpid = fork();
//    if (cpid < 0) {
//        printf("\nFork unsuccessful.");
//    } else if (cpid == 0) {
//        printf("\n\nIn Child process.");
//        printf("\n2.Child process ID is : %d", getpid());
//        printf("\n2.Parent process ID is : %d", getppid());
//
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                if (a[j] < a[i]) {
//                    int temp = a[i];
//                    a[i] = a[j];
//                    a[j] = temp;
//                }
//            }
//        }
//
//        printf("\n\nSorted elements in array : \n");
//        for (int i = 0; i < n; i++) {
//            printf("%d ", a[i]);
//        }
//        sleep(5);
//        printf("\n\n3.Child process ID is : %d", getpid());
//        printf("\n3.Parent process ID is : %d\n", getppid());
//    } else {
//        printf("\nIn Parent process.");
//        printf("\n1.Child process ID is : %d", getpid());
//        printf("\n1.Parent process ID is : %d", getppid());
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                if (a[j] < a[i]) {
//                    int temp = a[i];
//                    a[i] = a[j];
//                    a[j] = temp;
//                }
//            }
//        }
//
//        printf("\n\nSorted elements in array : \n");
//        for (int i = 0; i < n; i++) {
//            printf("%d ", a[i]);
//        }
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
