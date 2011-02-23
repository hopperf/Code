#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
  int numprocs, rank, namelen;
  double start, end;
  char processor_name[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs); // size
  MPI_Comm_rank(MPI_COMM_WORLD, &rank); // node
  MPI_Get_processor_name(processor_name, &namelen);

  //printf("I am process %d on %s out of %d\n", rank, processor_name, numprocs);

  if(rank==0){
     printf("Hello from Master. Time = %lf \n", MPI_Wtime() - start);
     //Count number of ticks
  }
  else{
    //printf("hello from node #%d %lf \n", rank, (MPI_Wtime() - start));
  }
  MPI_Finalize();
}

