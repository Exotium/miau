#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    ushort port = 0;
    char* portstr = argv[1];
    while(*portstr) port = port * 10 + *portstr++ - '0';

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) return errno;

    // avoid "address in use" error when restarting the program
    int option = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    struct sockaddr_in sa = {AF_INET, htons(port), htonl(INADDR_ANY) };
    if (bind(sock, (struct sockaddr*)&sa, sizeof(sa)) == -1) return errno;
    if (listen(sock, 0) == -1) return errno;

    char buf[65536] = {};
    int loop = 1;
    while (loop) {
        int client = accept(sock, NULL, 0);
        if (client == -1) return errno;

        int recvn;
        for (;;) {
            ushort len;
            recv(client, &len, 2, 0);
            len = ntohs(len);

            recvn = (int)recv(client, buf, len, 0);
            if (recvn <= 0) break;
            buf[recvn] = 0;

            if (!strncmp("quit", buf, 4)) {
                loop = 0;
                break;
            }

            FILE* cmd = popen(buf, "r");
            size_t read = fread(buf, 1, 65535, cmd);
            buf[read] = 0;

            ushort netlen = htons(read);
            send(client, &netlen, 2, 0);
            send(client, buf, read, 0);
        }
        close(client);
    }
    close(sock);
}