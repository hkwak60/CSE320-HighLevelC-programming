#include <unistd.h>
#include <stdio.h>

int main(){
  char *command[]={"grep", "-E", "c$", "-", 0};
  char *bin_file = command[0];
  pid_t pid = fork();
  if(execvp(bin_file, command)){
    fprintf(stderr, "Error executing %s\n", bin_file);
  }
  printf("done!\n");
}