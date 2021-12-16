//#include <unistd.h>
//#include <sys/types.h>
//#include <stdio.h>
//
//int main() {
//    pid_t q;
//    printf("before fork\n");
//    q = fork();
//    if (q == 0) {
//        printf("I am child having id %d\n", getpid());
//        printf("My parent's id is %d\n", getppid());
//    } else {
//        printf("My child's id %d\n", q);
//        printf("My parents id is %d\n", getpid());
//    }
//    return 0;
//}