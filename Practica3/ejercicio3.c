#include <math.h>
#include <stdio.h>

long long DOFraccion(double n) {
  long long mascara = pow(2, 52) - 1;
  double* punteron = &n;
  long long* numero = (long long*)punteron;
  long long fraccion = *numero & mascara;
  return fraccion;
}

int DOExponente(double n) {
  int mascara = 2047 << 52;
  double* punteron = &n;
  int* numero = (int*)punteron;
  int exponente = *numero & mascara;
  exponente = exponente >> 52;
  return exponente;
}

int obtenerFraccion(float n) {
  int mascara = 0x7fffff;
  float* punteron = &n;
  int* numero = (int*)punteron;
  int fraccion = *numero & mascara;
  return fraccion;
}

int obtenerExponente(float n) {
  int mascara = 255 << 23;
  float* punteron = &n;
  int* numero = (int*)punteron;
  int exponente = *numero & mascara;
  exponente = exponente >> 23;
  return exponente;
}

int main() {
  float fAvogadro = 6.02252 * pow(10, 23);
  double dAvogadro = 6.02252 * pow(10, 23);

  printf("Exponente: %d Fraccion: %d \n", obtenerExponente(fAvogadro),
         obtenerFraccion(fAvogadro));
}