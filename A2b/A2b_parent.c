#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// fucntion to pass to qsort for sorting in ascending order
int asc(const void *i, const void *j) {
    return (*(int *) i - *(int *) j);
}

// fork function
void forktest(int arr[], int n) {
    int cpid = fork();

    if (cpid < 0) {
        printf("\nFork unsuccessful.");
    } else if (cpid == 0) {

        printf("\n\nIn the Child process with ID : %d\n", getpid());

        qsort(arr, n, sizeof(int), asc);

        char *argv[n];
        for (int i = 0; i < n; i++) {
            char c[sizeof(int)];

            snprintf(c, sizeof(int), "%d", arr[i]);

            // allocate enough space on char* array to store the result
            argv[i] = malloc(sizeof(c));

            // copy to the array
            strcpy(argv[i], c);
        }

        argv[n] = NULL;

        if (execv("./child", argv) == -1) {
            perror("Could not execv");
        }
    } else {

        printf("\n\nIn the Parent process with ID : %d\n", getppid());

        //quick sort
        qsort(arr, n, sizeof(int), asc);

        printf("\nSorted elements in array in ascending order using quick sort : ");
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");

        wait(NULL);
    }
}

int main() {
    printf("\n\n\t*** Demonstration of EXECVE System Call ***\t\n\n");

    int n = 0;
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
