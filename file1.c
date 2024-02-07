
#include <stdio.h>
#include <math.h>

#define HEAVY  1000
#define SIZE   60

// This function performs heavy computations, 
// its run time depends on x and y values
// DO NOT change the function
double heavy(int x, int y) {
	int i, loop;
	double sum = 0;
	
	if (x > 0.25*SIZE &&  x < 0.5*SIZE && y > 0.4 * SIZE && y < 0.6 * SIZE)
		loop = x * y;
	else
		loop = y + x;

	for (i = 0; i < loop * HEAVY; i++)
		sum += cos(exp(sin((double)i / HEAVY)));

	return  sum;
}

// Sequencial code to be parallelized
int main(int argc, char* argv[]) {
	int x, y;
	int size = SIZE;
	double answer = 0;
	
	int rank, numP; // the rank of the current process and the number of processor 


	MPI_INIT(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numP);
	MPI_Comm_rank(MPI_COMM_WORLD, &size);
	
	
	int chunks, start, end;
	double current_answer = 0;
	
	chunks = size / numP;
	start = rank * chunks;
	end = start + chunks;
	
	for(x= start;x<end;x++)
	   for(y=start;y<end;y++)
	   	current_answer+= heavy(x,y);
	   	MPI_Reduce(&current_answer, &answer, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	
	

	printf("answer = %e\n", answer);
	
	MPI_FINALIZE(
}
