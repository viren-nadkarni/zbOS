# zbOS

zbOS is a hobby operating system I have been building from scratch.

### What's been done:

- [x] A custom bootloader capable of switching to 32-bit protected mode and bootstrapping a kernel
- [ ] \(wip) A monolithic kernel
- [ ] \(wip) libc implementation
- [ ] Device drivers
  - [ ] \(wip) video
  - [ ] \(wip) keyboard
  - [ ] filesystem (SFS?)
- [ ] Memory management
- [ ] Process scheduling

### Getting started

    apt install build-essential nasm qemu       # on debian
    dnf install @development-tools nasm qemu    # on fedora

    make run                                    # build and run in qemu
    make debug                                  # run in the bochs debugger

### Resources:

- [OSDev.org](http://wiki.osdev.org) :point_left: this is all you need
- [linux-insides](https://github.com/0xAX/linux-insides) - for how linux works

