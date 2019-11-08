.global main
main:
    movl $1, %eax
    sall $63, %eax

    movl $1, %ebx
    sall $15, %ebx
    orl %ebx, %eax

    movl $-1, %eax
    movl $-1, %ebx
    sall $8, %ebx
    andl %ebx, %eax

    movl $0xAA, %eax
    movl $0xAA, %ebx
    sall $24, %ebx
    orl %ebx, %eax

    movl $5, %eax
    sall $8, %eax

    movl $-1, %eax
    movl $1, %ebx
    sall $8, %ebx
    notl %ebx
    andl %ebx, %eax

    ret

#No podemos revisar este ejercicio sin el GDB, pues los valores de retorno se
#almacenan en %al y este solamente almacena 8 bits. Como la mayoría de los valores
#superan los 8 bits en tamaño, debemos usar el GDB para reconocer dichos números
