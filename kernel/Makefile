SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJ = ${SOURCES:.c=.o}

all: kernel.bin

entry.o: entry.asm
	$(AS) $(ASFLAGS) -o entry.o entry.asm

%.o: %.c ${HEADERS}
	$(CC) $(CCFLAGS) -o $@ $< 

kernel.bin: entry.o kernel.o ${OBJ}
	$(LD) $(LDFLAGS) -o $@ $^
