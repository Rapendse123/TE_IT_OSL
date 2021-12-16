#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <strings.h>

int comparison(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

// function for binary search
int binary_search(int arr[], int n, int key) {
    int *searched;
    searched = (int *) bsearch(&key, arr, n, sizeof(int), comparison);

    if (searched != NULL) {
        printf("\n%d is present in the array.\n", key);
    } else {
        printf("\n%d is not present in the array.\n", key);
    }

    printf("\n\n");
}

int main(int argc, char **argv) {
    int n = argc;
    int arr[n];

    for (int j = 0; j < n; j++) {
        arr[j] = atoi(argv[j]);
    }

    printf("\nThe array passed by the parent process is : ");
    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }

    int key;
    printf("\n\nEnter the number to be searched in the array : ");
    scanf("%d", &key);

    binary_search(arr, n, key);
}
