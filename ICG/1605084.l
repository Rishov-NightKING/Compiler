%option noyywrap
%x STRING

%{
#include"1605084_symbolTable.h"
#include"y.tab.h"

using namespace std;

extern YYSTYPE yylval;
void yyerror(const char *s);

int line_count = 1;
int error_count = 0;
string str;
int str_index;


//extern SymbolTable symbolTable;


%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
FLOAT_NUMBER [0-9]*\.?[0-9]+([E][+-]?[0-9]+)?

NEWLINE \n
CHARACTER_LITERAL '(.|"\\n"|"\\t"|"\\a"|"\\b"|"\\f"|"\\v"|"\\0"|"\\\\"|"\\'")' 
MUL_CHAR_ERROR '((.)(.)+)'
DECIMAL_POINT_ERROR (([0-9]+)*((\.)+))*([0-9]+)*
ILL_FORMED_NUMBER [0-9]*(\.[0-9]*)?(E[+-]?{FLOAT_NUMBER})
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
INVALID_SUFFIX [0-9]+[A-Za-z]+
SINGLE_LINE_COMMENT "//"[^\n](.)*$
MULTI_LINE_COMMENT_1 "/*"([^"*"]|"*"[^"/"])*"*/"
UNFINISHED_COMMENT "/*"([^"*"]|"*"[^"/"])*[^"*/"]*
UNFINISHED_CHAR '.
UNRECONGNIZED_CHARACTER .

%% 


{WHITESPACE}+ {}

{NEWLINE} {
			   line_count++;
		  }

 

"if" {
			return IF;
		}
		
"else" {
			return ELSE;
		}

"for" {
			return FOR;
		}

"while"	{
			return WHILE;
		}

"do" {
			return DO;
		}						

"break"	{
			return BREAK;
		}

"int" {
	      //cout<<"integer naki"<<endl;
			return INT;
		}

"char" {
			return CHAR;
		}

"float"	{
			return FLOAT;
		}

"double" {
			return DOUBLE;
		}

"void" {
			return VOID;
		}

"return" {
			return RETURN;
		}

"switch" {
			return SWITCH;
		}

"case" {
			return CASE;
		}

"default" {
			return DEFAULT;
		}

"continue" {
			return CONTINUE;
		}

"println"	{
			return PRINTLN;
		}

"+"|"-" {
			//cout<<"Add koro"<<endl;
			SymbolInfo* symbolInfo = new SymbolInfo(yytext,"ADDOP");
			yylval.symbol = symbolInfo;
			return ADDOP;
			
		}

"*" | 
"/" | 
"%" {
			SymbolInfo* symbolInfo = new SymbolInfo(yytext,"MULOP");
			yylval.symbol = symbolInfo;
			return MULOP;
		}

"++" {
			
			SymbolInfo* symbolInfo = new SymbolInfo(yytext,"INCOP");
			yylval.symbol = symbolInfo;
			return INCOP;
			
		}

"--" {
			SymbolInfo* symbolInfo = new SymbolInfo(yytext,"DECOP");
			yylval.symbol = symbolInfo;
			return DECOP;
			
		}

"<" | 
"<=" |
">" |
">=" | 
"==" | 
"!=" {
			SymbolInfo* symbolInfo = new SymbolInfo(yytext,"RELOP");
			yylval.symbol = symbolInfo;
			return RELOP;
			
		}

"=" {
			SymbolInfo* symbolInfo = new SymbolInfo(yytext,"ASSIGNOP");
			yylval.symbol = symbolInfo;
			//cout<<"hi from lexer assign"<<endl;
			return ASSIGNOP;
			
		}

"&&" |
"||" {
			SymbolInfo* symbolInfo = new SymbolInfo(yytext,"LOGICOP");
			yylval.symbol = symbolInfo;
			return LOGICOP;
			
		}

"&" |
"|" | 
"^" | 
"<<" | 
">>" {
			SymbolInfo* symbolInfo = new SymbolInfo(yytext,"BITOP");
			yylval.symbol = symbolInfo;
			return BITOP;
			
		}

"!" {
			SymbolInfo* symbolInfo = new SymbolInfo(yytext,"NOT");
			yylval.symbol = symbolInfo;
			return NOT;
			
		}

"(" {
			return LPAREN;
			
		}	


")" {
			return RPAREN;
		}

"{" {
			return LCURL;
		}

"}" {
			return RCURL;
			
		}

"[" {
	
			return LTHIRD;
			
		}

"]" {
			return RTHIRD;
			
		}						

"," {
			return COMMA;
			
		}

";" {
			return SEMICOLON;
			
		}



{DIGIT}+ {
	//cout<<"digit naki";
				//cout<<"hi integer"<<endl;
				SymbolInfo* symbolInfo = new SymbolInfo(yytext,"CONST_INT");
				yylval.symbol = symbolInfo;
				return CONST_INT;
				
				
			}
{FLOAT_NUMBER} {
				SymbolInfo* symbolInfo = new SymbolInfo(yytext,"CONST_FLOAT");
				yylval.symbol = symbolInfo;
				return CONST_FLOAT;
				
		}

{ILL_FORMED_NUMBER} {
		
				error_count++;
				
				}
{DECIMAL_POINT_ERROR} {
				
				error_count++;

				}


{CHARACTER_LITERAL} {
				string s;
				for(int i=0;i<strlen(yytext);i++)
				{
					if(yytext[i] != '\'')
					{
					    s = s+yytext[i];
					}
				}
				if(s == "\n")
				{
					s = '\n';
					s = s+'\0';
				}
				else if(s == "\t")
				{
					s = '\t';
					s = s+'\0';
				}
				else if(s == "\a")
				{
					s = '\a';
					s = s+'\0';
				}
				else if(s == "\b")
				{
					s = '\t';
					s = s+'\0';
				}
				else if(s == "\f")
				{
					s = '\f';
					s = s+'\0';
				}
				else if(s == "\v")
				{
					s = '\v';
					s = s+'\0';
				}
				else if(s == "\0")
				{
					s = '\0';
				}
				else if(s == "\\")
				{
					s = '\\';
					s = s+'\0';
				}
				else if(s == "\"")
				{
					s = '\t';
					s = s+'\0';
				}
				SymbolInfo* symbolInfo = new SymbolInfo(s,"CONST_CHAR");
				yylval.symbol = symbolInfo;
				return CONST_CHAR;
				
			  	
}

{MUL_CHAR_ERROR} {
				error_count++;
		 }




{INVALID_SUFFIX} {
				error_count++;
					
                             }



{SINGLE_LINE_COMMENT} |
{MULTI_LINE_COMMENT_1} {
						for(int i=0;i<yyleng;i++)
						{	
							if(yytext[i] =='\n') line_count++;		
						}

						}
{UNFINISHED_COMMENT} {
						for(int i=0;i<yyleng;i++)
						{	
							if(yytext[i] =='\n') line_count++;		
						}
						error_count++;

                    }

<INITIAL>["] {
			
			BEGIN STRING;
			str_index = 0;
			str ="";

               }



<STRING>["] {
			const char* s1 = str.c_str();
			BEGIN INITIAL;
			SymbolInfo *symbolInfo = new SymbolInfo(s1,"STRING");
			yylval.symbol = symbolInfo;
			return STRING;
}
<STRING>("\\\n")* {
			//str = str+"\n";
			//fprintf(logout,"\n");
			//str = str + '\n';
			line_count++;
}



<STRING><<EOF>> {
			 const char* s1 = str.c_str();
			 error_count++;
			 yyterminate();			
}


<STRING>[^\"] {
			str = str+yytext[str_index];
			//printf("%s\n",yytext[str_index]);
			str_index++;
			yymore();

}

{IDENTIFIER} {
				SymbolInfo* symbolInfo = new SymbolInfo(yytext,"ID");
				yylval.symbol = symbolInfo;
				return ID; 
			
			 }	


{UNFINISHED_CHAR} {
				
			 	error_count++;
}
{UNRECONGNIZED_CHARACTER} {
				
			 	error_count++;
} 

%%
