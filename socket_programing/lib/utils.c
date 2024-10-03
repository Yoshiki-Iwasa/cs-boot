#include <execinfo.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

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
