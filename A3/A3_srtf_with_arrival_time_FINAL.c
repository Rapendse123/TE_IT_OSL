// C program to implement pre-emptive SJF(SRTF) arrival time

#include <stdio.h>
#include <stdbool.h>
#define MAX 100

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

int main() {
    struct process pr[MAX];
    float avg_tat;  // avg turn around time
    float avg_wt;   // avg waiting time
    float avg_rt;   // avg response time
    float cpu_util; // cpu utilization
    float throughput;
    int total_tat = 0;
    int total_wt = 0;
    int total_rt = 0;
    bool is_completed[MAX];  // to mark which processes are completed

    int n;
    printf("Enter no of processes:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pr[i].pid = i + 1;
        printf("Enter arrival time of process %d:", i + 1);
        scanf("%d", &pr[i].arrival_time);
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        printf("Enter burst time of process %d:", i + 1);
        scanf("%d", &pr[i].burst_time);
        printf("\n");
    }

    int current_time = 0, completed = 0;
    while (completed != n) {
        int idx = -1;
        int mn = 1000000;   // to find the process with min burst time
        for (int i = 0; i < n; i++) {
            if (pr[i].arrival_time <= current_time && !is_completed[i]) {
                if (pr[i].burst_time < mn) {
                    mn = pr[i].burst_time;
                    idx = i;
                } else if (pr[i].burst_time == mn) {
                    if (pr[i].arrival_time < pr[idx].arrival_time) {
                        mn = pr[i].burst_time;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1) {
            pr[idx].start_time = current_time;
            pr[idx].completion_time = pr[idx].start_time + pr[idx].burst_time;
            pr[idx].turnaround_time = pr[idx].completion_time - pr[idx].burst_time;
            pr[idx].waiting_time = pr[idx].turnaround_time - pr[idx].burst_time;
            pr[idx].response_time = pr[idx].start_time - pr[idx].arrival_time;

            total_tat += pr[idx].turnaround_time;
            total_wt += pr[idx].waiting_time;
            total_rt += pr[idx].response_time;

            is_completed[idx] = true;
            completed++;
            current_time = pr[idx].completion_time;
        } else {
            current_time++;
        }
    }
    int min_arrival_time = 1000000;
    int max_completion_time = -1;
    for (int i = 0; i < n; i++) {
        if (min_arrival_time > pr[i].arrival_time) {
            min_arrival_time = pr[i].arrival_time;
        }
        if (max_completion_time < pr[i].completion_time) {
            max_completion_time = pr[i].completion_time;
        }
    }

    avg_tat = (float) total_tat / (float) n;
    avg_wt = (float) total_wt / (float) n;
    avg_rt = (float) total_rt / (float) n;
    cpu_util = (float) (max_completion_time - min_arrival_time) / (float) (max_completion_time);
    throughput = (float) n / (float) (max_completion_time - min_arrival_time);
    printf("\n\n");

    printf("#P\t AT\t BT\t ST\t CT\t TAT\t WT\t RT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n",
               pr[i].pid, pr[i].arrival_time, pr[i].burst_time, pr[i].start_time,
               pr[i].completion_time, pr[i].turnaround_time, pr[i].waiting_time,
               pr[i].response_time);
    }

    printf("\nAverage turnaround time: ");
    printf("%f", avg_tat);
    printf("\n");

    printf("\nAverage waiting time: ");
    printf("%f", avg_wt);
    printf("\n");

    printf("\nAverage response time: ");
    printf("%f", avg_rt);
    printf("\n");

    printf("\nCPU Utilization: ");
    printf("%f", cpu_util);
    printf("\n");

    printf("Throughput: ");
    printf("%f", throughput);
    printf("\n");

    return 0;
}

/*
OUTPUT:
Enter no of processes:5
Enter arrival time of process 1:3

Enter arrival time of process 2:1

Enter arrival time of process 3:4

Enter arrival time of process 4:0

Enter arrival time of process 5:2

Enter burst time of process 1:1

Enter burst time of process 2:4

Enter burst time of process 3:2

Enter burst time of process 4:6

Enter burst time of process 5:3



#P       AT      BT      ST      CT      TAT     WT      RT
1        3       1       6       7       6       5       3
2        1       4       12      16      12      8       11
3        4       2       7       9       7       5       3
4        0       6       0       6       0       -6      0
5        2       3       9       12      9       6       7

Average turnaround time: 6.800000

Average waiting time: 3.600000

Average response time: 4.800000

CPU Utilization: 1.000000
Throughput: 0.312500
*/