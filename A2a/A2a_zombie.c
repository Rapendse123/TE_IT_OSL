#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

// fucntion to pass to qsort for sorting in ascending order
int asc(const void *i, const void *j) {
    return (*(int *) i - *(int *) j);
}

// fucntion to pass to qsort for sorting in descending order
int desc(const void *i, const void *j) {
    return (*(int *) j - *(int *) i);
}

// fork function
void forktest(int arr[], int n) {
    int cpid = fork();

    if (cpid < 0) {
        printf("\nFork unsuccessful.");
    } else if (cpid == 0) {
        printf("\n\nIn Child process.");

        //quick sort
        qsort(arr, n, sizeof(int), desc);

        printf("\n\nSorted elements in array in descending order using quick sort : ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n\nChild process ID is : %d", getpid());
        printf("\nParent process ID is : %d", getppid());

        sleep(2);
        printf("\n\nChild process is exiting.\n\n");
    } else {
        printf("\n\nIn Parent process.");

        //quick sort
        qsort(arr, n, sizeof(int), asc);

        printf("\n\nSorted elements in array in ascending order using quick sort : ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n\n1.Child process ID is : %d", getpid());
        printf("\n1.Parent process ID is : %d\n", getppid());


        sleep(10);
        wait(NULL);
    }
}

int main() {
    int n = 0;
    printf("\n    ***Demonstration of Zombie State***\t\n");
    printf("\nEnter size of array : ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter numbers in the array : \n");
    for (int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }

    forktest(arr, n);
    return 0;
}
