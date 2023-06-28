#  Object Files
OBJS = tokenizer.o history.o uimain.o

#  Complier flags. -g for debug, -03 for optimization
CFLAGS=-g -O3

#include file dependencies
tokenizer.h: tokenizer.o uimain.o
history.h: history.o uimain.o

# user input
tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

all: tokenizer

clean:
	rm -f *.o *.c~ *.h~ *.c# *.h# src

run: tokenizer
	./tokenizer
