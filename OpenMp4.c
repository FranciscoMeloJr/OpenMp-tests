#include <omp.h>
#include <stdio.h>

/*
  SPMD strategy:
   request the number of threads

  */
static long num_steps = 100;

double step;

#define NUM_THREADS 2

// Simples program to write and test:
int main()
{
  
  int  i, nthreads;
  double pi, sum[NUM_THREADS];
  step = 1.0/(double)num_steps;
  
  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel 
  {
    int i, id, nthrds;
    double x;
    id = omp_get_thread_num(); 
    nthreads = omp_get_num_threads();
    if (id == 0 )
    { 
       nthreads = nthrds;
    }

    for(i = id, sum[id]= 0.0; i < num_steps; i=i+nthrds)
    {
     x = (i+ 0.5)*step;
     sum[id] += 4.0/(1.0+x*x);
    }
  
  }
  
  for(i = 0, pi= 0.0; i<nthreads;i++)
     pi+= step*sum[i];

  printf("%lf", pi);

  return 0;
}
