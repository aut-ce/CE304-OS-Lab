CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=-pthread

OBJ=slice.o main.o
P=server.out

$(P): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

.PHONY: clean
clean:
	rm $(OBJ) $(P)
