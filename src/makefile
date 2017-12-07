CC=gcc

FORK : Producer.o Consumer.o Main.o
	gcc -o FORK Producer.o Consumer.o Main.o

Producer.o : Producer.c
	gcc -c -O3 -Wall Producer.c

Consumer.o : Consumer.c
	gcc -c -O3 -Wall Consumer.c

Main.o : Main.c
	gcc -c -O3 -Wall Main.c
