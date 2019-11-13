.text
.global fact2

fact2:
  movq $1, %rax
  movq %rdi, %rcx
  cmpq $1, %rcx
  jle salida
  bucle:
  mulq %rcx
  loop bucle

salida:
  ret
