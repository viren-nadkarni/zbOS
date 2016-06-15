export CCFLAGS = -fno-builtin -m32 -Wall -nostartfiles -nostdlib -nostdinc -std=gnu99 -g -c -O0
export ASFLAGS = -f elf32
export LDFLAGS = -melf_i386 -Ttext 0x1000 --oformat binary # -T linker.ld

export KERNEL_INCDIR = $(shell pwd)/kernel/include
export LIBC_INCDIR = $(shell pwd)/libc/include

.PHONY: all run debug qemu bochs clean libc zbos kernel bootloader prereq

all: libc zbos

run: qemu

debug: bochs

qemu: all
	/usr/bin/qemu-system-i386 -drive file=build/zbos.img,format=raw

bochs: all
	/usr/bin/bochs

clean:
	find . -iname "*.img" -o -iname "*.bin" -o -iname "*.o" -o -iname "*.a" | xargs rm -v

prereq:
	mkdir -p build

libc: prereq
	cd libc; make

zbos: kernel bootloader prereq
	dd if=/dev/zero of=build/zero.img bs=64K count=1
	cat build/boot.img build/kernel.bin build/zero.img > build/zbos.img

kernel: prereq
	cd kernel; make

bootloader: prereq
	cd boot; make

