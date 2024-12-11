CC = gcc
CFLAG = -std=c11 -O2 -Wall
TARGET = copy_file
SRCS = copy_file.c
OBJS = copy_file.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAG) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
