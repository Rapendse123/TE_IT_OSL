//# include <stdio.h>
//
//struct process {
//    char name;
//    int at, bt, rt, ct, tat, wt;
//    int completed;
//} p[10];
//
//int n;
//int q[10];
//int rear = -1, front = -1;
//
//void enqueue(int i) {
//    if (rear == 9) {
//        printf("Overflow");
//        fflush(stdout);
//        return;
//    }
//    rear++;
//    q[rear] = i;
//    if (front == -1) {
//        front = 0;
//    }
//}
//
//int dequeue() {
//    if (front == -1) {
//        printf("Underflow");
//        fflush(stdout);
//        return -1;
//    }
//    int ret = q[front];
//    if (front == rear) {
//        front = rear = -1;
//    } else {
//        front++;
//    }
//    return ret;
//}
//
//int inQueue(int i) {
//    for (int j = front; j <= rear; j++) {
//        if (q[j] == i) {
//            return 1;
//        }
//    }
//    return 0;
//}
//
//void sortByArrival() {  // Insertion Sort
//    struct process temp;
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (p[i].at > p[j].at) {
//                temp = p[i];
//                p[i] = p[j];
//                p[j] = temp;
//            }
//        }
//    }
//}
//
//void roundRobin() {
//    int i, j, time = 0, total_bt = 0, avg_wt = 0, avg_tat = 0, tq, count = n;
//    char c;
//    printf("Enter no of processes:");
//    fflush(stdout);
//    scanf("%d", &n);
//
//    for (i = 0, c = 'A'; i < n; i++, c++) {
//        p[i].name = c;
//        printf("\nEnter the arrival time and burst time of process %c seperated by a space: ", p[i].name);
//        fflush(stdout);
//        scanf("%d %d", &p[i].at, &p[i].bt);
//        p[i].rt = p[i].bt;
//        p[i].completed = 0;
//        total_bt += p[i].bt;
//    }
//
//    sortByArrival();
//
//    printf("\nEnter the time quantum:");
//    fflush(stdout);
//    scanf("%d", &tq);
//
//    printf("The execution sequence is : ");
//    fflush(stdout);
//
//    enqueue(0);
//
//    for (time = p[0].at; time < total_bt;) { // Run until total burst time is reached
//        i = dequeue();
//        if (p[i].rt <= tq) {
//            time += p[i].rt;
//            p[i].rt = 0;
//            printf(" %c ", p[i].name);
//            fflush(stdout);
//            p[i].ct = time;
//            p[i].wt = time - p[i].at - p[i].bt;
//            p[i].tat = time - p[i].at;
//            avg_tat += p[i].tat;
//            avg_wt += p[i].wt;
//            p[i].completed = 1;
//            count++;
//            // Enqueue the processes that arrived now
//            for (j = 0; j < n; j++) {
//                if (p[j].at <= time && p[j].completed == 0 && inQueue(j) != 1) {
//                    enqueue(j);
//                }
//            }
//        } else {
//            time += tq;
//            p[i].rt -= tq;
//            printf(" %c ", p[i].name);
//            fflush(stdout);
//            for (j = 0; j < n; j++) {
//                if (p[j].at <= time && p[j].completed == 0 && inQueue(j) != 1 && i != j) {
//                    enqueue(j);
//                }
//            }
//            enqueue(i); // then enqueue the uncompleted process
//        }
//    }
//
//    printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time\tCompletion Time");
//    fflush(stdout);
//    for (i = 0; i < n; i++) {
//        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i].name, p[i].at, p[i].bt, p[i].wt, p[i].tat, p[i].ct);
//        fflush(stdout);
//    }
//    printf("\nAverage waiting time:%f\n", avg_wt / n);
//    fflush(stdout);
//}
//
//void sjf_p() {
//    int i, j, time = 0, total_bt = 0, avg_wt = 0, avg_tat = 0, count = 0;
//    char c;
//    printf("Enter no of processes:");
//    fflush(stdout);
//    scanf("%d", &n);
//
//    for (i = 0, c = 'A'; i < n; i++, c++) {
//        p[i].name = c;
//        printf("\nEnter the arrival time and burst time of process %c seperated by a space: ", p[i].name);
//        fflush(stdout);
//        scanf("%d %d", &p[i].at, &p[i].bt);
//        p[i].rt = p[i].bt;
//        p[i].completed = 0;
//        total_bt += p[i].bt;
//    }
//
//    printf("The execution sequence is : ");
//    fflush(stdout);
//
//    for (time = 0; count != n; time++) {
//        int shortest_time = 9999;
//        j = 0;                    // Index of the process with shortest rt
//        for (i = 0; i < n; i++) {
//            if (p[i].at <= time && p[i].completed != 1 && p[i].rt < shortest_time) {
//                shortest_time = p[i].rt;
//                j = i;
//            }
//        }
//        p[j].rt--;
//        //printf(" %c ",p[j].name);
//        if (p[j].rt == 0) {
//            p[j].completed = 1;
//            int end = time + 1;
//            count++;
//            printf("\nProcess %d completed atr time %d.\n", j, end);
//            fflush(stdout);
//            p[j].ct = end;
//            p[j].wt = end - p[j].at - p[j].bt;
//            p[j].tat = end - p[j].at;
//            avg_tat += p[j].tat;
//            avg_wt += p[j].wt;
//        }
//    }
//
//    printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time\tCompletion Time");
//    fflush(stdout);
//    for (i = 0; i < n; i++) {
//        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i].name, p[i].at, p[i].bt, p[i].wt, p[i].tat, p[i].ct);
//        fflush(stdout);
//    }
//    avg_wt /= n;
//    printf("\nAverage waiting time:%f\n", (avg_wt / n));
//    fflush(stdout);
//}
//
//int main() {
//    roundRobin();
//    sjf_p();
//    return 0;
//}
