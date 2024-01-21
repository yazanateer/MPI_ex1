#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){

	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	printf("the process %d of %d, My rank is %d\n",rank, size, rank);
	
	int recv_data , send_data;
	send_data = 15;
	
	if (rank == 0) {
		MPI_Send(&send_data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Process %d send this msg: %d\n", rank, send_data);
		
		//now this process will receive a data from the second process so we will defien the recv
		MPI_Recv(&recv_data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process %d received this msg: %d\n", rank, recv_data);
	} else{
		MPI_Recv(&recv_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //now the process 1 get the msg from proc 0
		printf("Process %d received msg: %d\n", rank, recv_data);
		
		int num = rand() % 10 + 1;
		recv_data *=num;
		
		MPI_Send(&recv_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		printf("Process %d, send the msg: %d\n", rank, recv_data);
		
	}
	
	
	MPI_Finalize();
	return 0;

}


