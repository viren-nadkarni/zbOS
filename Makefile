export CCFLAGS = -fno-builtin -m32 -Wall -nostartfiles -nostdlib -nostdinc -std=gnu99 -g -c -O0
export ASFLAGS = -f elf32
export LDFLAGS = -melf_i386 -Ttext 0x1000 --oformat binary # -T linker.ld

.PHONY: all run debug qemu bochs clean libc zbos kernel bootloader

all: libc zbos

run: qemu

debug: bochs

qemu: all
	/usr/bin/qemu-system-i386 -drive file=build/zbos.img,format=raw

bochs: all
	/usr/bin/bochs

clean:
	find . -iname "*.img" -o -iname "*.bin" -o -iname "*.o" -o -iname "*.a" | xargs rm -v

libc:
	cd libc; make

zbos: kernel bootloader
	mkdir -p build
	dd if=/dev/zero of=build/zero.img bs=64K count=1
	cat boot/boot.img kernel/kernel.bin build/zero.img > build/zbos.img
	rm build/zero.img

kernel:
	cd kernel; make

bootloader:
	cd boot; make

