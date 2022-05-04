#include <stdio.h>
#include <netdb.h>

void test_dns(char *sName) {
	struct hostent *he = gethostbyname(sName);
	printf("HN:%s\n",he->h_name);
	printf("IP:%x\n",he->h_addr);
}

int main(int argc, char **argv) {
	printf("hello world\n");
	test_dns("www.google.com");
	return 0;
}

