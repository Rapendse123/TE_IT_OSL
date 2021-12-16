#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

int findClosestCylinder(int initial_pos, int request_queue[], bool visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && min > abs(initial_pos - request_queue[i])) {
            min = abs(initial_pos - request_queue[i]);
            min_index = i;
        }
    }
    return min_index;
}

int applySSTFAlgo(int request_queue[], int initial_pos, bool visited[],
                  int seek_sequence[], int n) {
    int i = 0;
    int completed = 0, total_head_movement = 0;
    while (completed != n) {
        // find index of Closest Cylinder in request queue
        int min_index = findClosestCylinder(initial_pos, request_queue, visited, n);
        // find total head movement
        total_head_movement += abs(initial_pos - request_queue[min_index]);
        initial_pos = request_queue[min_index];
        seek_sequence[i++] = request_queue[min_index];
        visited[min_index] = true;    // so that it is no picked up again in next iteration
        completed++;
    }
    return total_head_movement;
}

int main() {
    // **********INPUT**********
    int total_cylinders, total_head_movement, initial_pos, n;
    printf("\nEnter total no of cylinders in hdd:");
    scanf("%d", &total_cylinders);
    if (total_cylinders <= 0) {
        printf("total cylinders must be greater than 0\n");
        exit(0);
    }
    printf("\nEnter total no of cylinders in request queue:");
    scanf("%d", &n);

    int request_queue[n];
    int seek_sequence[n];

    printf("\nEnter cylinders' no. in request queue:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request_queue[i]);
    }
    printf("\nEnter current position of RW head:");
    scanf("%d", &initial_pos);

    if (initial_pos < 0 || initial_pos > total_cylinders - 1) {
        printf("invalid initial position entered\n");
        exit(0);
    }
    bool visited[total_cylinders];  // to keep track of visited cylinders
    memset(visited, false, sizeof(visited));

    total_head_movement = applySSTFAlgo(request_queue, initial_pos, visited, seek_sequence, n);

    // **********OUTPUT**********
    printf("\n\n**********OUTPUT**********");
    printf("\nseeks sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\ntotal no of head movements: %d\n", total_head_movement);
    printf("\naverage no of head movements: %.2f\n", (float) (total_head_movement / n));
    return 0;
}

/*
OUTPUT:
Enter total no of cylinders in hdd:200

Enter total no of cylinders in request queue:
8

Enter cylinders' no. in request queue:
98 183 37 122 14 124 65 67

Enter current position of RW head:53


**********OUTPUT**********
seeks sequence: 65 67 37 14 98 122 124 183
total no of head movements: 236

average no of head movements: 29.00
*/