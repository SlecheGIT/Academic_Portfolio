
PORT = 8080
HOST = localhost

CC = gcc
CFLAGS = -o
FLAGS = -lm -lpthread -lrt -Wall -Wextra -pedantic
 
SRC = semaforos_bin.c
TARGET = semaforos_bin.exe

run: compile #dependencias 
	./semaforos_bin.exe

compile: 
	$(CC) $(CFLAGS) $(TARGET) $(SRC) $(FLAGS)

clean:
	rm -f $(TARGET)

.phony: run compile clean