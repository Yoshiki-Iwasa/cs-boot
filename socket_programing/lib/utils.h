#ifndef UTIL_H
#define UTIL_H

void signal_handler(int sig);

int check(int target, char message[]);

int set_ip_port(const char *ip_str, const uint16_t port ,struct sockaddr_in6 *addr_in6);

#endif
