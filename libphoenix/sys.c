#include <sys/syscall.h>

/* User-space wrappers for our new syscalls */
int setVariable(int var) {
    return syscall(125, var);
}

int getVariable(void) {
    return syscall(126);
}

/* Note: path_info_t  */
int getLongestPath(int skip_pid, void *info) {
    return syscall(127, skip_pid, info);
}

int setGroup(int group) {
    return __syscall(syscalls_setGroup, group);
}

int setQuanta(int group, int quanta) {
    return __syscall(syscalls_setQuanta, group, quanta);
}
