# zbOS

[![Build Status](https://travis-ci.org/viren-nadkarni/zbOS.svg?branch=master)](https://travis-ci.org/viren-nadkarni/zbOS)

zbOS is a UNIX-clone being built from scratch.

![zbOS in QEMU](screenshot.png)

### What's been done:

- [x] A custom bootloader capable of switching to protected mode and bootstrapping a kernel
- [ ] a standard C library (libc) **WIP**
- [x] Interrupt handler
- [ ] Device drivers
  - [x] video (hardware cursor, scrolling, ASCII escapes)
  - [x] clock (PIT timer)
  - [x] keyboard
  - [ ] filesystem (SFS? ramdisk?)
- [ ] Memory management
  - [ ] paging **WIP**
  - [ ] heap
- [ ] Process scheduling (multitasking)
- [ ] the future (userland?)

### Getting started

    apt install build-essential nasm qemu       # on debian
    dnf install @development-tools nasm qemu    # on fedora

    make run                                    # build and run in qemu
    make debug                                  # run with bochs debugger

### Resources:

- [OSDev.org](http://wiki.osdev.org) :point_left: this is all you need
- [Nick Blundell's OpSys Lecture Notes](https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf)
- [www.brokenthorn.com/Resources/OSDevIndex.html](http://www.brokenthorn.com/Resources/OSDevIndex.html)
- [pages.cs.wisc.edu/~remzi/OSTEP](http://pages.cs.wisc.edu/~remzi/OSTEP/)
- [Bran's Kernel Development Tutorial](http://www.osdever.net/bkerndev/index.php)
- [JamesM's kernel development tutorial](http://www.jamesmolloy.co.uk/tutorial_html/)
- [linux-insides](https://github.com/0xAX/linux-insides)
- [Samy Pesse's How to make an OS](https://www.gitbook.com/book/samypesse/how-to-create-an-operating-system/details)

