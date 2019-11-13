#include <setjmp.h>
#include <stdio.h>

int setjmp2(jmp_buf buffer);
void longjmp2(jmp_buf buffer, int val);

jmp_buf buffer;

int main() {
  int k = setjmp2(buffer);
  printf("%d\n", k);
  if (k == 0) longjmp2(buffer, 2);
  return 0;
}