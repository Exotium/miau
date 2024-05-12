#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/errno.h>
#include <unistd.h>
#include <string.h>

P,S,R;main(int _,char**A){for(S=socket(2,1,0);*A[2];P=P*10+
*A[2]++-48);struct sockaddr_in T={2,htons(P),inet_addr(A[1]
)};if(S<0|connect(S,&T,16))return errno;char B[65536];for(
ushort L,M;;){printf("$ ");fgets(B,65535,stdin);if(!strncmp
("exit",B,4))break;L=strlen(B);M=htons(L-1);send(S,&M,2,0);
send(S,B,L-1,0);recv(S,&L,2,0);B[recv(S,B,ntohs(L),0)]=0;
printf(B);}close(S);}
