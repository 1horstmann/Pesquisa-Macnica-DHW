
CC=clant
CFLAGS=-g -Wall

BIN=ci.c

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lcurl

clean:
	$(RM) -rf $(BIN) *.dSYM
