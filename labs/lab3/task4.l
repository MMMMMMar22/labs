%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task4.tab.h"
%}
%%
[0-9]+[\.]?[0-9]* { yylval.flo= atof(yytext);return NUMBER; } // [0-9]* - 0 или более цифр после точки
//  atof(yytext) - преобразует текст в double
"+" {return PLUS;} // найден токен + возвращается PLUS
"-" {return MINUS;}
"*" {return MULTYPLY;}
"/" {return DIVISION;}
"(" {return OPEN;}
")" {return CLOSE;}
\n  {return EOL;}
%%
