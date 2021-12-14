//// Writer Process
//#include <sys/ipc.h>
//#include <sys/shm.h>
//#include <stdio.h>
//
//int main() {
//    // ftok to generate unique key
//    key_t key = ftok("shmfile", 65);
//
//    // shmget return an identifier in shmid
//    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);   // 0666 corresponds to read and write mode
//
//    // shmat to attach to shared memory
//    char *str = (char *) shmat(shmid, (void *) 0, 0);
//
//    printf("\nWrite data: ");
//    gets(str);
//    printf("\nData written into memory: %s\n", str);
//
//    // detach from shared memory
//    shmdt(str);
//
//    return 0;
//}
//
///*
//OUTPUT:
//rapen@rapen-VirtualBox:~/OS$ gcc writer.c -o writer
//writer.c: In function ‘main’:
//writer.c:17:5: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
//   17 |     gets(str);
//      |     ^~~~
//      |     fgets
///usr/bin/ld: /tmp/ccc8GF1w.o: in function `main':
//writer.c:(.text+0x6d): warning: the `gets' function is dangerous and should not be used.
//rapen@rapen-VirtualBox:~/OS$ gcc reader.c -o reader
//
//
//rapen@rapen-VirtualBox:~/OS$ ./writer
//
//Write data: Hello from writer
//
//Data written into memory: Hello from writer
//rapen@rapen-VirtualBox:~/OS$ ./reader
//
//Data read from memory: Hello from writer
//*/