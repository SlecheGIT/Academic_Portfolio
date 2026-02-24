
CC = gcc
CFLAGS = -o
FLAGS = -lm -Wall -Wextra -pedantic
 
SRC = substituicao_de_paginas.c
TARGET = substituicao_de_paginas.exe

run: compile #dependencias 
	./$(TARGET) 10 30 seq-20-paginas-10.txt

compile: 
	$(CC) $(CFLAGS) $(TARGET) $(SRC) $(FLAGS)

clean:
	rm -f $(TARGET)

.phony: run compile clean