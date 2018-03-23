//Victor Ferrao Santolim
//RA 187888

//Funcoes em C para o Lex que conversor de CamelCase

#include "ccc_lib.h"
#include <string.h>

void camelcase_to_underline(char *input, char *output) {

	int i=0;
	int numUnder=0; //Numero de underlines detectados
	int tamInput = strlen(input); //Tamanho do input

	strcpy(output, ""); //Limpa a string input
	
	//Converte a primeira letra para minuscula
	output[0] = input[0] + 32;

	//Percorre o vetor de entrada	
	for(i = 1; i < tamInput ; i++)
	{

		//Se achar maiuscula
		if(input[i] >= 65 && input[i] <= 90)
		{
			//Troca por underline
			output[i+numUnder] = '_';
			numUnder ++;
			//E adiciona a letra minuscula correspondente
			output[i+numUnder] = input[i] + 32;
		}
		else
		{
			//Caso contrario apenas repita a letra
			output[i+numUnder] = input[i];
		}
	}

	//Null-terminate a string
	output[i+numUnder] = '\0';

	return;
}

void underline_to_camelcase(char *input, char *output) {


	int i=0;
	int numUnder=0; //Numero de underlines gerados
	int tamInput = strlen(input); //Tamanho do input

	strcpy(output, ""); //Limpa a string input
	
	//Converte a primeira letra para maiuscula
	output[0] = input[0] - 32;

	//Percorre o vetor de entrada
	for(i = 1; i < tamInput ; i++)
	{

		//Se achar um underline
		if(input[i+numUnder] == '_')
		{
		
			//Substitui pela proxima letra na versao maiuscula
			numUnder ++;
			output[i] = input[i+numUnder] - 32;
		}
		else
		{
			//Caso contrario apenas repete a letra			
			output[i] = input[i+numUnder];
		}
	}

	//Null-terminate a string
	output[i-numUnder] = '\0';

 	return;
}




