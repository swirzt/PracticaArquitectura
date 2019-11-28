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
numero suma(numero a, numero b) {
  if (noValido(a) || noValido(b)) {
    printf("No se puede calcular la suma");
    return Nan();
  } else {
    if (a.exponente >
        b.exponente) {  // Subo el exponente de b y hago operaciones
      int corrimiento = a.exponente - b.exponente;
      b.mantisa = b.mantisa >> 1;
      int mascara = 0x20000;
      b.mantisa = b.mantisa | mascara;
      corrimiento--;
      b.mantisa = b.mantisa >> corrimiento;
      int mantisa = a.mantisa + b.mantisa;
      // TODO: chequear lo del signo
      if (a.signo == b.signo) {
        numero num = nuevo(a.signo, a.exponente, mantisa);
      }
    } else {
      if (a.exponente < b.exponente) {
        int corrimiento = b.exponente - a.exponente;
        a.mantisa = a.mantisa >> 1;
        int mascara = 0x20000;
        a.mantisa = a.mantisa | mascara;
        corrimiento--;
        a.mantisa = a.mantisa >> corrimiento;
        int mantisa = a.mantisa + b.mantisa;
        // TODO: chequear lo del signo
        if (a.signo == b.signo) {
          numero num = nuevo(b.signo, b.exponente, mantisa);
        }
      } else {
        // Exponentes iguales
        int mantisa = a.mantisa + b.mantisa;
        mantisa = mantisa >> 1;
        // TODO: chequear lo del signo
        if (a.signo == b.signo) {
          numero num = nuevo(b.signo, b.exponente, mantisa);
        }
      }
      return;
    }
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

int main() { return 0; }
