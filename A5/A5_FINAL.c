#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main() {
    int pro, inst;
    int *available;
    int *maxins;
    int *work;
    int *allocated;
    int *request;
    int max[10][10];
    int allocation[10][10];
    int need[10][10];
    int count = 0;
    int *finished;
    printf("Enter the number of processes \n");
    scanf("%d", &pro);
    int safesequence[pro];
    printf("Enter the number of resources \n");
    scanf("%d", &inst);
    available = (int *) malloc(inst * sizeof(int));
    maxins = (int *) malloc(inst * sizeof(int));
    allocated = (int *) malloc(inst * sizeof(int));
    work = (int *) malloc(inst * sizeof(int));
    finished = (int *) malloc(inst * sizeof(int));
    request = (int *) malloc(inst * sizeof(int));
    printf("Enter the max instances of each resource type \n");
    for (int i = 0; i < inst; i++) {
        printf("max[%d] : \n", i);
        scanf("%d", &maxins[i]);
    }

    printf("\n Enter the Max matrix \n");
    for (int i = 0; i < pro; i++) {
        for (int j = 0; j < inst; j++) {
            scanf("%d", &max[i][j]);

        }
    }
    printf("\n The Max matrix is : \n");
    for (int i = 0; i < pro; i++) {
        for (int j = 0; j < inst; j++) {
            printf("%d\t", max[i][j]);
        }
        printf("\n");
    }

    printf("\n Enter the allocation matrix \n");
    for (int i = 0; i < pro; i++) {
        for (int j = 0; j < inst; j++) {
            scanf("%d", &allocation[i][j]);

        }
    }
    printf("\n The Allocation matrix is : \n");
    for (int i = 0; i < pro; i++) {
        for (int j = 0; j < inst; j++) {
            printf("%d\t", allocation[i][j]);
        }
        printf("\n");
    }


    printf("The need matrix is :\n");
    for (int i = 0; i < pro; i++) {
        for (int j = 0; j < inst; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < pro; i++) {
        for (int j = 0; j < inst; j++) {
            allocated[j] += allocation[i][j];
        }
    }
    printf("The available instances of each resource type \n");
    for (int i = 0; i < inst; i++) {
        available[i] = maxins[i] - allocated[i];
        printf("%d ", available[i]);
    }
    //Main Safety Check Algorithm
    //Initially work=available and initialise finished=false for all processes
    for (int i = 0; i < inst; i++) {
        work[i] = available[i];
        finished[i] = false;
    }
    printf("\n");
    while (count < pro) {
        //found bool for knowing if there exists a safe sequence
        bool found = false;
        for (int i = 0; i < pro; i++) {
            //Find a process that has not yet been finished
            if (finished[i] == false) {
                int j;
                for (j = 0; j < inst; j++) {
                    //Checking if the process requirement of resources is higher than available resources
                    if (need[i][j] > work[j])
                        break;
                }
                //if all needs are satisfied
                if (j == inst) {
                    for (int k = 0; k < inst; k++) {
                        work[k] = work[k] + allocation[i][k];
                    }
                    safesequence[count++] = i;
                    finished[i] = true;
                    found = true;
                }
            }
        }

        if (found == false) {
            printf("No safe sequence found \n");
            break;
        }


    }
    printf("Safe sequence is  : ");
    for (int i = 0; i < pro; i++) {
        printf("P%d  ", safesequence[i]);
    }
    printf("\n");


    //Resource Request
    int reqpro;
    printf("Enter the process that is requesting : \n");
    scanf("%d", &reqpro);
    printf("Enter the request : \n");
    for (int i = 0; i < inst; i++) {
        scanf("%d", &request[i]);
    }
    for (int j = 0; j < inst; j++) {
        if (request[j] <= need[reqpro][j]) {
            available[j] = available[j] - request[j];
            allocation[reqpro][j] = allocation[reqpro][j] + request[j];
            need[reqpro][j] = need[reqpro][j] - request[j];
        } else {
            printf("Request cannot be granted ");
            break;
        }
    }
    printf("New allocation and available will be : \n");
    printf("\n The Allocation matrix is : \n");
    for (int i = 0; i < pro; i++) {
        for (int j = 0; j < inst; j++) {
            printf("%d\t", allocation[i][j]);
        }
        printf("\n");
    }
    printf("The need matrix is :\n");
    for (int i = 0; i < pro; i++) {
        for (int j = 0; j < inst; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }
    printf("The available instances of each resource type \n");
    for (int i = 0; i < inst; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
    printf("Checking safety sequence now : \n");
    //Initially work=available and initialise finished=false for all processes
    for (int i = 0; i < inst; i++) {
        work[i] = available[i];
        finished[i] = false;
    }
    printf("\n");
    while (count < pro) {
        //found bool for knowing if there exists a safe sequence
        bool found = false;
        for (int i = 0; i < pro; i++) {
            //Find a process that has not yet been finished
            if (finished[i] == false) {
                int j;
                for (j = 0; j < inst; j++) {
                    //Checking if the process requirement of resources is higher than available resources
                    if (need[i][j] > work[j])
                        break;
                }
                //if all needs are satisfied
                if (j == inst) {
                    for (int k = 0; k < inst; k++) {
                        work[k] = work[k] + allocation[i][k];
                    }
                    safesequence[count++] = i;
                    finished[i] = true;
                    found = true;
                }
            }
        }

        if (found == false) {
            printf("No safe sequence found \n");
            break;
        }


    }
    printf("Safe sequence is  : ");
    for (int i = 0; i < pro; i++) {
        printf("P%d  ", safesequence[i]);
    }
    printf("\n");
}


/*
satyajeetchavan@satyajeetchavan-VirtualBox:~/Desktop$ gcc bankers.c -o bankers
satyajeetchavan@satyajeetchavan-VirtualBox:~/Desktop$ ./bankers
Enter the number of processes
5
Enter the number of resources
3
Enter the max instances of each resource type
max[0] :
10
max[1] :
5
max[2] :
7

 Enter the Max matrix
7
5
3
3
2
2
9
0
2
2
2
2
4
3
3

 The Max matrix is :
7	5	3
3	2	2
9	0	2
2	2	2
4	3	3

 Enter the allocation matrix
0
1
0
2
0
0
3
0
2
2
1
1
0
0
2

 The Allocation matrix is :
0	1	0
2	0	0
3	0	2
2	1	1
0	0	2
The need matrix is :
7	4	3
1	2	2
6	0	0
0	1	1
4	3	1
The available instances of each resource type
3 3 2
Safe sequence is  : P1  P3  P4  P0  P2
Enter the process that is requesting :
1
Enter the request :
1
0
2
New allocation and available will be :

 The Allocation matrix is :
0	1	0
3	0	2
3	0	2
2	1	1
0	0	2
The need matrix is :
7	4	3
0	2	0
6	0	0
0	1	1
4	3	1
The available instances of each resource type
2 3 0
Checking safety sequence now :

Safe sequence is  : P1  P3  P4  P0  P2
*/