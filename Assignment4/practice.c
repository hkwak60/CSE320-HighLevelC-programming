#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main() {
pid_t pid = fork();
if(pid == 0) { // Child
printf("before pause\n");
pause();
printf("after pause\n");
}
else { // Parent
sleep(1);
printf("killing child\n");
kill(pid, SIGKILL);
}
return 0;
}