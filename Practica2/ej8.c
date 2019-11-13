#include <stdio.h>

int findChar(char palabra[], char c, long hola);
int compareString(char palabra[], char palabra2[], long n);
int fuerzaBruta(char palabra1[], char palabra2[], long n1, long n2);

int main() {
  char palabra1[100] = "oraciondeejemplobuscolapalabraejemplo";
  char palabra2[100] = "ejemplo";
  int k = fuerzaBruta(palabra1, palabra2, 37, 7);
  printf("%s %d\n", pedro, k);
  return 0;
}