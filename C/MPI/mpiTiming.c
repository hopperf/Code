/*******************************************************************************
 * FILE: mpiTiming.c
 * 
 * AUTHOR: Franz Hopper
 * DATE: 2/21/2011
 * DESCRIPTION: An example MPI program for timeing code.
 ******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <mpi.h>

int main(int argc, char *argv[]){
  int numprocs, rank, namelen;
  double start_time, end_time, processing_time;
  char processor_name[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs); // Total number of processes
  MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Which process am I?
  MPI_Get_processor_name(processor_name, &namelen); // Hostname of processor

  //printf("I am process %d on %s out of %d\n", rank, processor_name, numprocs);
  start_time = MPI_Wtime();
  
  if(rank==0){
     end_time = MPI_Wtime();
     processing_time = end_time - start_time;
     printf("TIME MASTER: %lf \n", processing_time);
  }
  else{
    int i;
    for (i = 0; i < 1000; i++){
      sleep(.1);
    }
     end_time = MPI_Wtime();
     processing_time = end_time - start_time;
     printf("TIME NODE: %lf \n", processing_time);
  }
  
  MPI_Finalize();
  return 0;
}

/*******************************************************************************
 * mpiTiming - An example MPI program for timeing code.
 * Copyright (C) 2011 Franz Hopper
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/