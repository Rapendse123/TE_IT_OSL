//// C program to implement round robin
//
//#include <stdio.h>
//#include <stdbool.h>
//
//#define MAX 100
//
//struct process {
//    int pid;
//    int arrival_time;
//    int burst_time;
//    int completion_time;
//    int turn_around_time;
//    int waiting_time;
//};
//
//int main() {
//    struct process pr[MAX];
//    int bt_remaining[MAX];
//    int tq, i, current_time = 0;
//
//    int n;
//    printf("Enter no of processes:");
//    scanf("%d", &n);
//
//    for (i = 0; i < n; i++) {
//        printf("Enter arrival time of process %d:", i);
//        scanf("%d", &pr[i].arrival_time);
//        pr[i].pid = i + 1;
//        printf("\n");
//    }
//
//    for (i = 0; i < n; i++) {
//        printf("Enter burst time of process %d:", i);
//        scanf("%d", &pr[i].burst_time);
//        bt_remaining[i] = pr[i].burst_time;
//        printf("\n");
//    }
//
//    printf("Enter time quantum:");
//    scanf("%d", &tq);
//
//    while (true) {
//        bool done = true;
//        for (i = 0; i < n; i++) {
//            if (bt_remaining[i] > 0) {
//                done = false;
//                if (bt_remaining[i] > tq) {
//                    current_time += tq;
//                    bt_remaining[i] -= tq;
//                } else {
//                    current_time += bt_remaining[i];
//                    pr[i].completion_time = current_time;
//                    pr[i].waiting_time = current_time - pr[i].burst_time;
//                    bt_remaining[i] = 0;
//                }
//            }
//        }
//        if (done) break;
//    }
//
//    float awt = 0, atat = 0;
//    printf("\nprocess\tburst time\tcompletion time\tturn around time\twaiting time\n");
//    for (i = 0; i < n; i++) {
//        pr[i].turn_around_time = pr[i].waiting_time + pr[i].burst_time;
//
//        awt += (float) pr[i].waiting_time;
//        atat += (float) pr[i].turn_around_time;
//
//        printf("\n%d\t%d\t\t%d\t\t\t%d\t\t%d",
//               pr[i].pid, pr[i].burst_time, pr[i].completion_time, pr[i].turn_around_time, pr[i].waiting_time);
//    }
//
//    awt = awt / (float) n;
//    atat = atat / (float) n;
//    printf("\nAverage waiting time = %f\n", awt);
//    printf("\nAverage turn around time = %f\n", atat);
//    return 0;
//}
//
///*
//OUTPUT:
//Enter no of processes:3
//Enter arrival time of process 0:1
//
//Enter arrival time of process 1:2
//
//Enter arrival time of process 2:3
//
//Enter burst time of process 0:10
//
//Enter burst time of process 1:5
//
//Enter burst time of process 2:8
//
//Enter time quantum:2
//
//process burst time      completion time turn around time        waiting time
//
//1       10              23                      23              13
//2       5               15                      15              10
//3       8               21                      21              13
//Average waiting time = 12.000000
//
//Average turn around time = 19.666666
//*/