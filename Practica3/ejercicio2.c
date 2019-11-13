#include <math.h>
#include <stdio.h>
#define myisnan2(n) !(n == n)

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

int myisnan(float n) {
  if (obtenerExponente(n) == 255) {
    return obtenerFraccion(n) != 0;
  } else
    return 0;
}

int main(void) {
  float g = 0.0;
  float f = 0.0 / g;
  printf("f: %f\n", f);
  // ADVERTENCIA: ‘NAN’ es una extensión de GCC.
  if (f == NAN) printf("Es NAN\n");

  if (isnan(f)) printf("isNaN dice que sı́\n");
  printf("es nan? %d\n", myisnan2(INFINITY + 5));
  return 0;
}

//INFINITY no es NaN
//Sumar un número a INFINITY mantiene su estado de no NaN