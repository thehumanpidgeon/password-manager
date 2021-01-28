CC=gcc
CFLAGS=-I.
DEPS= quiz.h
OBJ= passwordManager.o serviceChoice.o findFile.o encrypt.o decrypt.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

manager.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

._PHONY: clean

clean:
	rm -fv *.o
