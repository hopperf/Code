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

/*
 mpiTiming - An example MPI program for timeing code.
 Copyright (C) 2011 Franz Hopper

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/