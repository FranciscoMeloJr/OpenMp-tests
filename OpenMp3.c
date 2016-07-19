#include<omp.h>

/*Fork Join Parallelism
  Team of threads
  when they finish the work, they join back together
  Series of sequences and parallel regions
  Nesting them

  You create threads in OpenMP with the parallel constructs
*/

int main()
{
  double A[1000];
  //set the number of threads:
  omp_set_num_threads(4);
 
  #pragma omp parallel
  {
    //This is private to each thread
    int ID = omp_get_thread_num();
    pooh(ID,A); //each thread will call the function with a different ID
  }
  printf("All done\n");
}
  


