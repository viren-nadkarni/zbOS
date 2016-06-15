SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJ = ${SOURCES:.c=.o}

.PHONY: all clean

all: libc.a

clean:
	rm $(OBJ) libc.a

libc.a: $(OBJ)
	ar rcs $@ $(OBJ)
	cp $@ ../build

%.o: %.c ${HEADERS}
	gcc $(CCFLAGS) -o $@ $< -I$(KERNEL_INCDIR) -I$(LIBC_INCDIR)

