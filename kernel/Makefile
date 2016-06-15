SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJ = ${SOURCES:.c=.o}

.PHONY: all

all: kernel.bin

entry.o: entry.asm
	nasm $(ASFLAGS) -o entry.o entry.asm

%.o: %.c ${HEADERS}
	gcc $(CCFLAGS) -o $@ $< -I$(KERNEL_INCDIR) -I$(LIBC_INCDIR)

kernel.bin: entry.o kernel.o ${OBJ}
	ld $(LDFLAGS) -o $@ $^ -L../build -lc
	cp $@ ../build

