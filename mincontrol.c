#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

P,S;main(int _,char**V){for(S=socket(2,1,0);*V[2]
;P=P*10+*V[2]++-48);struct sockaddr_in A={2,htons
(P),inet_addr(V[1])};char B[65537];for(ushort L,N
=connect(S,&A,16);strncmp("exit",fgets(B,printf(
"$ ")<<15,stdin),4);L=strlen(B),N=htons(L-1),send
(S,&N,2,0),send(S,B,L-1,0),recv(S,&L,2,0),B[recv(
S,B,ntohs(L),0)]=0,printf(B));}
