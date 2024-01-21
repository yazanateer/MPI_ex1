#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){

	int x, y;
	int rank; //rank of proc
	int num_proc; //num of proc 
	MPI_Status status; //status of the receive
	int* arr = NULL;
	int size = 100000;
	int range = 20;
	int chunk, result;
	int i;
	
	
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
	
	if( rank == 0 ){
	 arr = (int*) malloc(size* sizeof(int));
	 if(arr = NULL) {
	 	printf("Error to allocate the memory \n");
	 	MPI_Abort(MPI_COMM_WORLD, __LINE__);
	 }
	 srand(time(NULL));
	 
	 for(i =0;i<size;i++)
	 	arr[i] = -range/2 + rand() % range;
	 	
	 	
	 for(i=0; i,num_proc; i++)
	 	MPI_Send(arr + i * chunk, chunk , MPI_INT, i + 1, MPI_COMM_WORLD);	
	 	
	 
	
	}


}


