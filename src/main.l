
%{

	//Victor Ferrao Santolim
	//RA 187888

	//Programa em Lex que faz a conversao de Camel Case

#include <stdio.h>
#include "ccc_lib.h"
char output[100];

%}


%%

((.*[A-Z][^ \n\t\r]*[_].*)|(.*[_][^ \n\t\r]*[A-Z].*)) {printf("ERRO");}

([A-Z][a-z]+[a-z0-9]*){2,}[A-Z]? {

	camelcase_to_underline(yytext, output);
	printf("%s" , output);
}

([a-z]+[_][a-z]+)+([_][a-z])* {

	underline_to_camelcase(yytext, output);
	printf("%s" , output);
}

%%

int main() {
  yylex();
  return 0;
}


