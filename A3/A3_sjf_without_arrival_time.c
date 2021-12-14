//// C program to implement non pre-emptive SJF with arrival time
//#include <stdio.h>
//#include <conio.h>
//
//#define MAX 100
//
//struct process {
//    int pid;
//    int arrival_time;
//    int burst_time;
//    int waiting_time;
//    int turn_around_time;
//};
//
//int main() {
//    struct process pr[MAX];
//    int i, j, n, temp;
//    float awt = 0; // avg waiting time
//    float atat = 0; // avg turn around time
//    printf("Enter no of processes:");
//    scanf("%d", &n);
//    for (i = 0; i < n; i++) {
//        pr[i].pid = i + 1;
//        printf("Enter arrival time of process %d:", i + 1);
//        scanf("%d", &pr[i].arrival_time);
//        printf("\n");
//    }
//
//    for (i = 0; i < n; i++) {
//        printf("Enter burst time of process %d:", i + 1);
//        scanf("%d", &pr[i].burst_time);
//        printf("\n");
//    }
//    // applying bubble sort to sort processes according to their burst times
//    for (i = 0; i < n - 1; i++) {
//        for (j = i + 1; j < n; j++) {
//            if (pr[i].burst_time > pr[j].burst_time) {
//                // sorting process id
//                temp = pr[i].pid;
//                pr[i].pid = pr[j].pid;
//                pr[j].pid = temp;
//                // sorting burst time
//                temp = pr[i].burst_time;
//                pr[i].burst_time = pr[j].burst_time;
//                pr[j].burst_time = temp;
//                // sorting arrival time
//                temp = pr[i].arrival_time;
//                pr[i].arrival_time = pr[j].arrival_time;
//                pr[j].arrival_time = temp;
//            }
//        }
//    }
//    printf("\n");
//    printf("process \t burst time \t waiting time \t turn around time\n");
//    for (i = 0; i < n; i++) {
//        pr[i].waiting_time = 0;
//        pr[i].turn_around_time = 0;
//        for (j = 0; j < i; j++) {
//            pr[i].waiting_time = pr[i].waiting_time + pr[j].burst_time;
//        }
//        pr[i].turn_around_time = pr[i].waiting_time + pr[i].burst_time;
//        awt = awt + pr[i].waiting_time;  // calculating sum
//        atat = atat + pr[i].turn_around_time;    // calculating sum
//        printf("%d\t\t %d\t\t %d\t\t %d\n",
//               pr[i].pid, pr[i].burst_time, pr[i].waiting_time, pr[i].turn_around_time);
//    }
//    awt = awt / n;
//    atat = atat / n;
//    printf("Average waiting time = %f\n", awt);
//    printf("Average turn around time = %f\n", atat);
//    getch();
//    return 0;
//}
//
///*
//OUTPUT:
//
//Enter no of processes:5
//Enter arrival time of process 1:3
//
//Enter arrival time of process 2:1
//
//Enter arrival time of process 3:4
//
//Enter arrival time of process 4:0
//
//Enter arrival time of process 5:2
//
//Enter burst time of process 1:1
//
//Enter burst time of process 2:4
//
//Enter burst time of process 3:2
//
//Enter burst time of process 4:6
//
//Enter burst time of process 5:3
//
//
//process          burst time      waiting time    turn around time
//1                1               0               1
//3                2               1               3
//5                3               3               6
//2                4               6               10
//4                6               10              16
//Average waiting time = 4.000000
//Average turn around time = 7.200000
//*/