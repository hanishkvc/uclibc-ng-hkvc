
LPATH="/usr/x86_64-linux-uclibc/usr/lib/"

test: test.c
	gcc test.c -static -nostdinc -nostdlib -I /usr/lib/gcc/x86_64-linux-gnu/8/include/ -I ../../linux-headers/include/ -I /usr/x86_64-linux-uclibc/usr/include/ -L /usr/x86_64-linux-uclibc/usr/lib/ ${LPATH}crt1.o ${LPATH}crti.o ${LPATH}crtn.o -lc
	
#gcc test.c -nostdinc -nostdinc++ -nostdlib -I /usr/lib/gcc/x86_64-linux-gnu/8/include/ -I /usr/x86_64-linux-uclibc/usr/include/ -I ../../linux-headers/include/linux/
#gcc test.c -static -nostdinc -nostdlib -I /usr/lib/gcc/x86_64-linux-gnu/8/include/ -I /usr/x86_64-linux-uclibc/usr/include/ -I ../../linux-headers/include/linux/ -L /usr/x86_64-linux-uclibc/usr/lib/ ${LPATH}crt1.o ${LPATH}crti.o ${LPATH}crtn.o ${LPATH}libc.a
#gcc test.c -static -nostdinc -nostdlib -I /usr/lib/gcc/x86_64-linux-gnu/8/include/ -I /usr/x86_64-linux-uclibc/usr/include/ -I ../../linux-headers/include/linux/ -L /usr/x86_64-linux-uclibc/usr/lib/ ${LPATH}crt1.o ${LPATH}crti.o ${LPATH}crtn.o ${LPATH}libc.a
