//echo_server.c
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "util.h"
#include <errno.h>

#define SERV_PORT   6000
#define MAXLINE     512

void echo(int fd) {
    char sline[MAXLINE], rline[MAXLINE];
    while(1) { 
        char line[MAXLINE];
        int n = readline(fd, line, MAXLINE);
        CHKBOOLQUIT(n >= 0, "readline error");
        if(strcmp(line,"exit\n")==0){                       //When client enters exit
            printf("CSE320:received a message:exit\n"); 
            printf("CSE320:send a message:exit\n"); 
            writen(fd, "exit", strlen("exit"));
            return;
        }
        else if(strcmp(line,"exit")==0){                    //When server entered exit
            printf("CSE320:received a message:exit\n");
            return;
        }
        if(strlen(line)>50||strlen(sline)>50){               //When either input is over 50 characters
            printf("ERROR: too many characters\n");
            return;
        }
        if(n == 0){ //connection terminated
            return;}
        else{
            printf("CSE320:received a message : %s",line);
            printf("CSE320:send a message : ");
            while(fgets(sline, MAXLINE, stdin) != NULL){
                int a = strlen(sline);
                CHKBOOLQUIT( writen(fd, sline, a) == a, "writen error" );
                n = readline(fd, line, MAXLINE);
                CHKBOOLQUIT(n >= 0, "readline error");
                if(strcmp(line,"exit\n")==0){                  //When client enters exit
                    printf("CSE320:received a message : exit\n"); 
                    printf("CSE320:send a message : exit\n"); 
                    writen(fd, "exit", strlen("exit"));
                    return;
                }
                else if(strcmp(line,"exit")==0){                //When server entered exit
                    printf("CSE320:received a message : exit\n");
                    return;
                }
                if(strlen(line)>50||strlen(sline)>50){          //When either input is over 50 characters
                    printf("ERROR: too many characters\n");
                    writen(fd, line, strlen(line));
                    return;
                }
                printf("CSE320:received a message : %s",line);
                printf("CSE320:send a message : ");
            }
        }
    }
}

int main(int argc, char **argv) {
    int sfd;
    struct sockaddr_in saddr;

    CHKBOOLQUIT( (sfd = socket(AF_INET, SOCK_STREAM, 0)) >= 0, "socket failed" );
    printf("CSE320:socket successfully created\n");
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(SERV_PORT);
    CHKBOOLQUIT( bind(sfd, (struct sockaddr*)&saddr, sizeof(saddr)) >= 0, strerror(errno));
    printf("CSE320:socket successfully binded\n");
    CHKBOOLQUIT( listen(sfd, 1024) >= 0, "listen failed" );
    printf("CSE320:server listening\n");

    while(1) {
        struct sockaddr_in caddr;
        int cfd, clen = sizeof(caddr);
        CHKBOOLQUIT( (cfd = accept(sfd, (struct sockaddr*) &caddr, &clen)) >= 0,"accept failed");
        printf("CSE320:server accept the client\n");
        pid_t pid = fork();
        if(pid == 0) {   //child
            close(sfd);
            echo(cfd);
            exit(0);
        }
        else {
            waitpid(pid, NULL, 0);
            close(cfd);
            printf("CSE320: exit server\n");
            exit(0);
        }
    }
    return 0;
}

