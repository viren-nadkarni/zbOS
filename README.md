# zbOS

zbOS is a hobby operating system I have been building from scratch.

### What's been done:

- [x] A custom bootloader capable of switching to 32-bit protected mode and bootstrapping a kernel
- [x] A basic kernel
- [ ] libc implementation
- [ ] Device drivers
  - [ ] video
  - [ ] keyboard
  - [ ] filesystem
- [ ] Memory management
- [ ] Process management

### Getting started

    apt install build-essential nasm qemu       # on debian
    dnf install @development-tools nasm qemu    # on fedora

    make run                                    # build and run in qemu

### Resources:

- [OSDev.org](http://wiki.osdev.org) :point_left: this is all you need
- [linux-insides](https://github.com/0xAX/linux-insides) how linux works

