#include <math.h>
#include <stdio.h>

typedef struct {
  int signo : 1;
  int exponente : 16;
  int mantisa : 18;
} numero;

// int isNaN(numero k) { return k.exponente == 0xffff && k.mantisa != 0; }

int noValido(numero k) { return k.exponente == 0xffff; }

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
  }
  else{
    if(a.exponente > b.exponente){
        
    }
    return;
  }
}

int main() { return 0; }