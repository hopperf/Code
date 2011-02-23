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
#include <stdbool.h> // Needed for bool datatype wtf c, wtf

int main(int argc, char *argv[]){
  int numProcs, procRank, iterations;
  double startTime, endTime, processingTime;

  MPI_Init(&argc, &argv); // Init MPI
  MPI_Comm commRail; // Init communicator
  MPI_Comm_size(MPI_COMM_WORLD, &numProcs); // Get the total number of processes
  MPI_Comm_rank(MPI_COMM_WORLD, &procRank); // Which process am I?
  MPI_Comm_split(MPI_COMM_WORLD, procRank == 0, 0, &commRail); // Create communicator out of COMM_WORLD 

  if(procRank == 0){ // Master, Blaster rule Thunderdome!!
    startTime = MPI_Wtime(); 
    masterProc(MPI_COMM_WORLD, commRail); 
    endTime = MPI_Wtime();
    processingTime = endTime - startTime; 
    printf("%d Processes calculated PI in: %lf Seconds\n", numProcs - 1, processingTime);
  }
  
  else{ // Crap, I'm a worker bee. better get to work!
    iterations = 9999;
    nodeProc(MPI_COMM_WORLD, commRail, iterations); 
  }
  
  MPI_Finalize();
  return 0;
}

// Master Process
int masterProc(mCommunicator, commToUse)
MPI_Comm commToUse;
{
  int  i, size;
  char buf[256];
  
  MPI_Status status;
  MPI_Comm_size(mCommunicator, &size);
  
    for (i=1; i<size; i++) { // Recive 1 message from all node processes
      MPI_Recv(buf, 256, MPI_CHAR, i, 0, mCommunicator, &status);
      fputs(buf, stdout);
    }
}
  
// Node Process
int nodeProc(mCommunicator, commToUse, iterations)
MPI_Comm commToUse;
{
    char buf[256];
    int	 rank, i;
    bool toggle = true; // 0 = ADD 1 = SUB
    double pi;

    MPI_Comm_rank(commToUse, &rank);
   
    for(i = 0;i < iterations; i++){ 
      switch(toggle){
	case true:
	  pi += (4.0/((i*2)+1));
	  toggle = false;
	  break;
	case false:
	  pi -= (4.0/((i*2)+1));
	  toggle = true;
	  break;
      }
    }
    
    sprintf(buf, "Node %d got %lf for PI\n", rank + 1, pi);
    MPI_Send(buf, strlen(buf) + 1, MPI_CHAR, 0, 0, mCommunicator);
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
