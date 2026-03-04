CC = gcc
CFLAGS = -g -Wall
TARGET  = college

OBJS = college.o dataset.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

college.o: college.c dataset.h
	$(CC) $(CFLAGS) -c college.c

dataset.o: dataset.c dataset.h
	$(CC) $(CFLAGS) -c dataset.c

clean:
	rm -f $(OBJS) $(TARGET)
