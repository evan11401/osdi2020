
// define system call table
#define __NR_syscalls	    8

#define SYS_WRITE_NUMBER    0 		// syscal numbers 
#define SYS_MALLOC_NUMBER   1 	
#define SYS_CLONE_NUMBER    2 	
#define SYS_EXIT_NUMBER     3 	
#define SYS_CHK_EXL         4 
#define SYS_ENABLE_TIME     5
#define SYS_CHK_EXL_INFO    6
#define SYS_GET_TASKID      7

#ifndef __ASSEMBLER__
void sys_write(char * buf);


void call_sys_write(char * buf);
int call_sys_clone(unsigned long fn);
unsigned long call_sys_malloc();
void call_sys_exit();
void call_sys_chk_exl();
void call_sys_chk_exl_info();
void call_sys_enable_time();
int call_sys_get_taskid();
#endif