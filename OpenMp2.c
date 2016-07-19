#include<omp.h>
#include<stdio.h>

/*
  Symmetric Process Machine - SMP
    No space blocks in memory
  
  NUMA
    So addresses are closer to the process

  There is a cache hierarch on that.
  
*/
//Main Program:
int main()
{
  
  #pragma omp parallel
  {
  int ID = omp_get_thread_num();
  printf("hello(%d)\n", ID);
  printf("World(%d)\n", ID);
  }

}
