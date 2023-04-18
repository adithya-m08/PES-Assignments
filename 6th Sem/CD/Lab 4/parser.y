%{
	#include "abstract_syntax_tree.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char* s); 											// error handling function
	int yylex(); 													// declare the function performing lexical analysis
	extern int yylineno; 											// track the line number
%}

%union																// union to allow nodes to store return different datatypes
{
	char* text;
	expression_node* exp_node;
}



%token <text> T_ID T_NUM

%type <exp_node> E T F

/* specify start symbol */
%start START


%%
START : ASSGN	{ 
					printf("Valid syntax\n");
	 				YYACCEPT;										// If program fits the grammar, syntax is valid
	 			}

/* Grammar for assignment */
ASSGN : T_ID '=' E	{
				display_exp_tree($3);			// displaying the expression tree
					}
	;

/* Expression Grammar */
E : E '+' T 	{
			$$ = init_exp_node(strdup("+"),$1,$3);		// create a new node of the AST and set left and right children appropriately
				}
	| E '-' T 	{
			$$ = init_exp_node(strdup("-"),$1,$3);			// create a new node of the AST and set left and right children appropriately
				}
	| T 	{ $$ = $1; }
	;
	
	
T : T '*' F 	{
			$$ = init_exp_node(strdup("*"),$1,$3);				// create a new node of the AST and set left and right children appropriately
				}
	| T '/' F 	{
				$$ = init_exp_node(strdup("/"),$1,$3);			// create a new node of the AST and set left and right children appropriately
				}
	| F {
		$$ = $1;	//pass AST node to the parent
		}
	;

F : '(' E ')' { $$ = $2; }
	| T_ID 	{
			$$ = init_exp_node(strdup($1),NULL,NULL);		// creating a terminal node of the AST
			}
	| T_NUM 	{
				$$ = init_exp_node(strdup($1),NULL,NULL);			// creating a terminal node of the AST
				}
	;

%%


/* error handling function */
void yyerror(char* s)
{
	printf("Error :%s at %d \n",s,yylineno);
}


/* main function - calls the yyparse() function which will in turn drive yylex() as well */
int main(int argc, char* argv[])
{
	yyparse();
	return 0;
}
