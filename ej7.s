.global sum
# float[] a float[] b int c -> void
sum:
movq %rdx, %rcx
bucle:
movss (%rdi), %xmm0
movss (%rsi), %xmm1
addss %xmm1, %xmm0
movss %xmm0, (%rdi)
addq $4, %rdi
addq $4, %rsi
loop bucle
ret
