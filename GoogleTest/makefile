.PHONY: clean

all: main.o haizei/test.o
	gcc -o ./bin/haizei main.o haizei/test.o

main.o: main.c
	gcc -I./ -c main.c

haizei/test.o: haizei/test.h haizei/test.c
	gcc -I./ -o haizei/test.o -c haizei/test.c

run: all
	./bin/haizei

clean:
	rm -rf ./a.out *.o ./haizei/test.o ./bin/haizei
