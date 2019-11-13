.data
.text
.global findChar

findChar: #Cadena rdi, Caracter rsi, Largo rdx
    cld
    movq %rdx, %rcx
    movq %rsi, %rax
    movq $0, %r8
    bucle:
    incq %r8
    scasb
    je encontrado
    loop bucle
    movq $-1, %rax
    jmp  fin
    encontrado:
    subq $1, %r8
    movq %r8, %rax
    fin: 
    # subq %r8, %rdi # no sabemos si incrementa el original
    ret

.global compareString

compareString: #Cadena rdi, Cadena rsi, Largo rdx
    cld
    movq %rdx, %rcx
    movq $0, %r8
    bucle2:
    incq %r8
    cmpsb
    jg mayor
    jl menor
    loop bucle2
    iguales:
        movq $0, %rax
        jmp fin2
    mayor:
        movq $1, %rax
        jmp fin2
    menor:
        movq $-1, %rax
    fin2:
        ret

.global fuerzaBruta

fuerzaBruta: #Cadena rdi, Cadena rsi, Largo1 rdx Largo2 rcx
    pila:
    pushq $0
    programa:
    pushq %rcx 
    pushq %rdx 
    pushq %rdi 
    pushq %rsi 
    movb (%rsi), %sil
    call findChar
    cmpq $-1, %rax
    je nochar
    movq (%rsp), %rsi
    movq 8(%rsp), %rdi
    movq 24(%rsp), %rdx
    movq 16(%rsp), %r9
    subq %rdx, %r9
    incq %r9
    cmpq %rax, %r9
    jle noloop
    addq %rax, 32(%rsp) # incrementa el 0 original 
    addq %rax, %rdi
    movq %rax, %r10
    call compareString
    cmpq $0, %rax
    je encontro
    noencontro:
    movq %r10, %rax
    incq 32(%rsp)
    incq %rax
    popq %rsi
    popq %rdi
    addq %rax, %rdi
    popq %rdx
    subq %rax, %rdx
    popq %rcx
    jmp programa
    
    encontro:
    popq %r9
    popq %r9
    popq %r9
    popq %r9
    popq %rax
    ret


    noloop:
    popq %r9
    popq %r9
    popq %r9
    popq %r9
    popq %r9
    movq $-1, %rax
    ret

    nochar:
    popq %r9
    popq %r9
    popq %r9
    popq %r9
    popq %r9
    ret

    

    