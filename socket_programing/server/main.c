#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "../lib/utils.h"

#define BUFFER_SIZE 1024


int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    const char *port = argv[2];

    int listen_sock, connection_sock, bytes_received;
    uint16_t port_number;
    struct sockaddr_in6 server_addr, client_addr;
    char buffer[BUFFER_SIZE] = { 0 };

    // port_number = atoi(port); // TODO: 16bit符号なし整数への丁寧な変換を行う
    signal(SIGSEGV, signal_handler);
    listen_sock = check(socket(AF_INET6, SOCK_STREAM, 0), "Failed to create socket"); // IPv6, tcpのソケットを作成

    // IPv4も受け入れられるようにする
    int off = 0;
    check(setsockopt(listen_sock, IPPROTO_IPV6, IPV6_V6ONLY, &off, sizeof(off)), "Failed to set option to socket"); // IPv6, IPv4どちらも受け入れる

    port_number = atoi(port); // TODO: 16bit符号なし整数への丁寧な変換を行う
    check(set_ip_port(ip_address, port_number, &server_addr), "Invalid IP address or port number");


    check(bind(listen_sock, (struct sockaddr *)&server_addr, (socklen_t)sizeof(server_addr)), "Failed to bind sockaddr to sockfd");

    check(listen(listen_sock, SOMAXCONN), "Failed to listen sockfd");

    printf("Server is listening on %s:%d\n", ip_address, port_number);


    // 一度に一つのクライアントと接続して、エコーサーバになる
    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);
        connection_sock = check(accept(listen_sock, (struct sockaddr *)&client_addr, &client_addr_len), "Failed to establish connection");
        while ((bytes_received = recv(connection_sock, buffer, BUFFER_SIZE, 0)) > 0) {
            print_buffer("Received: ", buffer, bytes_received);
            int bytes_sent = 0;
            while (bytes_sent < bytes_received) {
                int sent_now = send(connection_sock, buffer + bytes_sent, bytes_received - bytes_sent, 0);

                if (sent_now < 0) {
                    fprintf(stderr, "Failed to send message");
                    close(connection_sock);
                    break;
                }
                bytes_sent += sent_now;
            }
        }
        if (bytes_received < 0) {
            fprintf(stderr, "Failed to receive message");
        }
        close(connection_sock);
    }

    check(close(connection_sock), "Failed to close connection socket properly");
    check(close(listen_sock), "Failed to close listen socket properly");









}
