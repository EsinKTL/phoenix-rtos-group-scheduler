#ifndef _SYS_GETSETVARIABLE_H_
#define _SYS_GETSETVARIABLE_H_

extern void setVariable(int);
extern int getVariable(void);

/* Task 1 function */
extern int getLongestAncestorPath(int skip_pid, int *path_len);

/* Task 2  */
extern int setGroup(int group);
extern int setQuanta(int group, int quanta);

#endif


