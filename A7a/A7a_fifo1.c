//// Process 1
//#include <stdio.h>
//#include <string.h>
//#include <unistd.h>
//// Below header files are required to make low and high level system calls
//#include <fcntl.h>
//#include <sys/stat.h>
//#include <sys/types.h>
//
//int main() {
//    int fd1, fd2;   // variables to store file data
//    char *my_fifo1 = "file1", *my_fifo2 = "file2";
//    char str1[100], str2[100];
//
//    // create FIFO files
//    // 0666 => files to be used only for reading and writing purpose (chmod command)
//    fd1 = mkfifo(my_fifo1, 0666);
//    fd2 = mkfifo(my_fifo2, 0666);
//
//    // read data to write on first pipe
//    printf("\nEnter string:");
//    // [NOTE] - scanf() cannot be used because it cannot read input with spaces
//    fgets(str1, 100, stdin);
//
//    // write data on first fifo pipe
//    fd1 = open(my_fifo1, O_WRONLY);   // open in write mode only (low level system call)
//    write(fd1, str1, strlen(str1) + 1);
//    close(fd1);
//
//    // Read data from second pipe
//    fd2 = open(my_fifo2, O_RDONLY);
//    read(fd2, str2, 100);
//
//    // Print output
//    printf("\nMessage from fifo2 process:\n%s", str2);
//    close(fd2);
//}
//
///*
//OUTPUT:
//
//rapen@rapen-VirtualBox:~/OS$ gcc A7a_fifo1.c -o f1
//rapen@rapen-VirtualBox:~/OS$ ./f1
//
//Enter string:Hello World Rohit here
//
//Message from fifo2 process:
//
//no of lines: 2
//
//no of words: 4
//
//no of characters: 19
//*/