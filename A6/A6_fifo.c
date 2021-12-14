//// C program to implement FIFO page replacement algorithm
//// Time Complexity = O(n)
//// Space Complexity = O(no of frames + size of Page Table)
//
//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//
//#define MAX 50
//struct PageTable {  // used for hashing => O(1)
//    int frame_no;
//    bool valid;
//};
//
//// function to check if referenced page is already present in frame[] or not
//bool isPagePresent(struct PageTable pageTable[MAX], int page) {
//    if (pageTable[page].valid) return true;
//    else return false;
//}
//
//
//void printFrameContents(int frames[], int no_of_frames) {
//    for (int i = 0; i < no_of_frames; i++) {
//        printf("%d ", frames[i]);
//    }
//    printf("\n");
//}
//
//void updatePageTable(struct PageTable pageTable[], int page, int frame_no, int status) {
//    pageTable[page].valid = status;
//    pageTable[page].frame_no = frame_no;
//}
//
//void fifo(struct PageTable pageTable[], int reference_string[], int frames[], int no_of_pages, int no_of_frames) {
//    int i, page_fault = 0, current = 0;
//    bool flag = false;
//    printf("\n*****contents of page table at different times*****\n");
//    for (i = 0; i < no_of_pages; i++) {
//        // search ith page in all allocated frames
//        if (!isPagePresent(pageTable, reference_string[i])) {
//            page_fault++;
//            if (!flag && current < no_of_frames) {
//                frames[current] = reference_string[i];
//                printFrameContents(frames, no_of_frames);
//                updatePageTable(pageTable, reference_string[i], current, 1);
//                current++;
//                if (current == no_of_frames) {
//                    current = 0;
//                    flag = true;    // so that we do not come inside this if block again
//                }
//            } else {
//                // frames are full, apply FIFO
//                // find victim page to replace
//                // the page pointed by current is victim page to be replaced now
//                // mark that page as invalid in page table
//                // set invalid frames as -1
//                updatePageTable(pageTable, frames[current], -1, 0);
//                frames[current] = reference_string[i];
//                printFrameContents(frames, no_of_frames);
//                updatePageTable(pageTable, reference_string[i], current, 1);
//                current = (current + 1) % no_of_frames;
//            }
//        }
//    }
//    printf("\ntotal no of page faults = %d\n", page_fault);
//    printf("\ntotal no of page fault ratio = %.2f\n", (float) page_fault / no_of_pages);
//    printf("\ntotal no of page hit ratio = %.2f\n", (float) (no_of_pages - page_fault) / no_of_pages);
//}
//
//int main() {
//    int i, no_of_pages, no_of_frames;
//
//    printf("Enter no of pages:\n");
//    scanf("%d", &no_of_pages);
//
//    int reference_string[no_of_pages];
//    printf("\nEnter space separated reference string:\n");
//    for (i = 0; i < no_of_pages; i++) {
//        scanf("%d", &reference_string[i]);
//    }
//
//    printf("\nEnter no of frames to be allocated to process:\n");
//    scanf("%d", &no_of_frames);
//
//    // frames array to store pages at different point of times
//    int frames[no_of_frames];
//    memset(frames, -1, no_of_frames * sizeof(int));
//
//    struct PageTable pageTable[MAX];
//    for (i = 0; i < MAX; i++) {
//        pageTable[i].valid = false;   // 0 means page fault
//    }
//    fifo(pageTable, reference_string, frames, no_of_pages, no_of_frames);
//    return 0;
//}
//
///*
//OUTPUT:
//Enter no of pages:
//12
//
//Enter space separated reference string:
//7 0 1 2 0 3 0 4 2 3 0 3
//
//Enter no of frames to be allocated to process:
//3
//
//*****contents of page table at different times*****
//7 -1 -1
//7 0 -1
//7 0 1
//2 0 1
//2 3 1
//2 3 0
//4 3 0
//4 2 0
//4 2 3
//0 2 3
//
//total no of page faults = 10
//
//total no of page fault ratio = 0.83
//
//total no of page hit ratio = 0.17
//*/