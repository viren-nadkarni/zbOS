[bits 32]
[extern main]
    call main
    jmp $               ; this should happen when returning from kernel main
                        ; shutdown?
