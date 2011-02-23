/*******************************************************************************
 * FILE: mPI.c
 * VERSION: 0.1
 *
 * DESCRIPTION: An example MPI program that calculates PI and times how 
 * long the total procedure takes.
 *
 * OPTIONS: ---
 * REQUIREMENTS: MPI
 *
 * AUTHOR: Franz Hopper
 * EMAIL:  hopperf@lavabit.com
 * DATE:   2/21/2011  
 ******************************************************************************/
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
  int numProcs, rank;
  double startTime, end_time, processing_time;

  MPI_Init(&argc, &argv);
  MPI_Comm commRail; // Init communicator
  MPI_Comm_size(MPI_COMM_WORLD, &numProcs); // Total number of processes
  MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Which process am I?
  MPI_Comm_split( MPI_COMM_WORLD, rank == 0, 0, &commRail ); // Create communicator 

  if(rank == 0){ // I am the master then
    startTime = MPI_Wtime(); // Get the start time
    master(MPI_COMM_WORLD, commRail); // Call the master function
  }
  else{ // Crap, I'm a node then
    node(MPI_COMM_WORLD, commRail); // Call the node function
  }
  MPI_Finalize();
  return 0;
}

// Master 
int master(mCommunicator, commToUse)
MPI_Comm commToUse;
{
  int  i,j, size;
  char buf[256];
  
  MPI_Status status;
  MPI_Comm_size(mCommunicator, &size);
  
  //for (j=1; j<=2; j++) {
    for (i=1; i<size; i++) {
      MPI_Recv(buf, 256, MPI_CHAR, i, 0, mCommunicator, &status);
      fputs(buf, stdout);
    }
  //}
  printf("this is the end of exec\n");
}
  
// Node
int node(mCommunicator, commToUse)
MPI_Comm commToUse;
{
    char buf[256];
    int	 rank, i, interation;
    int ADD = 1; // 1= true 2 == false make this bool later
    double pi;

    MPI_Comm_rank(commToUse, &rank);
    
    for(i=0;i<999999; i++){ // 99999 then is the number of terms.
      switch(ADD){
	case 1:
	  pi += (4.0/((i*2)+1));
	  ADD = 2;
	  break;
	case 2:
	  pi -= (4.0/((i*2)+1));
	  ADD =1;
	  break;
      }
    }
     printf("PI: %lf\n", pi);
    
    sprintf(buf, "Hello from slave %d\n", rank);
    MPI_Send(buf, strlen(buf) + 1, MPI_CHAR, 0, 0, mCommunicator);
    
   // sprintf(buf, "Goodbye from slave %d\n", rank);
    //MPI_Send(buf, strlen(buf) + 1, MPI_CHAR, 0, 0, mCommunicator);
    return 0;
}

/*******************************************************************************
 * mPI - An example MPI program for calculating PI with timing.
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
