SOURCES = $(wildcard *.asm)

all: boot.img

boot.img: ${SOURCES}
	nasm -f bin -o boot.img main.asm
