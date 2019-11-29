#include <math.h>
#include <stdio.h>

typedef struct {
  int signo : 1;
  int exponente : 16;
  int mantisa : 18;
} numero;

// int isNaN(numero k) { return k.exponente == 0xffff && k.mantisa != 0; }

int noValido(numero k) { return k.exponente == 0xffff; }

numero nuevo(int signo, int exponente, int mantisa) {
  numero num;
  num.signo = signo;
  num.exponente = exponente;
  num.mantisa = mantisa;
  return num;
}

numero zero() {
  numero cero;
  cero.signo = 0;
  cero.exponente = 0;
  cero.mantisa = 0;
  return cero;
}
numero Nan() {
  numero cero;
  cero.signo = 0;
  cero.exponente = 0xffff;
  cero.mantisa = 1;
  return cero;
}

//TODO: TESTEAR SI PONE BIEN EL SIGNO
numero suma(numero a, numero b) {
  if (noValido(a) || noValido(b)) {
    printf("No se puede calcular la suma");
    return Nan();
  } else {
    numero num;
    if (a.exponente > b.exponente) {  // Subo el exponente de b y hago operaciones
      int corrimiento = a.exponente - b.exponente;
      b.mantisa = b.mantisa >> 1;
      int mascara = 0x20000;
      b.mantisa = b.mantisa | mascara;
      corrimiento--;
      b.mantisa = b.mantisa >> corrimiento;
      int mantisa = a.mantisa + b.mantisa;

      num = nuevo(a.signo, a.exponente, mantisa);
    } else if (a.exponente < b.exponente) {
      int corrimiento = b.exponente - a.exponente;
      a.mantisa = a.mantisa >> 1;
      int mascara = 0x20000;
      a.mantisa = a.mantisa | mascara;
      corrimiento--;
      a.mantisa = a.mantisa >> corrimiento;
      int mantisa = a.mantisa + b.mantisa;

      num = nuevo(b.signo, b.exponente, mantisa);
    } else {
      // Exponentes iguales
      int mantisa = a.mantisa + b.mantisa;
      mantisa = mantisa >> 1;

      if (a.mantisa > b.mantisa) {
        num = nuevo(a.signo, b.exponente, mantisa);
      } else
        num = nuevo(b.signo, b.exponente, mantisa);
    }
    return num;
  }
}

numero producto(numero a, numero b) {
  if (noValido(a) || noValido(b)) {
    printf("No se puede calcular el produto");
    return Nan();
  } else {
    int exponente = a.exponente + b.exponente;
  }
}

int main() {
  numero num1, num2;
  num1.signo = 0;
  num1.exponente = 48;
  num1.mantisa = 5 << 15;  // numero dado
  num2.signo = 0;
  num2.exponente = 48;
  num2.mantisa = 3 << 16;  // 1.75
  numero resultado = suma(num1, num2);
  printf("%d%d%d\n", resultado.signo, resultado.exponente, resultado.mantisa);
  return 0;
}
