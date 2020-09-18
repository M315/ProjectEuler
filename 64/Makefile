src = $(wildcard *.c)
obj = $(src:.c=.o)

CFLAGS = -lm -lgmp

a.out: $(obj)
	gcc -o $@ $^ $(CFLAGS)

$(obj): $(src)
	gcc -c -ansi -Wall $^ -lm

.PHONY: clean

clean:
	rm -f $(obj) a.out
