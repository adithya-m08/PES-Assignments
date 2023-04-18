%{
	#include "sym_tab.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define YYSTYPE char*
	int type=-1;	
	char* vval="~";	
	int vtype=-1;	
	int scope=0;	
	void yyerror(char* s); 
	int yylex(); 
	extern int yylineno; 
%}

%token T_INT T_CHAR T_DOUBLE T_WHILE  T_INC T_DEC   T_OROR T_ANDAND T_EQCOMP T_NOTEQUAL T_GREATEREQ T_LESSEREQ T_LEFTSHIFT T_RIGHTSHIFT T_PRINTLN T_STRING  T_FLOAT T_BOOLEAN T_IF T_ELSE T_STRLITERAL T_DO T_INCLUDE T_HEADER T_MAIN T_ID T_NUM

%start START

%%

START : PROG { printf("Valid syntax\n");
	 YYACCEPT; }	
        ;						

PROG :  MAIN PROG				
	| DECLR ';' PROG 			
	| ASSGN ';' PROG 			
	| Array_declaration ';' PROG
	| 					
	;

Array_declaration : T_ID '[' T_NUM ']' 
          | T_ID '[' T_ID ']' 
          | T_ID
          ;

DECLR : TYPE LISTVAR 
	;	

LISTVAR : LISTVAR ',' VAR 
	  | VAR
	  ;

VAR: T_ID '=' EXPR 	{
				if(check_sym_tab($1))	
				{
					printf("Variable %s already declared\n",$1);
					yyerror($1);
				}
				else
				{
				insert_symbol($1,size(type),type,yylineno,scope);
				insert_val($1,vval,yylineno);
				vval="~";	
				type=-1;
				}
			}
     | T_ID 		{
				if(check_sym_tab($1))	
				{
					printf("Variable %s already declared\n",$1);
					yyerror($1);
				}
				else{
				insert_symbol($1,size(type),type,yylineno,scope);
				type=-1;	
				}
			}	 
	
TYPE : T_INT {type = INT;}		
       | T_FLOAT {type = FLOAT;}	
       | T_DOUBLE {type = DOUBLE;}	
       | T_CHAR {type = CHAR;}		
       ;
    
ASSGN : T_ID {type=retrieve_type($1);}'=' EXPR 	{
				if(!check_sym_tab($1))	
				{
					printf("Variable %s not declared\n",$1);
					yyerror($1);
				}
				insert_val($1,vval,yylineno);
				vval="~";		
				type=-1;		
			}
	;

EXPR : EXPR REL_OP E  
       | E {vval=$1;}
       ;

E : E '+' T 	{ 
			if(vtype==2)				
				sprintf($$,"%d",(atoi($1)+atoi($3)));
			else if(vtype==3)			
				sprintf($$,"%lf",(atof($1)+atof($3)));
			else
			{
				printf("Character used in arithmetic\n");
				yyerror($$);
				$$="~";
			}
		}
    | E '-' T 	{ 
			if(vtype==2)				
				sprintf($$,"%d",(atoi($1)-atoi($3)));
			else if(vtype==3)			
				sprintf($$,"%lf",(atof($1)-atof($3)));
			else
			{
				printf("Character used in arithmetic\n");
				yyerror($$);
				$$="~";
			}
		}
    | T {$$=$1;}
    ;
	
T : T '*' F 	{ 
			if(vtype==2)				
				sprintf($$,"%d",(atoi($1)*atoi($3)));
			else if(vtype==3)			
				sprintf($$,"%lf",(atof($1)*atof($3)));
			else
			{
				printf("Character used in arithmetic\n");
				yyerror($$);
				$$="~";
			}
		}
    | T '/' F 	{ 
			if(vtype==2)				
				sprintf($$,"%d",(atoi($1)/atoi($3)));
			else if(vtype==3)			
				sprintf($$,"%lf",(atof($1)/atof($3)));
			else
			{
				printf("Character used in arithmetic\n");
				yyerror($$);
				$$="~";
			}
		}
    | F {$$=$1;}
    ;

F : '(' EXPR ')'
    | T_ID 	{
			if(check_sym_tab($1))		
			{
				char* check=retrieve_val($1);
				if(check=="~")		
				{
					printf("Variable %s not initialised",$1);
					yyerror($1);
				}
				else
				{	
					$$=strdup(check);
					vtype=type_check(check);	
					if(vtype!=type && type!=-1)	
					{
						printf("Mismatch type\n");
						yyerror($1);
					}	
				}
			}
		}
    | T_NUM 	{
    			$$=strdup($1); 
    			vtype=type_check($1);
    			if(vtype!=type && type!=-1)	
			{
				printf("Mismatch type\n");
				yyerror($1);
			}
		}
    | T_STRLITERAL {
    			$$=strdup($1); 
    			vtype=1;
			if(vtype!=type)		
			{
				printf("Mismatch type\n");	
				yyerror($1);
			}
		}
    ;

REL_OP :   T_LESSEREQ
	   | T_GREATEREQ
	   | '<' 
	   | '>' 
	   | T_EQCOMP
	   | T_NOTEQUAL
	   ;	

MAIN : TYPE T_MAIN '(' EMPTY_LISTVAR ')' '{' {scope++;} STMT '}' {scope--;};

EMPTY_LISTVAR : LISTVAR
		|	/* similar to lambda */
		;

STMT : STMT_NO_BLOCK STMT
       | BLOCK STMT
       |
       ;

STMT_NO_BLOCK : DECLR ';'
       | ASSGN ';'
       ;

BLOCK : '{' {scope++;} STMT '}' {scope--;};

COND : EXPR  
       | ASSGN
       ;
      
%%

void yyerror(char* s)
{
	printf("Error :%s at %d \n",s,yylineno);
}

int main(int argc, char* argv[])
{
	t=init_table();
	yyparse();
	display_sym_tab();
	return 0;
}