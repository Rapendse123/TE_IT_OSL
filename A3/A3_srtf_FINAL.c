#include<stdio.h>
#include<limits.h>

int n;
struct process {
    int bt, at, wt, tat, pid;
    int count;
};
typedef struct process process;
process p[10];

void printt() {

    printf("Process\tAT\tBT\tCounter\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].count, p[i].wt, p[i].tat);
    }
}

void sort() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int minimum(int tot) {
    int min = INT_MAX;
    int index = -1;
    int i = 0;
    while ((p[i].at <= tot) && i < n) {
        if (p[i].count == 0) {
            i++;
            continue;
        }

        if (p[i].count < min) {
            min = p[i].count;
            index = i;
        }

        i++;
    }
    return index;
}

void sjf() {
    int tot = 0, fin = 0;

    process gantt[100];
    while (fin < n) {
        int min = minimum(tot);
        gantt[tot].count = p[min].pid;
        tot++;

        if (--p[min].count == 0) {
            p[min].tat = tot - p[min].at;
            p[min].wt = p[min].tat - p[min].bt;
            fin++;
        }
    }
    printf("\nTotal time spent :- %d\n", tot);
    printt();
    int avgtat = 0, avgwt = 0;
    for (int i = 0; i < n; i++) {
        avgwt += p[i].wt;
        avgtat += p[i].tat;
    }

    printf("Average wt = %f \nAverage tat = %f\n", (float) avgwt / n, (float) avgtat / n);

    //print gantt chart
    printf("Gantt Chart :- \n");
    int num = 0;
    int prev = 0;
    for (int i = 0; i < tot; i++) {

        if (gantt[i].count != prev) {
            printf(" | P%d", gantt[i].count);
        }
        prev = gantt[i].count;

    }
    printf(" |");

    printf("\n");
    // printf(" 0   ");
    for (int i = 0; i < tot; i++) {


        if (gantt[i].count != prev) {
            printf(" %d   ", num);


        }
        prev = gantt[i].count;
        num = num + 1;
    }
    printf(" %d   ", tot);
    printf("\n");

}

int main() {
    printf("\nEnter total processes(<10)\n");
    scanf("%d", &n);

    //Input and initialize
    printf("\nEnter space separated values for at and bt sequentially\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].at);
        scanf("%d", &p[i].bt);
        p[i].wt = p[i].tat = -1;
        p[i].count = p[i].bt;
        p[i].pid = i + 1;
    }
    sort();
    sjf();
}

/*
OUTPUT
Enter total processes(<10)
5

Enter space separated values for at and bt sequentially
2 6
5 2
1 8
0 3
4 4

Total time spent :- 23
Process	AT	BT	Counter	WT	TAT
p4	0	3	0	0	3
p3	1	8	0	14	22
p1	2	6	0	7	13
p5	4	4	0	2	6
p2	5	2	0	0	2
Average wt = 4.600000
Average tat = 9.200000
Gantt Chart :-
 | p4 | p1 | p5 | p2 | p5 | p1 | p3 |
 0    3    4    5    7    10    15    23
*/