CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=

OBJ=main.o
P=client.out

$(P): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

.PHONY: clean
clean:
	rm $(OBJ) $(P)
