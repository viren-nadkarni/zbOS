all: kernel.img

kernel.o: kernel.c
	gcc -ffreestanding -c -o kernel.o kernel.c

kernel.img: kernel.o
	ld -Ttext 0x1000 --oformat binary -o kernel.img kernel.o
