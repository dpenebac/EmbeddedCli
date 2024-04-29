CC = gcc
CFLAGS = -Wall -D uRunCustomRecieve -Iinclude 

SRCDIR = src
INCDIR = include
TESTDIR = test

SRC = $(SRCDIR)/uRun.c
INC = $(INCDIR)/uRun.h
TESTSRC = $(TESTDIR)/test.c

TARGET = myprogram

all: $(TARGET)

$(TARGET): $(SRC) $(INC) $(TESTSRC)
	$(CC) $(CFLAGS) $(INC) $(SRC) $(TESTSRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
