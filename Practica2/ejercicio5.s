.text
.global fact1
fact1:
  movq $1, %rax

fact1e:
    cmpq $1, %rdi
    jle salida
    mulq %rdi
    decq %rdi
    jmp fact1e

salida:
  ret
