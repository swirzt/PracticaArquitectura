#include <stdio.h>
#include <time.h>

void sum(float* a, float* b, int c);
void sum_sse(float* a, float* b, int c);

#define k 1000
#define l 10000
#define m 1000000
#define n 100000000

float a[k], b[k];
float c[l], d[l];
float e[m], f[m];
float g[n], h[n];

int main() {
  clock_t t;
  // 1000
  t = clock();
  sum(a, b, k);
  t = clock() - t;
  printf("En un array de %d elementos tarda %f segundos con UNPACKED.\n", k,
         ((float)t) / CLOCKS_PER_SEC);
  t = clock();
  sum_sse(a, b, k);
  t = clock() - t;
  printf("En un array de %d elementos tarda %f segundos con PACKED.\n", k,
         ((float)t) / CLOCKS_PER_SEC);

  // 10000
  t = clock();
  sum(c, d, l);
  t = clock() - t;
  printf("En un array de %d elementos tarda %f segundos con UNPACKED.\n", l,
         ((float)t) / CLOCKS_PER_SEC);
  t = clock();
  sum_sse(c, d, l);
  t = clock() - t;
  printf("En un array de %d elementos tarda %f segundos con PACKED.\n", l,
         ((float)t) / CLOCKS_PER_SEC);

  // 1000000
  t = clock();
  sum(e, f, m);
  t = clock() - t;
  printf("En un array de %d elementos tarda %f segundos con UNPACKED.\n", m,
         ((float)t) / CLOCKS_PER_SEC);
  t = clock();
  sum_sse(e, f, m);
  t = clock() - t;
  printf("En un array de %d elementos tarda %f segundos con PACKED.\n", m,
         ((float)t) / CLOCKS_PER_SEC);

  // 100000000
  t = clock();
  sum(g, h, n);
  t = clock() - t;
  printf("En un array de %d elementos tarda %f segundos con UNPACKED.\n", n,
         ((float)t) / CLOCKS_PER_SEC);
  t = clock();
  sum_sse(g, h, n);
  t = clock() - t;
  printf("En un array de %d elementos tarda %f segundos con PACKED.\n", n,
         ((float)t) / CLOCKS_PER_SEC);

  return 0;
}
