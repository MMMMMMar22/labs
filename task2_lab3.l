%{
    #include <stdio.h> // ввод-вывод
    #include <string.h> // строки
    #include <stdlib.h>
    #include "task2.tab.h" // заголовочный файл (определение токенов)
%}

%% // начало правил анализатора
[0-9]+  {yylval=atoi(yytext); return NUMBER;} // atoi - преобразование в целое число
"+" {return PLUS;}
"-" {return MINUS;}
\n  {return EOL;}
. {printf("Error:\n");}
%% // конец правил
int yywrap(){ // не обрабатываем доп данные (функция вызывается для доп ввода)
}
