.data
.text
.global compareString

compareString: #Cadena rdi, Cadena rsi, Largo rdx
    cld
    movq %rdx, %rcx
    repe cmpsb
    je iguales
    jg mayor
    jl menor
    iguales:
        movq $0, %rax
        jmp fin
    mayor:
        movq $1, %rax
        jmp fin
    menor:
        movq $-1, %rax
    fin:
        ret
        