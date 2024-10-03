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

    int connection_sock, bytes_read, bytes_received;
    uint16_t port_number;
    struct sockaddr_in6 server_addr;
    char read_buffer[BUFFER_SIZE] = { 0 };
    char receive_buffer[BUFFER_SIZE] = { 0 };

    signal(SIGSEGV, signal_handler);
    connection_sock = check(socket(AF_INET6, SOCK_STREAM, 0), "Failed to create socket"); // IPv6, tcpのソケットを作成

    // IPv4も受け入れられるようにする
    int off = 0;
    check(setsockopt(connection_sock, IPPROTO_IPV6, IPV6_V6ONLY, &off, sizeof(off)), "Failed to set option to socket"); // IPv6, IPv4どちらも受け入れる

    port_number = atoi(port); // TODO: 16bit符号なし整数への丁寧な変換を行う
    check(set_ip_port(ip_address, port_number, &server_addr), "Invalid IP address or port number");

    check(connect(connection_sock, (struct sockaddr *)&server_addr, (socklen_t)sizeof(server_addr)), "Failed to connect to server");
    printf("Successful connection to %s:%d\n", ip_address, port_number);


    while ((bytes_read = read(STDIN_FILENO, read_buffer, BUFFER_SIZE)) > 0) {
        int bytes_sent = 0;
        while (bytes_sent < bytes_read) {
            int sent_now = send(connection_sock, read_buffer + bytes_sent, bytes_read - bytes_sent, 0);
            if (sent_now < 0) {
                fprintf(stderr, "Failed to send message");
                close(connection_sock);
                break;
            }
            bytes_sent += sent_now;
        }
        bytes_received = recv(connection_sock, receive_buffer, BUFFER_SIZE, 0);
            print_buffer("Received: ", read_buffer, bytes_received);
        if (bytes_received < 0) {
            fprintf(stderr, "Failed to receive message");
            break;
        }
    }
    if (bytes_read < 0) {
        fprintf(stderr, "Failed to receive message");
    }
    close(connection_sock);

}
