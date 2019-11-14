#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define FALSE 1
#define TRUE 0

int* primeNumb;

int isPrime(unsigned int x){
  if((x & 1) == 0)
    return x == 2;
    
  return primeNumb[x >> 1];
}

void fillPrimeNumbers(unsigned int max){
  const unsigned int half = max >> 1;

  primeNumb = (int*)calloc(half, sizeof(int));
  primeNumb[0] = FALSE;

  for(unsigned int i = 1; 2*i*i < half; i++)
    if(primeNumb[i] == TRUE)
    {
      unsigned int current = 3*i+1;
      while(current < half){
        primeNumb[current] = FALSE;
        current += 2*i+1;
      }
    }
}

int max(int *arr, int len){
  int max = arr[0];

  for(int i = 1; i<len; i++)
    if(arr[i] > max)
      max = arr[i];

  return max;
}

int main(int argc, char const *argv[]) {
  int N, count, *list;
  unsigned int maxPrime;
  unsigned int *primes;

  scanf("%d", &N);

  list = (int*)malloc(N*sizeof(int));

  for(int i = 0; i<N; i++)
    scanf("%d", &list[i]);

  maxPrime = max(list, N) / 2 +100;

  fillPrimeNumbers(maxPrime);

  if(primes = (unsigned int*)malloc(3002000*sizeof(unsigned int)))
  {
    int j = 1;
    primes[0] = 2;
    for(unsigned int i = 3; i < maxPrime; i += 2)
      if(isPrime(i) == TRUE)
      {
        primes[j] = i;
        j++;
      }

    for(int k = 0; k<N; k++)
    {
      count = 0;
      for(int i=0; primes[i]*primes[i] < list[k]; i++)
      	for(int j=i; primes[i]*primes[j] <  list[k]; j++)
      		count++;

      printf("%d\n", count);
    }
  }

  return 0;
}
