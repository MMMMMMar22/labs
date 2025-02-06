%{
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include "task3.tab.h"
//extern YYSTYPE yylval;
%}
%%
[0-9]+ {yylval= atoi(yytext); return NUMBER;}
// последовательность цифр преобразуется в число
// возвращается токен NUMBER
"+"    {return PLUS;}
// токен PLUS
"-"    {return MINUS;} 
"*"    {return MUL;} 
"/"    {return DIV;} 
"("    {return OPEN;} 
"\n"   {return END;} 
")"    {return CLOSE;} 
.      {printf("Error:\n");}
%%
int yywrap() { // вызывается когда достигнут конец 
    return 1; // нет больше данных
}
