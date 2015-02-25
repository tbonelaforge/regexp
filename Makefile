all: regexp_test.bin

regexp_test.bin: regexp_test.c regexp.h regexp.o
	gcc -I ./ regexp_test.c regexp.o -o regexp_test.bin

regexp.o: regexp.c regexp.h
	gcc -I ./ -c regexp.c -o regexp.o
