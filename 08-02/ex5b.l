/* PALABRA, NUMERO, ARCHIVO, COMILLAS, LLAVE IZQUIERDA,LLAVE DERECHA, SEMICOLON, \n */

%{
#include<stdio.h>
#include<string.h>
%}

N ([0-9])*
W ([a-zA-Z0-9])*
A  {W}\.{pdf|txt}
C  {\" | \'}
LI \{
LD \}
SC \;
SL \n

%%
{N} {printf("NUMERO\t");}
{W} {printf("PALABRA\t");}
{A} {printf("ARCHIVO\t");}
{C} {printf("COMILLAS\t");}
{LI} {printf("LLAVE IZQUIERDA\t");}
{LD} {printf("LLAVE DERECHA\t");} 
{SC} {printf("SEMICOLON\t");} 
{SL} {printf("SALTO DE LINEA\t");} 
%%

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1], "r");
	yylex();
	fclose(yyin);
}


