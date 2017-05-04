mRun program by: Brent Daniels-Soles (ODIN: brent8, PSU ID: 922140535)

To run the program type:

	./mRun <maze file>

The program only takes one maze at a time. The format for the maze should be:

	-First three lines have maze information:
		
		1st Line) How long each maze string is followed by how many there are. 
		ex.) 5, 4 -> 	"XX0XX"
				"XX00X"
				"XXX0X"
				"XXX0X"
		
		2nd Line) Coordinates of the entrance of the maze.
		ex.) entrance to above maze would be: 2, 0.
		     So it would be the first string, third element of that string. 

		3rd Line) Coordinates of the exit of the maze.
		ex.) Exit of the above maze would be: 3, 3
		     So it would be the fourth string, fourth element of that string.


_______________mInfo__:
	-To get the maze information, I have written a function that creates an array of integer arrays (int**).
	 Because it is assumed the file formatting is always correct, I know that there are to be 3 sets of X, Y
	 coordinates. So the function mInfo takes the arguments (char * filename, int # int arrays, size of int arrays).
	 The function then returns an int**.

_______________mGet__:
	-After those three lines, is the maze, which is of the char** type. To get the actual maze, the functino mGet loops through the first
	 three lines and then proceeds to read in the strings. Firstly, each string is read in to a temp array, and
	 then using strcpy, the function copies them over to their respective line in the (char**)maze. After all the
	 maze lines are copied, then char** maze is returned.

______________mWalk__:
	-After everything has been initialized and assigned, the mWalk function is called. The parameters of this function are (char** maze,
	 int entrance string, int entrence element, int exit string, int exit element, int string bound, int element bound, int * found delim)
	 The functiion stars at the enterance and checks each surrounding element to see if there is a '0'. If there is, the function recursively
	 passes to that next element with the '0' and marks it as walked. If the end is reached, then the found delim is set to 1 and the stack
	 returns without walking anymore places.

_____________(char**)delteMDArray/(int**)deleteMInfo__:
	-Once the maze is solved, two funcitons are called to free the memory allocated for the char ** and int **.
	
