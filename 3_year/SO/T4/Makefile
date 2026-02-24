
PORT = 8080
HOST = localhost

CC = gcc
CFLAGS = -o
FLAGS = -lm -lpthread -lrt

SRC = semaforos.c
TARGET = semaforos.exe

run: compile #dependencias 
	./semaforos.exe

compile: 
	$(CC) $(CFLAGS) $(TARGET) $(SRC) $(FLAGS)

clean:
	rm -f $(TARGET)

.phony: run compile clean