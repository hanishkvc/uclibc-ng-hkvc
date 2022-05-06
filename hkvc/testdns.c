#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>


void test_dns(char *sName) {
	struct hostent *he = gethostbyname(sName);
	if (he == NULL) {
		printf("TestDNS:ERRR: GHbN:%s\n", sName);
		return;
	}
	printf("TestDNS:INFO: HN:%s\n",he->h_name);
	int i=-1;
	while(1) {
		i += 1;
		char *addr = he->h_addr_list[i];
		if (addr == NULL) break;
		printf("TestDNS:INFO: IP:%s\n",inet_ntoa(*(struct in_addr*)addr));
	}
}

int main(int argc, char **argv) {
	printf("TestDNS:INFO: hello world\n");
	int sumGlobalRandoms = 0;
	for(int i=1; i < argc; i++) {
		test_dns(argv[i]);
		sumGlobalRandoms += random();
	}
	printf("TestDNS:INFO: SumGlobalRandoms:%d\n", sumGlobalRandoms);
	return 0;
}

