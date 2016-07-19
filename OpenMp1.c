#include<omp.h>
#include<stdio.h>

//Main Program:
int main()
{
  #pragma omp parallel
  {
  int ID = 0;
  printf("hello(%d)\n", ID);
  printf("World(%d)\n", ID);
  }

}
