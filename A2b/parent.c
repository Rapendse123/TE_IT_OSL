#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


void print_arr(int [], int);

void bubble_sort(int [], int);

int main() {

    int arr[100], n;
    pid_t child;

    printf("\nThis is the main process:- ");
    printf("\nProcess id %d", getpid());
    printf("\nParent id %d", getppid());

    printf("\n\nEnter the size of array:- ");
    scanf("%d", &n);

    printf("\nPlease enter the elements in the array in ascending order:-\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the element [%d]:- ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray is:- ");
    print_arr(arr, n);
    printf("\n");

    bubble_sort(arr, n);


    printf("\nForking the current process");
    child = fork();

    if (child == -1)
        printf("\nChild not born");

    else if (child == 0) {
        printf("\nChild process!\n");

        char *buffer[n + 1];
        int i;

        buffer[0] = "./binary";

        for (i = 1; i < n + 1; i++) {
            buffer[i] = malloc(20);
            snprintf(buffer[i], 20, "%d", arr[i - 1]);
        }

        buffer[i] = NULL;

        execv("./binary", buffer);

        printf("Child executed successfully\n");
    } else {
        printf("\nParent process!\n");
        printf("\nSorted array is:- ");
        print_arr(arr, n);
        printf("\n");
        wait(NULL);
        printf("\nParent executed successfully\n\n");
    }
    return 0;
}


void print_arr(int arr[100], int n) {
    int i;
    printf("[ ");

    for (i = 0; i < n - 1; i++)
        printf(" %d, ", arr[i]);

    printf(" %d ]", arr[i]);
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int temp;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/*
OUTPUT:
rapen@rapen-VirtualBox:~$ cd OS
rapen@rapen-VirtualBox:~/OS$ gcc parent.c
rapen@rapen-VirtualBox:~/OS$ gcc child.c -o binary
rapen@rapen-VirtualBox:~/OS$ ./a.out

This is the main process:-
Process id 5362
Parent id 5133

Enter the size of array:- 5

Please enter the elements in the array in ascending order:-
Enter the element [0]:- 6
Enter the element [1]:- 7
Enter the element [2]:- 8
Enter the element [3]:- 3
Enter the element [4]:- 2

Array is:- [  6,  7,  8,  3,  2 ]

Forking the current process
Parent process!

Sorted array is:- [  2,  3,  6,  7,  8 ]
Forking the current process
Child process!

Enter the value to be searched:- 3

Element was found in the array at location 2

Parent executed successfully
*/
