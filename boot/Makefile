SOURCES = $(wildcard *.asm)

.PHONY: all

all: boot.img

boot.img: ${SOURCES}
	nasm -f bin -o $@ main.asm

