CC=gcc
CPP=g++
CFLAGS= -march=native 
LIB= -O3 
SOURCES_C= Ficheros-abrir.c
SOURCES_CPP= Ficheros-abrir.cpp
# SOURCES= Ficheros-leer.c
all: 
	$(CC) -o test_c $(SOURCES_C) $(LIB) $(CFLAGS) 
	$(CPP) -o test_cpp $(SOURCES_CPP) $(LIB) $(CFLAGS) 
clean: 
	rm *.o  