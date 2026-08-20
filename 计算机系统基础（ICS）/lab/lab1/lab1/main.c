/*
* Main module of BinaLAB.
*
* Copyright 2023, SU Feng, All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

//
// Global Data
//

extern int phase(char *inputs);

extern const char* phase_id;


//
// Declarations
//

char inputs[256];


//
// Utilities
// 

void fixinput( char* inputs, int length )
{
	char *p;
	for ( p = inputs+length-1; p >= inputs; p -- )
		if ( *p == '\n' )  *p = '\0';
}


//
// Main Function
// 

int main( int argc, const char* argv[] )
{
#if defined(QUESTION)
    FILE *stream = 0;

    // If no command argument is given, read the input line from standard input.
    if (argc == 1)
		stream = stdin;
    else // When a file argument is given, read the input line from the file.
	if (argc == 2)
	{
		stream = fopen(argv[1], "r");
		if (! stream) {
			printf("Error: Failed to open the file %s.\n", argv[1]);
			exit(1);
		}
    }
    else // More than one command line arguments are not allowed.
	{
		printf("Usage: %s [input file]\n", argv[0]);
		exit(1);
    }

    printf("Welcome to the binary program analysis lab.\n");
    printf("Here begins the task. Please input your answer ...\n");

	// Read the input line
	memset(inputs, 0, sizeof(inputs));
	if (! fgets(inputs, sizeof(inputs), stream)) {
		printf("Error: Failed to read the input line.\n");
		exit(1);
	}
	fixinput(inputs, sizeof(inputs));

	// Run the phase
    if ( phase(inputs) )
        printf("Congratulations! You've completed %s successfully.\n", phase_id);
	else
        printf("Oops, %s failed. Try again.\n", phase_id);

#elif defined(ANSWER)
	memset(inputs, 0, sizeof(inputs));
	phase(inputs);
	
#endif
		
	return 0;
}
