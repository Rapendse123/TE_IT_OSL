// C Program to Implement the LRU(Least Recently Used) Page replacement Algorithm
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX 100

struct PageTable {
    int frame_no;
    int last_time_of_access;
    bool valid;
};

// function to check if referenced page is already present in frame[] or not
bool isPagePresent(struct PageTable pageTable[MAX], int page) {
    if (pageTable[page].valid) return true;
    else return false;
}

void updatePageTable(struct PageTable pageTable[MAX], int page, int frame_no, int status, int access_time) {
    pageTable[page].valid = status;
    if (pageTable[page].valid == 1) {   // [NOTE:] minor change unlike FIFO
        pageTable[page].last_time_of_access = access_time;
        pageTable[page].frame_no = frame_no;
    }
}

void printFrameContents(int frames[], int no_of_frames) {
    for (int i = 0; i < no_of_frames; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n");
}

// function to find victim page index (lru_page_index) in frames[]
void searchLRUPage(struct PageTable pageTable[MAX], int frames[], int no_of_frames, int *lru_page_index) {
    int min = INT_MAX;
    for (int i = 0; i < no_of_frames; i++) {
        if (min > pageTable[frames[i]].last_time_of_access) {
            min = pageTable[frames[i]].last_time_of_access;
            *lru_page_index = i;
        }
    }
}

void lru(struct PageTable pageTable[MAX], int reference_string[], int frames[], int no_of_pages, int no_of_frames) {
    int i, page_fault = 0, current = 0;
    bool flag = false;
    printf("\n*****contents of page table at different times*****\n");
    for (i = 0; i < no_of_pages; i++) {
        // search ith page in all allocated frames
        if (!isPagePresent(pageTable, reference_string[i])) {
            page_fault++;
            if (!flag && current < no_of_frames) {
                frames[current] = reference_string[i];
                printFrameContents(frames, no_of_frames);
                updatePageTable(pageTable, reference_string[i], current, 1, i);
                current++;
                if (current == no_of_frames) {
                    // current = 0;     [NOTE:] minor change unlike FIFO
                    flag = true;    // so that we do not come inside this if block again
                }
            } else {
                // frames are full, apply LRU algorithm
                // find victim page to replace
                // the page pointed by current is victim page to be replaced now
                // mark that page as invalid in page table
                // pass invalid frames as -1
                int lru_page_index;
                searchLRUPage(pageTable, frames, no_of_frames, &lru_page_index);
                updatePageTable(pageTable, frames[lru_page_index], -1, 0, i);

                frames[lru_page_index] = reference_string[i];
                printFrameContents(frames, no_of_frames);
                updatePageTable(pageTable, reference_string[i], current, 1, i);
            }
        }
        // update page access time for reference_string[i]
        pageTable[reference_string[i]].last_time_of_access = i;
    }
    printf("\ntotal no of page faults = %d\n", page_fault);
    printf("\ntotal no of page fault ratio = %.2f\n", (float) page_fault / no_of_pages);
    printf("\ntotal no of page hit ratio = %.2f\n", (float) (no_of_pages - page_fault) / no_of_pages);
}

int main() {
    int i, no_of_pages, no_of_frames;
    printf("Enter no of pages:\n");
    scanf("%d", &no_of_pages);

    int reference_string[no_of_pages];
    printf("\nEnter space separated reference string:\n");
    for (i = 0; i < no_of_pages; i++) {
        scanf("%d", &reference_string[i]);
    }

    printf("\nEnter no of frames to be allocated to process:\n");
    scanf("%d", &no_of_frames);

    // frames array to store pages at different point of times
    int frames[no_of_frames];
    memset(frames, -1, no_of_frames * sizeof(int));

    struct PageTable pageTable[MAX];
    for (i = 0; i < MAX; i++) {
        pageTable[i].valid = false;   // 0 means page fault
    }
    lru(pageTable, reference_string, frames, no_of_pages, no_of_frames);
    return 0;
}


/*
OUTPUT:
Enter no of pages:
10

Enter space separated reference string:
7 0 1 2 0 3 0 4 2 3

Enter no of frames to be allocated to process:
3

*****contents of page table at different times*****
7 -1 -1
7 0 -1
7 0 1
2 0 1
2 0 3
4 0 3
4 0 2
4 3 2

total no of page faults = 8

total no of page fault ratio = 0.80

total no of page hit ratio = 0.20
*/