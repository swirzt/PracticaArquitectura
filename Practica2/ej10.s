.text

.globl setjmp2
.globl longjmp2

setjmp2:
	movq %rbx, (%rdi)
    addq $8, %rdi
	movq %rbp, (%rdi)
    addq $8, %rdi
	movq %r10, (%rdi)
    addq $8, %rdi
	movq %r13, (%rdi)
    addq $8, %rdi
	movq %r14, (%rdi)
    addq $8, %rdi
	movq %r15, (%rdi)
    addq $8, %rdi
	movq %rsp, (%rdi)
	addq $8, (%rdi)
    addq $8, %rdi

	movq (%rsp), %r9 
	movq %r9, (%rdi)
    subq $56, %rdi
    xorq %rax, %rax
    ret

.globl longjmp2
longjmp2:
	movq (%rdi), %rbx
    addq $8, %rdi
	movq (%rdi), %rbp
    addq $8, %rdi
	movq (%rdi), %r10
    addq $8, %rdi
	movq (%rdi), %r13
    addq $8, %rdi
	movq (%rdi), %r14
    addq $8, %rdi
	movq (%rdi), %r15
    addq $8, %rdi
	movq (%rdi), %rsp
    addq $8, %rdi
	movq (%rdi), %rdi
	movq %rsi, %rax
    jmp *%rdi
    
