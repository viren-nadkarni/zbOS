SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJ = ${SOURCES:.c=.o}

all: kernel.img

entry.o: entry.asm
	nasm -f elf64 -o entry.o entry.asm

%.o: %.c ${HEADERS}
	gcc -std=c99 -ffreestanding -c $< -o $@

kernel.img: entry.o kernel.o ${OBJ}
	ld -Ttext 0x1000 --oformat binary -o $@ $^
