CC ?= gcc
GASH_PREFIX ?= /usr/local
OBJS = src/interpreter.c src/builtins.c

all: bin/gash
bin/gash: $(OBJS)
	$(CC) -o $@ $^ -lreadline
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
install:
	cp bin/gash $(GASH_PREFIX)/bin
uninstall:
	rm $(GASH_PREFIX)/bin/gash
clean:
	rm -rf *.o bin/gash $(GASH_PREFIX)/bin/gash
.PHONY: install uninstall clean all
