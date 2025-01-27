%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define YYSTYPE double
int yyparse(); // синтаксический анализ
int yylex(void); // лексический анализ
void yyerror(const char *str){
        fprintf(stderr,"ошибка: %s\n",str);
}
int yywrap(){ // нет больше входных данных
        return 1;
} 
int main(){
        yyparse();
}
%}
%union{ // объединение для хранения различных типов данных для значений токенов
 double flo;
};
%token <flo> NUMBER
%token PLUS MINUS MULTYPLY DIVISION
%token OPEN CLOSE
%token EOL
%%
command: %empty
 | command exp EOL { printf(" "); } 
;
exp: factor
| exp PLUS factor { printf("+ "); }
| exp MINUS factor { printf("- "); }
;
factor: term
| factor MULTYPLY term { printf("* "); }
| factor DIVISION term { printf("/ "); }
;
term: NUMBER  { printf(" %.2f ",$1); } // вывод числа с 2 знаками после запятой
| OPEN exp CLOSE{ }
;
%%
