%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task4.tab.h"
%}
%%
[0-9]+[\.]?[0-9]* { yylval.flo= atof(yytext);return NUMBER; }
// [0-9]+ одна или более цифр, хотя бы одно совпадение
// [\.]? ноль или одна точка, может и отсутствовать
// [0-9]* ноль или более цифр после точки
// далее преобразование str в double
// затем передача токена в синтаксический анализатор
"+" {return PLUS;} // найден токен + возвращается PLUS
"-" {return MINUS;}
"*" {return MULTYPLY;}
"/" {return DIVISION;}
"(" {return OPEN;}
")" {return CLOSE;}
\n  {return EOL;}
%%
