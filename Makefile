PROJECT=evalite
TYPE=c

CC=gcc
CXX=g++
RM=rm -f
CFLAGS=-g -Wall -Wextra -Wshadow -pedantic -O3 -Wunreachable-code -Wmain #flags for C and C++
LDFLAGS=-g -s
LDLIBS= # insert here all libraries needed


SRCS=src/evalite.c
OBJS=$(subst .$(TYPE),.o,$(SRCS))

all : $(PROJECT)

$(PROJECT): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROJECT) $(OBJS) $(LDLIBS)
	
depend: .d

.d: $(SRCS)
	$(RM) ./.d
	$(CC) $(CFLAGS) -MM $^>>./.d;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .d

include .d
