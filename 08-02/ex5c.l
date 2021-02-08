/*lex program to count number of chars, words and lines*/
%{ 
#include<stdio.h> 
#include<string.h> 
int lines = 0, words=0, chars=0; 
%} 

/* Rules Section */
%% 
\n      {++lines; ++chars;}
.       {++chars;}
([a-zA-Z0-9])*    {++words; chars+= strlen(yytext);}
%%
  
int main() 
{    
    // The function that starts the analysis 
    yylex(); 
    printf("Chars:%d\nWords:%d\nLines:%d\n", chars, words, lines);
    return 0; 
} 
