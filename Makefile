all: zbos

run: zbos
	/usr/bin/qemu-system-x86_64 build/zbos.img

clean:
	find . -iname "*.img" -o -iname "*.bin" -o -iname "*.o" | xargs rm -v

zbos: kernel.img boot.img
	mkdir -p build
	dd if=/dev/zero of=build/zero.img bs=64K count=1
	cat boot/boot.img kernel/kernel.img build/zero.img > build/zbos.img

kernel.img:
	cd kernel; make

boot.img:
	cd boot; make
