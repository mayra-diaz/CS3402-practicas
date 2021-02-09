/* PALABRA, NUMERO, ARCHIVO, COMILLAS, LLAVE IZQUIERDA,LLAVE DERECHA, SEMICOLON, \n */

%{
#include<stdio.h>
%}

N ([0-9])+
W ([a-zA-Z])+
A ([a-zA-Z]|[0-9])+[.](pdf|txt|py|cpp|h|r|l|hpp)


%%
{A} {printf("ARCHIVO\n");}
{N} {printf("NUMERO\n");}
{W} {printf("PALABRA\n");}
["'] {printf("COMILLAS\n");}
[{] {printf("LLAVE IZQUIERDA\n");}
[}] {printf("LLAVE DERECHA\n");} 
[;] {printf("SEMICOLON\n");} 
[\n] {printf("SALTO DE LINEA\n");} 
%%

int main(int argc, char *argv[]) {
	yylex();
	return 0;
}


