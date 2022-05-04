
LPATH="/usr/x86_64-linux-uclibc/usr/lib/"

# Ensure gcc doesnt include the default set of paths and files wrt includes and libraries
# Dont forget -nostdinc++ for c++ files
CLEANSLATE=-nostdinc -nostdlib

ISET=-I /usr/lib/gcc/x86_64-linux-gnu/8/include/ -I ../../linux-headers/include/ -I /usr/x86_64-linux-uclibc/usr/include/

# Pass the required set of system libraries/object files.
# crt1.o : _start
# crti.o : entry _init and _fini
# crtn.o : exit .init and .fini
# libc.a : __uClibc_main and remaining c runtime
LSET=-L ${LPATH} ${LPATH}crt1.o ${LPATH}crti.o ${LPATH}crtn.o -lc

testdns: testdns.c
	gcc -o testdns testdns.c -static ${CLEANSLATE} ${ISET} ${LSET}

clean:
	rm testdns || /bin/true

