SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJ = ${SOURCES:.c=.o}

all: kernel.img

%.o: %.c ${HEADERS}
	gcc -std=c99 -ffreestanding -c $< -o $@

kernel.img: kernel.o ${OBJ}
	ld -Ttext 0x1000 --oformat binary -o $@ $^
