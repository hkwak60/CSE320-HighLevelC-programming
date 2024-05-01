//echo_client.c
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "util.h"

#define SERV_ADDR   "127.0.0.1"
#define SERV_PORT   6000
#define MAXLINE     512

void copy(int sfd) {
    char sline[MAXLINE], rline[MAXLINE];
    while(1){
        printf("CSE320:send a message : ");
        while(fgets(sline, MAXLINE, stdin) != NULL) {
            int n = strlen(sline);
            CHKBOOLQUIT( writen(sfd, sline, n) == n, "writen error" );
            CHKBOOLQUIT( (n = readline(sfd, rline, MAXLINE)) >= 0, "readline error" );
            if(strcmp(rline,"exit\n")==0){                          //When server enters exit
                printf("CSE320:received a message : exit\n");
                printf("CSE320:send a message : exit\n"); 
                writen(sfd, "exit", strlen("exit"));
                return;
            }
            else if(strcmp(rline,"exit")==0){                       //When client entered exit
                printf("CSE320:received a message : exit\n");
                return;
            }
            if(strlen(rline)>50||strlen(sline)>50){                 //Both when length is over 50
                printf("ERROR: too many characters\n");
                writen(sfd, rline, strlen(rline));
                return;
            }
            printf("CSE320:received a message : ");
            rline[n] = 0;
            fputs(rline, stdout);
            printf("CSE320:send a message : ");
        }
        CHKBOOLQUIT( ferror(stdin) == 0, "cannot read file" );
    }
}

int main(int argc, char **argv) {
    int sfd;
    struct sockaddr_in saddr;

    CHKBOOLQUIT( (sfd = socket(AF_INET, SOCK_STREAM, 0)) >= 0,"socket failed" );
    printf("CSE320:socket successfully created\n");

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr(SERV_ADDR);
    saddr.sin_port = htons(SERV_PORT);

    CHKBOOLQUIT( connect(sfd, (struct sockaddr*)&saddr, sizeof(saddr)) >= 0,"connectfailed" );
    // printf("server: %s:%d\n", inet_ntoa(saddr.sin_addr), saddr.sin_port);
    printf("CSE320:connected to the server\n");

    copy(sfd);
    printf("CSE320:exit client\n");
    close(sfd);
    exit(0);
    return 0;
}
