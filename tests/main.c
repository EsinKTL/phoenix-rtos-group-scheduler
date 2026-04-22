#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/getsetvariable.h>

void busy_work(const char* name) {
    for (int i = 0; i < 15; i++) {
        for (volatile int j = 0; j < 1000000; j++);
        printf("Process %s is running...\n", name);
        usleep(100000);
    }
    exit(0);
}

void spawn_process(const char* name, int group) {
    pid_t pid = fork();
    if (pid == 0) {
        setGroup(group);
        busy_work(name);
    }
}

int main(void) {
    sleep(2);
    printf("\n--- Group-Based Scheduler Test Initiation ---\n\n");
    setQuanta(0, 1);
    setQuanta(1, 3);
    setQuanta(2, 2);

    spawn_process("a1", 0);
    spawn_process("b1", 1);
    spawn_process("c1", 2);

    while(wait(NULL) > 0);
    printf("\n--- Test Completed ---\n");
    return 0;
}
