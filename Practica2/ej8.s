.data
.text
.global findChar

findChar: #Cadena rdi, Caracter rsi, Largo rdx
    cld
    movq %rdx, %rcx
    movq %rsi, %rax
    repne scasb
    je encontrado
    movq $0, %rax
    jmp  fin
    encontrado:
    movq $1, %rax
    fin: 
    ret
