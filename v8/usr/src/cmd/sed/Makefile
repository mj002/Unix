CFLAGS=-O
sed:	sed0.o sed1.o; cc -o sed -n *.o
install: sed
	strip sed
	cp sed /usr/bin
clean:
	rm -f sed *.o

sed0.o: sed0.c sed.h
sed1.o: sed1.c sed.h
