%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int yylex(); // функция лекс анализа
int yyerror( char *s); // обработка ошибок
%}

%token EOL // токен конец строки
%token NUMBER
%token PLUS MINUS
%% // начало правил грамматики
input: // для входных данных
|    line input; // можно вводить несколько строк
line:
    exp EOL {printf("%d\n",$1);} // пустая строка или выражение, $1 - результат выражений
|   EOL;
exp:
    NUMBER {$$=$1;} // вывод того же числа
|   exp PLUS NUMBER {$$=$1+$3;}
|   exp MINUS NUMBER {$$=$1-$3;};
%%
int main(){
    yyparse(); // считывание и обработка данных
    return 0;
}
int yyerror( char *s){ // обработка ошибок
    printf("ERROR:%s\n",s);
    return 0;
}
