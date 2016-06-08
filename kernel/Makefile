SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJ = ${SOURCES:.c=.o}

all: kernel.bin

entry.o: entry.asm
	nasm $(ASFLAGS) -o entry.o entry.asm

%.o: %.c ${HEADERS}
	gcc $(CCFLAGS) -o $@ $< -I../libc

kernel.bin: entry.o kernel.o ${OBJ}
	ld $(LDFLAGS) -o $@ $^ -L../libc -lc
