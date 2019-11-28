.global sum_sse
sum_sse:
movq %rdx, %rcx
bucle:
movaps (%rdi), %xmm0
movaps (%rsi), %xmm1
addps %xmm1, %xmm0
movaps %xmm0, (%rdi)
addq $16, %rdi
addq $16, %rsi
subq $3, %rcx
# Disminuimos RCX en 3 porque con cada loop calculamos 4 elementos
# y loop solo decrementa 1
loop bucle
ret