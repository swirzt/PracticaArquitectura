    .data 
format: .asciz "%ld\n"
format2: .asciz "%x\n"
i: .quad 0xDEADBEEF
    .text
    .global main

main:
    movq $format, %rdi
    movq $1234, %rsi
    xorq %rax, %rax
    call printf
    
    movq $format2, %rdi
    movq %rsp, %rsi
    xorq %rax, %rax
    call printf
    
    movq $format, %rdi
    movq format, %rsi
    xorq %rax, %rax
    call printf

    movq $format2, %rdi
    movq format, %rsi
    xorq %rax, %rax
    call printf    

    movq $format, %rdi
    movq (%rsp), %rsi
    xorq %rax, %rax
    call printf

    movq $format, %rdi
    movq 8(%rsp), %rsi
    xorq %rax, %rax
    call printf 

    movq $format2, %rdi
    movq i, %rsi
    xorq %rax, %rax
    call printf

    movq $format, %rdi
    movq $i, %rsi
    xorq %rax, %rax
    call printf

    ret
