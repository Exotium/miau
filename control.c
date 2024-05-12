#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 3) return 1;
    char *hostaddr = argv[1];
    ushort port = 0;
    char* portstr = argv[2];
    while(*portstr) port = port * 10 + *portstr++ - '0';

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) return errno;

    struct sockaddr_in sa = {AF_INET, htons(port), inet_addr(hostaddr)};
    if (connect(sock, (struct sockaddr *) &sa, sizeof(sa)) == -1) return errno;

    char buf[65536] = {};
    ushort len;
    for (;;) {
        printf("$ ");
        fgets(buf, 65535, stdin); // no overflow protection lmao
        if (!strncmp("exit", buf, 4)) break;

        len = strlen(buf);
        ushort netlen = htons(len - 1);
        send(sock, &netlen, 2, 0);
        send(sock, buf, len - 1, 0);

        int recvn;
        recv(sock, &len, 2, 0);
        len = ntohs(len);
        recvn = (int)recv(sock, buf, len, 0);
        buf[recvn] = 0;
        printf("%s", buf);

    }
    close(sock);
}