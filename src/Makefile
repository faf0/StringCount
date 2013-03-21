CC = gcc
CPP = g++
CPPFLAGS += -I./ -Wall -Wsign-compare -Wchar-subscripts -Werror -pedantic
CFLAGS += -std=c99
#CXXFLAGS += -O2
LDFLAGS  += -L./

.PHONY: all, clean

PROGNAME := string_count

all:	string_count
string_count:	string_count.o shell.o

clean:
	rm *.o string_count

