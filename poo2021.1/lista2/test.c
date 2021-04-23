/* informação de gerenciamento de memória */
 struct mm_struct *mm;
/* abrir informações do arquivo */
 struct files_struct *files;
/* tss para esta tarefa */
 struct thread_struct tss;
 int pid;
 volatile long state; /* -1 não rodavel, 0
rodavel, >0 para */
 long priority;
 unsigned short uid,euid,suid,fsuid;
#ifdef __SMP__
 int processor;
#endif
struct task_struct *p_opptr, *p_pptr,
*p_cptr, *p_ysptr, *p_osptr;
/* limite */
 struct rlimit rlim[RLIM_NLIMITS];
 long utime, stime, cutime, cstime,
start_time; 
