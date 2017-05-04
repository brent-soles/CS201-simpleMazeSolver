#include "MazeRun.h"

#define MAX_STRING_SIZE 512

int main(int argc, char* argv[])
{

	//Make sure an argument has been passed
	if(!(argv[1]))
	{
		printf("No File Specified:\n\n");
		printf("\t->Program Terminated<-\n\n");
		return -1;
	}

	//Gets maze info (first 3 lines)
	int ** mazeInfo = mInfo(argv[1], 3, 2); // 3x2 M.D Array
	if(!mazeInfo && !(*mazeInfo)) 
	{
		printf("Error retrieving maze information:\n\n");
		printf("\t->Program Terminated<-\n\n");
		return -1;
	}
	
	//Prints the maze information
	printf("MAZEINFO\n");
	printf("MD ARR: %d, %d\n", mazeInfo[0][1], mazeInfo[0][0]);
	printf("ENT: %d, %d\n", mazeInfo[1][1], mazeInfo[1][0]);
	printf("EXT: %d, %d\n", mazeInfo[2][0], mazeInfo[2][1]);

	//Function returns the maze
	char ** maze = mGet(argv[1], mazeInfo[0][1], mazeInfo[0][0]);
	if(!maze && !(*maze))
	{ 
		printf("Error opening file:\n\n");
		printf("\t->Program Terminated<-\n\n");
		return -1;
	}

	//temp delim
	int temp = 0;
	int * delim = &temp;

	//Walks/Solves the maze
	//    maze  enter Row       enter Column    exit Row        exit Column     Row Size        Column Size
	mWalk(maze, mazeInfo[1][1], mazeInfo[1][0], mazeInfo[2][1], mazeInfo[2][0], mazeInfo[0][1], mazeInfo[0][0], delim);
	pmaze(maze, mazeInfo[0][1]);

	//Free's Memory
	deleteMDArray(maze, mazeInfo[0][1]);
	deleteMInfo(mazeInfo, 3);

	return 0;
}



