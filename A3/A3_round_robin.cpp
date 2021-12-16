// Assignment 3 - Round Robin Algorithm (C++ Code)

#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;
#define MAX 100

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int waiting_time;
    int turn_around_time;
    int response_time;
    int bt_remaining;
};

bool cmp_arrival_time(const struct process &p1, const struct process &p2) {
    return (p1.arrival_time <= p2.arrival_time);
}

bool cmp_pid(const struct process &p1, const struct process &p2) {
    return (p1.pid < p2.pid);
}

int main() {
    int n, index;
    struct process pr[MAX];
    float cpu_util;
    bool visited[MAX] = {false}, is_first_process = true;
    queue<int> queue;
    int current_time = 0;
    int completed = 0, tq = 0, total_idle_time = 0, length_cycle = 0;
    cout << "Enter total no of processes:\n";
    cin >> n;
    float sum_tat = 0, sum_wt = 0, sum_rt = 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout << "\nEnter process " << i << " arrival time:\n";
        cin >> pr[i].arrival_time;
        pr[i].pid = i;
    }
    for (int i = 0; i < n; i++) {
        cout << "\nEnter process " << i << " burst time:\n";
        cin >> pr[i].burst_time;
        pr[i].bt_remaining = pr[i].burst_time;
    }
    cout << "\nEnter time quantum:\n";
    cin >> tq;

    sort(pr, pr + n, cmp_arrival_time);
    queue.push(0);
    visited[0] = true;
    while (completed != n) {
        index = queue.front();
        queue.pop();
        if (pr[index].bt_remaining == pr[index].burst_time) {
            pr[index].start_time = max(current_time, pr[index].arrival_time);
            total_idle_time += (is_first_process) ? 0 : pr[index].start_time - current_time;
            current_time = pr[index].start_time;
            is_first_process = false;
        }
        if (pr[index].bt_remaining > tq) {
            pr[index].bt_remaining -= tq;
            current_time += tq;
        } else {
            current_time += pr[index].bt_remaining;
            pr[index].bt_remaining = 0;
            completed++;

            pr[index].completion_time = current_time;
            pr[index].turn_around_time = pr[index].completion_time - pr[index].arrival_time;
            pr[index].waiting_time = pr[index].turn_around_time - pr[index].burst_time;
            pr[index].response_time = pr[index].start_time - pr[index].arrival_time;

            sum_tat += (float) pr[index].turn_around_time;
            sum_wt += (float) pr[index].waiting_time;
            sum_rt += (float) pr[index].response_time;
        }

        // check which new processes needs to be pushed to Ready Queue from list
        for (int i = 1; i < n; i++) {
            if (pr[index].bt_remaining > 0 && pr[i].arrival_time <= current_time && !visited[i]) {
                queue.push(i);
                visited[i] = true;
            }
        }
        //check if Process on CPU needs to be pushed to Ready Queue
        if (pr[index].bt_remaining > 0)
            queue.push(index);

        // if queue is empty, just add one process from list, whose remaining burst time > 0
        if (queue.empty()) {
            for (int i = 1; i < n; i++) {
                if (pr[index].bt_remaining > 0) {
                    queue.push(i);
                    visited[i] = true;
                    break;
                }
            }
        }
    }

    // calculate Length of Process completion cycle
    int max_completion_time = INT_MIN;

    for (int i = 0; i < n; i++)
        max_completion_time = max(max_completion_time, pr[i].completion_time);

    length_cycle = max_completion_time - pr[0].arrival_time;
    cpu_util = (float) (length_cycle - total_idle_time) / length_cycle;

    sort(pr, pr + n, cmp_pid);

    // output
    cout << "\nProcess No.\tAT\tCPU Burst Time\tStart Time\tCT\tTAT\tWT\tRT\n";
    for (int i = 0; i < n; i++)
        cout << i << "\t\t"
             << pr[i].arrival_time << "\t"
             << pr[i].burst_time << "\t\t"
             << pr[i].start_time << "\t\t"
             << pr[i].completion_time << "\t"
             << pr[i].turn_around_time << "\t"
             << pr[i].waiting_time << "\t"
             << pr[i].response_time << '\n';
    cout << '\n';

    cout << "\nAverage Turn Around time= " << (float) sum_tat / n;
    cout << "\nAverage Waiting Time= " << (float) sum_wt / n;
    cout << "\nAverage Response Time= " << (float) sum_rt / n;
    cout << "\nThroughput= " << n / (float) length_cycle;
    cout << "\nCPU Utilization(Percentage)= " << cpu_util * 100;

    return 0;
}

/*
OUTPUT:
Enter total no of processes:
3

Enter process 0 arrival time:
1

Enter process 1 arrival time:
2

Enter process 2 arrival time:
3

Enter process 0 burst time:
10

Enter process 1 burst time:
5

Enter process 2 burst time:
8

Enter time quantum:
2

Process No.     AT      CPU Burst Time  Start Time      CT      TAT     WT      RT
0               1       10              1               24      23      13      0
1               2       5               3               16      14      9       1
2               3       8               5               22      19      11      2


Average Turn Around time= 18.67
Average Waiting Time= 11.00
Average Response Time= 1.00
Throughput= 0.13
CPU Utilization(Percentage)= 100.00
*/