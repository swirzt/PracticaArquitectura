.text
.global solEcuacion #float a float b float c float d float e float f float* x float* y -> int
  solEcuacion:
    movss %xmm0, %xmm6 #j=a
    movss %xmm1, %xmm7 #k=b
    mulss %xmm4,%xmm0 #a=ea
    movss %xmm0, %xmm8 # ea
    mulss %xmm3,%xmm1 #b=bd
    subb %xmm1,%xmm0 #a = det = b-a
    je finMalo
    mulss %xmm6, %xmm5 # f = af
    mulss %xmm2, %xmm3 # d = cd
    subss %xmm3, %xmm5 # f = af-dc
    divss %xmm0, %xmm5 # y = %xmm5
    mulss %xmm5, %xmm7 #b = yb
    subss %xmm7, %xmm2 # c = c-yb
    divss %xmm6, %xmm7 #x = %xmm7
    movss %xmm5, (%rsi)
    movss %xmm7, (%rdi)
    movq  $0, %rax
    ret
  finMalo:
    movq  $-1, %rax
    ret
