//// Process 2
//#include <stdio.h>
//#include <string.h>
//// Below header files are required to make low and high level system calls
//#include <fcntl.h>
//
//int main() {
//    FILE *fp;
//    int fd1, fd2;
//    char *my_fifo1 = "file1", *my_fifo2 = "file2";
//    char str1[100], str2[100];
//    char ch;
//    int lines = 1, words = 1, characters = 0;    // no of lines, words, characters
//
//    // read data from first my_fifo1 file
//    fd1 = open(my_fifo1, O_RDONLY);
//    read(fd1, str1, 100);
//    printf("\nPipe1: %s", str1);
//
//    // count no of lines words and characters in a sentence
//    int i = 0;
//    while (str1[i] != '\0') {
//        if (str1[i] == '.' || str1[i] == '\n') lines++;
//        else if (str1[i] == ' ') words++;
//        else characters++;
//        i++;
//    }
//
//    // print the result
//    printf("\nno of lines: %d\n", lines);
//    printf("\nno of words: %d\n", words);
//    printf("\nno of characters: %d\n", characters);
//
//    // write counted lines, words, characters data into a text file
//    fp = fopen("kp.txt", "w");
//    fprintf(fp, "\nno of lines: %d\n", lines);
//    fprintf(fp, "\nno of words: %d\n", words);
//    fprintf(fp, "\nno of characters: %d\n", characters);
//    fclose(fp);
//
//    fp = fopen("kp.txt", "r");
//    ch = fgetc(fp);
//    i = 0;
//    while (ch != EOF) {
//        str2[i++] = ch;
//        ch = fgetc(fp);
//    }
//    str2[i] = '\0';
//    fclose(fp);
//    close(fd1);
//
//    // write data of text file onto second fifo pipe
//    fd2 = open(my_fifo2, O_WRONLY);
//    write(fd2, str2, strlen(str2) + 1);
//    close(fd2);
//}
//
///*
//OUTPUT:
//
//rapen@rapen-VirtualBox:~$ cd OS
//rapen@rapen-VirtualBox:~/OS$ gcc A7a_fifo2.c -o f2
//rapen@rapen-VirtualBox:~/OS$ ./f2
//
//Pipe1: Hello World Rohit here
//
//no of lines: 2
//
//no of words: 4
//
//no of characters: 19
//*/