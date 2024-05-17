#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>



void main(){
    printf("My PID is %d and my parent's PID is %d\n", getpid(), getppid());
    int t=3;
    while(t--){
        pid_t id = fork();
        id == 0 ? printf("My PID is %d and my parent's PID is %d\n", getpid(), getppid()) : 1;
    }exit(0);
}

