
BPATH=/usr/x86_64-linux-uclibc/usr
LPATH=${BPATH}/lib/

# Ensure gcc doesnt include the default set of paths and files wrt includes and libraries
# Dont forget -nostdinc++ for c++ files
CLEANSLATE=-nostdinc -nostdlib

ISET1=-I /usr/lib/gcc/x86_64-linux-gnu/8/include/
ISET2=-I /usr/x86_64-linux-uclibc/usr/include/
ISET3=-I ../../linux-headers/include/
ISET4=-I ../../linux-headers/include/linux
ISET=${ISET1} ${ISET2} ${ISET3} ${ISET4}

# Pass the required set of system libraries/object files.
# crt1.o : _start
# crti.o : entry _init and _fini
# crtn.o : exit .init and .fini
# libc.a : __uClibc_main and remaining c runtime
LSET=-L ${LPATH} ${LPATH}crt1.o ${LPATH}crti.o ${LPATH}crtn.o -lc

all: testdns

#
# Additional steps
# In /usr/x86_64-linux-uclibc/usr/include/limits.h replace # include_next <limits.h> by # include <linux/limits.h>
#

patch:
	/bin/echo -e '1,$$s/include_next <limits/include <linux\/limits/g\nw\nq' | sudo ed ${BPATH}/include/limits.h

testdns: testdns.c
	gcc -o testdns testdns.c -static ${CLEANSLATE} ${ISET} ${LSET}

clean:
	rm testdns || /bin/true

test: testdns
	./testdns -1 google.com microsoft.com yahoo.com facebook.com intel.com ti.com analog.com archive.org ubuntu.com ibm.com kernel.org redhat.com amd.com google.com microsoft.com yahoo.com facebook.com intel.com ti.com analog.com archive.org ubuntu.com ibm.com kernel.org redhat.com amd.com google.com microsoft.com yahoo.com facebook.com intel.com ti.com analog.com archive.org ubuntu.com ibm.com kernel.org redhat.com amd.com google.com microsoft.com yahoo.com facebook.com intel.com ti.com analog.com archive.org ubuntu.com ibm.com kernel.org redhat.com amd.com google.com microsoft.com yahoo.com facebook.com intel.com ti.com analog.com archive.org ubuntu.com ibm.com kernel.org redhat.com amd.com google.com microsoft.com yahoo.com facebook.com intel.com ti.com analog.com archive.org ubuntu.com ibm.com kernel.org redhat.com amd.com google.com microsoft.com yahoo.com facebook.com intel.com ti.com analog.com archive.org ubuntu.com ibm.com kernel.org redhat.com amd.com

tcpdump:
	sudo tcpdump udp

