mp2: mp2final.o mp2head.o mp2final.c
	cc  -std=c99  mp2final.o mp2head.o -o mp2

mp2final.o: mp2final.c mp2head.h mp2final.c
	cc -c -std=c99 mp2final.c 

mp2head.o: mp2head.c 
	cc -c -std=c99 mp2head.c 
