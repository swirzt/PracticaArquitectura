.global sum_sse
sum_sse:
movq %rdx, %rax
xorq %rdx, %rdx
movq $4, %r9
div %r9
movq %rax, %rcx
bucle:
movaps (%rdi), %xmm0
movaps (%rsi), %xmm1
addps %xmm1, %xmm0
movaps %xmm0, (%rdi)
addq $16, %rdi
addq $16, %rsi
loop bucle
ret
