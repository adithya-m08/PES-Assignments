%{
	#include "sym_tab.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define YYSTYPE char*
	int type=-1;    //initial declaration of type for symbol table
        char* vval="~"; //initial declaration of value for symbol table
        int vtype=-1;   //initial declaration for type checking for symbol table
        int scope=0;    //initial declaration for scope
        void yyerror(char* s); // error handling function
        int yylex(); // declare the function performing lexical analysis
        extern int yylineno; // track the line number


%}

%token T_INT T_CHAR T_DOUBLE T_WHILE  T_INC T_DEC   T_OROR T_ANDAND T_EQCOMP T_NOTEQUAL T_GREATEREQ T_LESSEREQ T_LEFTSHIFT T_RIGHTSHIFT T_PRINTLN T_STRING  T_FLOAT T_BOOLEAN T_IF T_ELSE T_STRLITERAL T_DO T_INCLUDE T_HEADER T_MAIN T_ID T_NUM

%start START


%%
START : PROG { printf("Valid syntax\n"); YYACCEPT; }	
        ;	
	  
PROG :  MAIN PROG				
	|DECLR ';' PROG 				
	| ASSGN ';' PROG 			
	| 					
	;
	 

DECLR : TYPE LISTVAR 
	;	


LISTVAR : LISTVAR ',' VAR 
	  | VAR
	  ;

VAR: T_ID '=' EXPR 	{
				/*
					to be done in lab 3
				*/
			}
     | T_ID 		{
				/*
                   			check if symbol is in table
                    			if it is then print error for redeclared variable
                    			else make an entry and insert into the table
                    			revert variables to default values:type
                    		*/
			}	 

//assign type here to be returned to the declaration grammar
TYPE : T_INT {type=INT; printf("Int type\n");}
       | T_FLOAT {type=FLOAT;}
       | T_DOUBLE {type=DOUBLE;}
       | T_CHAR {type=CHAR;}
       ;
    
/* Grammar for assignment */   
ASSGN : T_ID '=' EXPR 	{retrieve_type($1);}'='EXPR
					{
						if (check_sym_tab($1)==0){
							printf("variable not declared\n",$1);
							yyerror($1);
					}
					insert_val($1,vval,yylineno);
					vval='~'
					type=-1;
				}
	;

EXPR : EXPR REL_OP E
       | E 
       ;
	   
E : E '+' T {printf($$,"%d",(atoi($1)+atoi($3)));}
    | E '-' T {printf($$,"%d",(atoi($1)-atoi($3)));}
    | T 
    ;
	
	
T : T '*' F {printf($$,"%d",(atoi($1)*atoi($3)));}
    | T '/' F {printf($$,"%d",(atoi($1)/atoi($3)));}
    | F
    ;

F : '(' EXPR ')'
    | T_ID {if (check_sym_table($1))
			{
				char* value=retrieve_val($1);
					if (value="~")
				{
					printf("variable %s not initialised\n",$1);
					yyerror($1);
				}
				else
					$$=strdup(value);
			}
		}

    | T_NUM {$$=strdup($1);}
    | T_STRLITERAL {$$=strdup($1);}
    ;

REL_OP :   T_LESSEREQ
	   | T_GREATEREQ
	   | '<' 
	   | '>' 
	   | T_EQCOMP
	   | T_NOTEQUAL
	   ;	


/* Grammar for main function */
MAIN : TYPE T_MAIN '(' EMPTY_LISTVAR ')' '{' STMT '}';

EMPTY_LISTVAR : LISTVAR
		|	
		;

STMT : STMT_NO_BLOCK STMT
       | BLOCK STMT
       |
       ;


STMT_NO_BLOCK : DECLR ';'
       | ASSGN ';' 
       ;

BLOCK : '{' STMT '}';

COND : EXPR 
       | ASSGN
       ;


%%


/* error handling function */
void yyerror(char* s)
{
	printf("Error :%s at %d \n",s,yylineno);
}


int main(int argc, char* argv[])
{
	/* initialise table here */
	yyparse();
	/* display final symbol table*/
	return 0;

}
