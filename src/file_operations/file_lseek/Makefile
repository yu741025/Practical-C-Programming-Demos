CC = gcc
CFLAG = -std=c11 -O2 -Wall
TARGET = file_lseek
SRCS = file_lseek.c
OBJS = file_lseek.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAG) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
