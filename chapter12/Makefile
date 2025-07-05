CC = cc
CFLAGS = -O1 -Wall -no-pie -I ../include
LDFLAGS = -lpthread
OBJS = ../src/csapp.o
TARGET = hello_n_thread

all: $(TARGET)

../src/csapp.o: ../src/csapp.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): hello_n_thread.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o ../src/*.o
