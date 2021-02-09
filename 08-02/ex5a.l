/*Añadir numeración de líneas*/

%{
int yylineno;
%}

%%
^(.*)\n {fprintf(yyout, "%d\t", yylineno++); ECHO;}
%%

int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	yyout=fopen(argv[2], "w");
	yylex();
	fclose(yyin);
	fclose(yyout);
	return 0;
}
