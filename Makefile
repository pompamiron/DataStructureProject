# Makefile for demo programs for Lecture 8
# Networks
# We also need a queue and a min priority queue for this lecture

ifeq ($(OSTYPE),WINDOWS)
	EXECEXT =.exe
	COMP	=__MINGCC__
	PLATFORM	=mingw
else
	EXECEXT =
	COMP	=__GCC__
	PLATFORM	=linux
endif

EXECUTABLES= main$(EXECEXT)

all : $(EXECUTABLES)

movieNetworkBuilder.o : movieNetworkBuilder.c movieNetworkBuilder.h
	gcc -c movieNetworkBuilder.c

movieNetwork.o : movieNetwork.c movieNetwork.h
	gcc -c movieNetwork.c

main.o : main.c movieNetwork.h movieNetworkBuilder.h
	gcc -c main.c

main$(EXECEXT) : main.o movieNetwork.o movieNetworkBuilder.o 
	gcc -o main$(EXECEXT) main.o movieNetwork.o movieNetworkBuilder.o

clean : 
	-rm *.o
	-rm $(EXECUTABLES) 
