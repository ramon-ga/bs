/* Nach: An Introductory 4.3BSD IPC Tutorial, S. Sechrest */
/* 03.12.04 / gle */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main () {
  pid_t pid;
  int status;

  if (fork() == 0) {
    printf ("Child executing \"/bin/date\"\n");
    execl ("/bin/date", "date", NULL);
//    execl ("forktest", "", NULL);

    printf ("This should not happen!\n");
  }else{ 
//	while(1);
  }
  printf ("Parent waiting for child's dead\n");
  pid=wait (&status);
  printf ("Parent: Child just died.\n");
//  exit(0);
}
