[bits 32]
[extern kmain]
    call kmain
    jmp $               ; this should happen when returning from kernel main
                        ; shutdown?
