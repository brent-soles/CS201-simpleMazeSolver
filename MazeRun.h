#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//Prints the maze
//	@params: maze, # of rows
//	@pre: maze is not null
//	@post: maze is output to console 
void pmaze(char ** maze, int size)
{
	if(!maze) return;

	int i;
	for(i = 0; i < size; ++i)
	{
		if(maze[i]) printf("%02d : %s\n", i, maze[i]);
	}

}

//Gets the maze information
//	@param: string filename
//	@pre: have a char ** to be assigned
//	@post: 2D array returned
char** mGet(char * filename, int rowc, int colc)
{
	++colc; //for NULL Character	

	FILE * srcfile = fopen(filename, "r");
	if(!srcfile) return NULL;
	
	//Reason for 4x4 grid is for null characters
	char ** info = (char **)malloc(sizeof(char*) * rowc);
	int i;
	for(i = 0; i < rowc; ++i)
	{
		info[i] = (char*)malloc(sizeof(char*) * colc); 
	}

	//sets up temp array	
	char temp[colc + 1];
	//count to get past first 3 lines
	int junkCount = 0;	

	//gets past maze info
	while(junkCount < 3)
	{
		++junkCount;
		fscanf(srcfile, "%s", temp);
	}

	//current string row
	int currRow = 0;

	//Copies each line into info	
	while((fscanf(srcfile, "%s", temp)) != EOF)
	{
		temp[colc - 1] = '\0';
		
		strcpy(info[currRow], temp);
		++currRow;	
	}

	fclose(srcfile);

	return info;
}

//Gets the maze informaiton
//	@params: string (filename), the number of rows, the number of columns
//	@pre: int ** to pass return value to
//	@post: Mult Dim Array returned
int ** mInfo(char * filename, int rowc, int colc)
{
	if(!filename) return 0;
	
	FILE * srcfile = fopen(filename, "r");

	if(rowc <= 0 && colc <= 0) return 0;

	int readCount = 0;
	int temp = 0;

	//Initialization/Allocation of memory
	int ** mazeInfo = (int**)malloc(sizeof(int*) * rowc);
	if(!mazeInfo) return 0;

	int i;
	for(i = 0; i < rowc; ++i)
	{
		mazeInfo[i] = (int*)malloc(sizeof(int) * colc);
	}

	int currRow = 0;
	int currCol = 0;

	while(readCount < 3)
	{
		++readCount;
	
		//Gets first number	
		fscanf(srcfile, "%i", &temp);
		mazeInfo[currRow][currCol++] = temp;
		fgetc(srcfile);//gets rid of ','
	
		//Gets second number	
		fscanf(srcfile, "%i", &temp);
		mazeInfo[currRow][currCol] = temp;
		fgetc(srcfile);//gets rid of '\n'
		
		currCol = 0;
		++currRow;
	}

	fclose(srcfile);
	
	return mazeInfo;
}

//Walks the maze and marks each walked "square"
//	@params: maze (array of strings), enter row/column, exit row/colum, bounds
//	@pre: maze is not null
//	@post: maze is solved, end denoted by 'F' for finished/solved
void mWalk(char ** maze, int enRow, int enCol, int exRow, int exCol, int rowSize, int colSize, int * delim)
{
	//Denotes the maze has been solved
	//Put at exit
	if(enRow == exRow && enCol == exCol)
	{
		printf("\nMAZE SOLVED\n");
		*delim = 1;
		maze[enRow][enCol] = 'F';
		return;
	}

	if(*delim == 0)
	{
		//Now walked
		maze[enRow][enCol] = 'W';

		//TEST CASES
		//WILL BE RIGHT DOWN LEFT UP

		//Right
		if(enCol < colSize)
		{
			if(maze[enRow][enCol + 1] == '0')
			{
				//Passes shift to go right
				mWalk(maze, enRow, (enCol + 1), exRow, exCol, rowSize, colSize, delim);
			}
		}


		//Down
		if(enRow < rowSize)
		{
			if(maze[enRow + 1][enCol] == '0')
			{
				//Passes shift to go down
				mWalk(maze, (enRow + 1), enCol, exRow, exCol, rowSize, colSize, delim);
			}
		}


		//Left
		if(enCol > 0)
		{
			if(maze[enRow][enCol - 1] == '0')
			{
				//Passes shift to go left
				mWalk(maze, enRow, (enCol - 1), exRow, exCol, rowSize, colSize, delim);
			}
		}


		//Up
		if(enRow > 0)
		{
			if(maze[enRow - 1][enCol] == '0')
			{
				//Passes shift to go up
				mWalk(maze, (enRow - 1), enCol, exRow, exCol, rowSize, colSize, delim);
			}
		}

		return;
	}
}

//Deletes the 2 Dimensional Array of char type
//	@param: 2D array, number of rowss
//	@pre: 2D array has memory
//	@post: 2D array deallocted and NULL
void deleteMDArray(char ** multArray, int rowsSize)
{
	if(multArray && *multArray)
	{
		int i;
		for(i = 0; i < rowsSize; ++i)
		{
			free(multArray[i]);
			multArray[i] = NULL;
		}

		free(multArray);
		multArray = NULL;
	}
}

//Deletes the 2 Dimensional Array of int type
//	@param: 2D array, number of rows
//	@pre: 2D array has memory
//	@post: 2D array deallocted and NULL
void deleteMInfo(int** multArray, int rowSize)
{
	if(multArray && *multArray)
	{
		int i;
		for(i = 0; i < rowSize; ++i)
		{
			free(multArray[i]);
			multArray[i] = NULL;
		}
		
		free(multArray);
		multArray = NULL;
	}
}

