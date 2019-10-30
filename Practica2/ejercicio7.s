.text
.global buscarCaracter #int buscarCaracter(char a, char* s, unsigned ls)
buscarCaracter:
  cld
  movq %rsi, %rax
bucle:
  scasq
  je encontrado
  loop bucle
  movq $0, %rax
  jmp fin:
encontrado:
  movq $1, %rax
fin:
  ret
