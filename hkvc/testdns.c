/**
 * Test DNS logic - Gen DNS queries and get results for specified list of domains.
 * HanishKVC, 2022
 *
 * One can specify how many seconds to sleep between dns queries.
 * Passing -ve sleepSecs will avoid sleeping between dns queries.
 *
 * It also calculates a sum of results of random prng of c library.
 * This is used to check that the random prng is not affected by dns query etal.
 */
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>


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
	if (argc <= 2) {
		printf("TestDNS:Usage: sleepSecs domain1 [domain2 ...]\n");
		return 1;
	}
	int sleepSecs = strtol(argv[1], 0, 0);
	printf("TestDNS:Sleep between dns queries [%d]\n", sleepSecs);
	for(int i=2; i < argc; i++) {
		test_dns(argv[i]);
		sumGlobalRandoms += random();
		if (sleepSecs > 0) {
			fprintf(stderr, "TestDNS:INFO: sleeping for %d secs...\n", sleepSecs);
			sleep(sleepSecs);
		}
	}
	printf("TestDNS:INFO: SumGlobalRandoms:%d\n", sumGlobalRandoms);
	return 0;
}

