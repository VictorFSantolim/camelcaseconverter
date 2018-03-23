
#include "ccc_lib.h"
#include <string.h>
#include <stdio.h>

void camelcase_to_underline(char *input, char *output) {

	int i=0;
	int numUnder=0;

	int tamInput = strlen(input);

	strcpy(output, "");
	//printf("Input=|%s|\n", input);
	//printf("Output=|%s|\n", output);

	output[0] = input[0] + 32;

	for(i = 1; i < tamInput ; i++)
	{

		if(input[i] >= 65 && input[i] <= 90)
		{
		
			output[i+numUnder] = '_';
			numUnder ++;
			output[i+numUnder] = input[i] + 32;
		}
		else
		{
			output[i+numUnder] = input[i];
		}
	}

	output[i+numUnder] = '\0';


	return;
}

void underline_to_camelcase(char *input, char *output) {


	int i=0;

	int numUnder=0;

	int tamInput = strlen(input);
	strcpy(output, "");
	

	output[0] = input[0] - 32;

	for(i = 1; i < tamInput ; i++)
	{

		if(input[i+numUnder] == '_')
		{
		
			numUnder ++;
			output[i] = input[i+numUnder] - 32;
		}
		else
		{
			output[i] = input[i+numUnder];
		}
	}

	output[i-numUnder] = '\0';

 	return;
}




