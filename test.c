#include <stdio.h>
#include <time.h>
void sum(float* a, float* b, int c);
void sum_sse(float* a, float* b, int c);

#define k 100000000

int main(){
  clock_t t;
  float a[k], b[k];
  for(int i = 0; i<k; i++) a[i] = b[i] = 1.0;
  t = clock();
  sum_sse(a,b,k);
  t = clock() - t;
  printf ("PACKED %d (%f seconds).\n",(int)t,((float)t)/CLOCKS_PER_SEC);

  for(int i = 0; i<k; i++) a[i] = b[i] = 1.0;
  t = clock();
  sum(a,b,k);
  t = clock() - t;
  printf ("NO PACKED %d (%f seconds).\n",(int)t,((float)t)/CLOCKS_PER_SEC);

}
