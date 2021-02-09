%{
#include<stdio.h>
%}
ends_with_a .*a
begins_with_a a+.*
%%
{ends_with_a} printf("Accepted Text: %s \n", yytext);
{begins_with_a} printf("Accepted Text: %s \n", yytext);
.*/n;
%%
int main(){
	yylex() ;
	return 0;
}
