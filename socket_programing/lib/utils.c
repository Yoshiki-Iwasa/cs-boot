#include <stdio.h>
#include <sys/socket.h>
#include <execinfo.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>

void signal_handler(int sig) {
    void *array[10];
    size_t size;

    // スタックフレームを取得
    size = backtrace(array, 10);

    // スタックトレースを stderr に出力
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);

    exit(1);
}

int check(int target, char message[]) {
    if (target < 0) {
        fprintf(stderr, "%s: %s\n", message, strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        return target;
    }
}

int set_ip_port(const char *ip_str, const uint16_t port ,struct sockaddr_in6 *addr_in6) {
    memset(addr_in6, 0, sizeof(struct sockaddr_in6)); // ガベージデータを削除
    addr_in6->sin6_family = AF_INET6;  // AF_INET6を設定

    if (inet_pton(AF_INET6, ip_str, &addr_in6->sin6_addr) == 1) {
        addr_in6->sin6_port = htons(port);
        return 0; // IPV6で変換に成功
    }

    // IPv4をマッピングする方法で試す
    struct in_addr addr_in4;
    if (inet_pton(AF_INET, ip_str, &addr_in4) == 1) {

        // 80byteまで、0埋めしてその後16byteをffに
        // その後IPv4を埋め込む
        addr_in6->sin6_addr.s6_addr[10] = 0xff;
        addr_in6->sin6_addr.s6_addr[11] = 0xff;
        addr_in6->sin6_port = htons(port);
        memcpy(&addr_in6->sin6_addr.s6_addr[12], &addr_in4, sizeof(addr_in4));
        return 0;
    }

    return -1; // どちらも失敗した場合
}
