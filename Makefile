export CC = gcc
export AS = nasm
export LD = ld

export CCFLAGS = -fno-builtin -m32 -Wall -nostartfiles -nostdlib -nostdinc -std=gnu99 -g -c -O0
export ASFLAGS = -f elf32
export LDFLAGS = -melf_i386 -Ttext 0x1000 --oformat binary


all: zbos.img

run: qemu

debug: bochs

qemu: zbos.img
	/usr/bin/qemu-system-i386 -drive file=build/zbos.img,format=raw

bochs: zbos.img
	/usr/bin/bochs

clean:
	find . -iname "*.img" -o -iname "*.bin" -o -iname "*.o" | xargs rm -v

zbos.img: kernel.bin boot.img
	mkdir -p build
	dd if=/dev/zero of=build/zero.img bs=64K count=1
	cat boot/boot.img kernel/kernel.bin build/zero.img > build/zbos.img

kernel.bin:
	cd kernel; make

boot.img:
	cd boot; make
