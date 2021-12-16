#include <stdio.h>
#include <stdbool.h>

#define MAX 10

struct process {
    int max[MAX];
    int allocated[MAX];
    int need[MAX];
};

int n;  // no of processes
int m;  // no of resources

void input(struct process pr[n], int available[m]) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter max need of resources for process %d:\n", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &pr[i].max[j]);
        }
        printf("\nEnter no of allocated resources for process %d:\n", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &pr[i].allocated[j]);
            pr[i].need[j] = pr[i].max[j] - pr[i].allocated[j];
        }
    }
    printf("\n\n");
    printf("Enter no of available resources:");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }
}

void display(struct process pr[n]) {
    printf("\nPID\tMAX\tALLOCATED\tNEED\n");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t", i);
        for (int j = 0; j < m; j++)
            printf("%d ", pr[i].max[j]);
        printf("\t\t");
        for (int j = 0; j < m; j++)
            printf("%d ", pr[i].allocated[j]);
        printf("\t\t");
        for (int j = 0; j < m; j++)
            printf("%d ", pr[i].need[j]);
        printf("\t\t");
    }
    printf("\n");
}

bool applySafetyAlgo(struct process pr[n], int available[m], int safe_sequence[m]) {
    bool finish[n];
    int work[m];
    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }
    for (int i = 0; i < n; i++) {
        finish[i] = false;
    }
    bool proceed = true;    // whether we get a process in safe sequence to proceed
    int k = 0;   // index to insert processes in safe sequence
    while (proceed) {
        proceed = false;
        // find an index i such for process i its request can be fulfilled subjected to work
        for (int i = 0; i < n; i++) {
            bool flag = true;
            if (!finish[i]) {
                for (int j = 0; j < m; j++) {
                    // if need <= work
                    if (pr[i].need[j] <= work[j]) {
                        continue;
                    } else {
                        flag = false;    // implies that for current process need > work
                        break;
                    }
                }
                if (!flag) continue; // check for next process
                // we got a process whose need can be fulfilled, update work accordingly
                for (int j = 0; j < m; j++) {
                    work[j] += pr[i].allocated[j];
                }
                finish[i] = true;
                safe_sequence[k++] = i;
                proceed = true;   // it means that we got at least one process in safe state, we can proceed further
            }
        }
    }
    // check finish array
    int i;
    for (i = 0; i < n && finish[i] == true; i++) {
        continue;
    }
    // if all processes are completed then return true
    if (i == n) {
        return true;
    }
    return false;
}

bool isSafeState(struct process pr[n], int available[m], int safe_sequence[m]) {
    if (applySafetyAlgo(pr, available, safe_sequence))
        return true;
    return false;
}

int main() {
    printf("Enter no of processes:");
    scanf("%d", &n);
    printf("Enter no of resources:");
    scanf("%d", &m);

    int available[m];
    int safe_sequence[n];
    struct process pr[n];

    printf("**********Enter details of processes**********\n");
    input(pr, available);

    printf("**********Displaying details of processes...**********\n");
    display(pr);

    if (isSafeState(pr, available, safe_sequence)) {
        printf("system is in sate state\n");
        printf("safe sequence is: ");
        for (int i = 0; i < n; i++) {
            printf("P%d ", safe_sequence[i]);
        }
    } else {
        printf("system is in unsafe state\n");
    }
    return 0;
}

/*
OUTPUT:
Enter no of processes:5
Enter no of resources:3
**********Enter details of processes**********

Enter max need of resources for process 0:
7
5
3

Enter no of allocated resources for process 0:
0
1
0

Enter max need of resources for process 1:
3
2
2

Enter no of allocated resources for process 1:
2
0
0

Enter max need of resources for process 2:
9
0
2

Enter no of allocated resources for process 2:
3
0
2

Enter max need of resources for process 3:
2
2
2

Enter no of allocated resources for process 3:
2
1
1

Enter max need of resources for process 4:
4
3
3

Enter no of allocated resources for process 4:
0
0
2


Enter no of available resources:3
3
2
**********Displaying details of processes...**********

PID     MAX     ALLOCATED       NEED

P0      7 5 3           0 1 0           7 4 3
P1      3 2 2           2 0 0           1 2 2
P2      9 0 2           3 0 2           6 0 0
P3      2 2 2           2 1 1           0 1 1
P4      4 3 3           0 0 2           4 3 1
system is in sate state
safe sequence is: P1 P3 P4 P0 P2
*/