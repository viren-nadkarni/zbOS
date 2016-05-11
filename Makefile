all: zbos

run: zbos
	/usr/bin/qemu-system-x86_64 build/zbos.img

zbos: kernel.img boot.img
	mkdir -p build
	cat boot/boot.img kernel/kernel.img > build/zbos.img

kernel.img:
	cd kernel; make

boot.img:
	cd boot; make
