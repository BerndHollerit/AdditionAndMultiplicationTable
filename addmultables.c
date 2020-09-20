// addmultables.c

// Author: HOLLERIT Bernd
//         
// Project start: April 26th, 2005
// 
// This is an exercise for the handling of two-dimensional arrays in C.
// It prints a nicely formatted addition table and multiplication table from zero to the input in range.

#include <stdio.h>
#include <stdbool.h>

unsigned MIN=1;
unsigned MAX=30;

// Returns true if x is in range [low..high], else false 
bool inRange(unsigned low, unsigned high, unsigned x) 
{ 
    return  ((x-low) <= (high-low)); 
}

// Prints the two-dimensional addition table and multiplication table between zero and the input
void addMulTables(unsigned range, char *operation)
{
	unsigned matrix_[range][range];

	// Print header
	printf("\n %s |  0", operation);

	for(int i=1; i<=range; i++)
	{
		if(i<10) {
			printf(" ");
		}
	  printf("  %d", i);
	}
	  
	printf("\n---+");

	for(int i=0; i<range; i++)
	  printf("----");
	  
	printf("---\n");

	// Print first column and table content
	for (int i=0; i<=range; i++)
	{
		// First column
		if(i<100) {
			printf(" ");
		}
		if(i<10) {
			printf(" ");
		}
		printf("%d|", i);

		// Table content
		for (int j=0; j<=range; j++)
		{
			if (operation == "+")
			{
				if(i+j<100)
				{
					printf(" ");
				}
				if(i+j<10) {
					printf(" ");
				}
				printf("%d ", i+j);
			}

			if (operation == "*")
			{
				if(i*j<100)
				{
					printf(" ");
				}
				if(i*j<10) {
					printf(" ");
				}
				printf("%d ", i*j);
			}
		}
		printf("\n");
	}
}

// Takes an input and calls the addition table and multiplication table if the input is between MIN and MAX
void inputPrompt()
{
	unsigned input=0;
	printf("Please enter a number between %d and %d: ", MIN, MAX);
	scanf("%d", &input);

	if (!inRange(MIN, MAX, input))
	{
		printf("Please run again and enter a number between %d and %d: ", MIN, MAX);
		return;
	}

	addMulTables(input, "+");
	addMulTables(input, "*");
} 

int main()
{
	inputPrompt();
	return(0);
}
	