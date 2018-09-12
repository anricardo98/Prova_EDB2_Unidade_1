#Makefile for "lista_encadeada" C++ application
#Created by Andre 12/09/2018

PROG = lista_encadeada
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o lista_encadeada.o 

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o:
	 $(CC) $(CPPFLAGS) -c main.cpp

lista_encadeada.o: lista_encadeada.hpp
	$(CC) $(CPPFLAGS) -c lista_encadeada.cpp

clean:
	rm -f *.o