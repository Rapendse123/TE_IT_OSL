//// C program to implement pre-emptive SJF without arrival time
//#include <stdio.h>
//#include <stdbool.h>
//#include <limits.h>
//
//#define MAX 100
//
//struct process {
//    int pid;
//    int arrival_time;
//    int burst_time;
//    int start_time;
//    int completion_time;
//    int turnaround_time;
//    int waiting_time;
//    int response_time;
//};
//
//int main() {
//    struct process pr[MAX];
//    bool is_completed[MAX] = {false};  // to mark which processes are completed
//    int bt_remaining[MAX];
//
//    bool is_first_process = true;
//    int current_time = 0, completed = 0;
//    float sum_tat = 0, sum_wt = 0, sum_rt = 0;
//    float total_idle_time = 0, prev = 0,cpu_util;
//
//    int n;
//    printf("Enter no of processes:");
//    scanf("%d", &n);
//
//    for (int i = 0; i < n; i++) {
//        printf("Enter arrival time of process %d:", i + 1);
//        scanf("%d", &pr[i].arrival_time);
//        pr[i].pid = i + 1;
//        printf("\n");
//    }
//    for (int i = 0; i < n; i++) {
//        printf("Enter burst time of process %d:", i + 1);
//        scanf("%d", &pr[i].burst_time);
//        bt_remaining[i] = pr[i].burst_time;
//        printf("\n");
//    }
//    while (completed != n) {
//        // find the process with min burst time in ready queue at current time
//        int mn = INT_MAX;   // to find the process with min burst time
//        int min_index = -1;   // index of process with min burst time
//        for (int i = 0; i < n; i++) {
//            if (pr[i].arrival_time <= current_time && !is_completed[i]) {
//                if (bt_remaining[i] < mn) {
//                    mn = bt_remaining[i];
//                    min_index = i;
//                } else if (bt_remaining[i] == mn) {
//                    if (pr[i].arrival_time < pr[min_index].arrival_time) {
//                        mn = bt_remaining[i];
//                        min_index = i;
//                    }
//                }
//            }
//        }
//        if (min_index == -1) {
//            current_time++;
//        } else {
//            if (bt_remaining[min_index] == pr[min_index].burst_time) {
//                pr[min_index].start_time = current_time;
//                total_idle_time += (is_first_process) ? 0 : pr[min_index].start_time - prev;
//                is_first_process = false;
//            }
//            bt_remaining[min_index]--;
//            current_time++;
//            prev = current_time;
//            if (bt_remaining[min_index] == 0) {
//                pr[min_index].completion_time = current_time;
//                pr[min_index].turnaround_time = pr[min_index].completion_time - pr[min_index].arrival_time;
//                pr[min_index].waiting_time = pr[min_index].turnaround_time - pr[min_index].burst_time;
//                pr[min_index].response_time = pr[min_index].start_time - pr[min_index].arrival_time;
//                sum_tat += pr[min_index].turnaround_time;
//                sum_wt += pr[min_index].waiting_time;
//                sum_rt += pr[min_index].response_time;
//                is_completed[min_index] = true;
//                completed++;
//            }
//        }
//    }
//
//    // Calculate Length of Process completion cycle
//    int min_arrival_time = INT_MAX, max_completion_time = INT_MIN;
//    for (int i = 0; i < n; i++) {
//        if (min_arrival_time > pr[i].arrival_time) {
//            min_arrival_time = pr[i].arrival_time;
//        }
//        if (max_completion_time < pr[i].completion_time) {
//            max_completion_time = pr[i].completion_time;
//        }
//    }
//
//    int length_cycle = max_completion_time - min_arrival_time;
//    float avg_tat = (float) sum_tat / (float) n;
//    float avg_wt = (float) sum_wt / (float) n;
//    float avg_rt = (float) sum_rt / (float) n;
//    cpu_util = (float) (length_cycle) / (float) (max_completion_time);
//    float throughput = (float) n / (float) (max_completion_time - min_arrival_time);
//    printf("\n\n");
//    printf("#P\t AT\t BT\t ST\t CT\t TAT\t WT\t RT\t \n");
//    for (int i = 0; i < n; i++) {
//        printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d",
//               pr[i].pid, pr[i].arrival_time, pr[i].burst_time, pr[i].start_time,
//               pr[i].completion_time, pr[i].turnaround_time, pr[i].waiting_time,
//               pr[i].response_time);
//        printf("\n");
//    }
//    printf("\n\n");
//    printf("Average turnaround time: ");
//    printf("%f", avg_tat);
//    printf("\n");
//
//    printf("Average waiting time: ");
//    printf("%f", avg_wt);
//    printf("\n");
//
//    printf("Average response time: ");
//    printf("%f", avg_rt);
//    printf("\n");
//
//    printf("CPU Utilization: ");
//    printf("%f", cpu_util);
//    printf("\n");
//
//    printf("Throughput: ");
//    printf("%f", throughput);
//    printf("\n");
//    return 0;
//}