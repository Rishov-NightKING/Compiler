%option noyywrap
%x STRING
%x VECTOR
%x HEX

%{
#include<bits/stdc++.h>
#include"1605084_symbolTable.h"
using namespace std;

int line_count=1;
int error_count =0;
string str;
int str_index;

FILE *logout;
FILE *tokenout;

int counter =0;

int result = 0;
SymbolTable st;



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
{NEWLINE} {
			   line_count++;
		  }

 

"if" {
			fprintf(tokenout,"<IF>");
			fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n",line_count,yytext);
		}
		
"else" {
			fprintf(tokenout,"<ELSE>");
			fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n",line_count,yytext);
		}

"for" {
			fprintf(tokenout,"<FOR>");
			fprintf(logout,"Line no %d: TOKEN <FOR> Lexeme %s found\n",line_count,yytext);
		}

"while"	{
			fprintf(tokenout,"<WHILE>");
			fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n",line_count,yytext);
		}

"do" {
			fprintf(tokenout,"<DO>");
			fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n",line_count,yytext);
		}						

"break"	{
			fprintf(tokenout,"<BREAK>");
			fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n",line_count,yytext);
		}

"int" {
			fprintf(tokenout,"<INT>");
			fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n",line_count,yytext);
		}

"char" {
			fprintf(tokenout,"<CHAR>");
			fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n",line_count,yytext);
		}

"float"	{
			fprintf(tokenout,"<FLOAT>");
			fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n",line_count,yytext);
		}

"double" {
			fprintf(tokenout,"<DOUBLE>");
			fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n",line_count,yytext);
		}

"void" {
			fprintf(tokenout,"<VOID>");
			fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n",line_count,yytext);
		}

"return" {
			fprintf(tokenout,"<RETURN>");
			fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n",line_count,yytext);
		}

"switch" {
			fprintf(tokenout,"<SWITCH>");
			fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n",line_count,yytext);
		}

"case" {
			fprintf(tokenout,"<CASE>");
			fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n",line_count,yytext);
		}

"default" {
			fprintf(tokenout,"<DEFAULT>");
			fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n",line_count,yytext);
		}

"continue" {
			fprintf(tokenout,"<CONTINUE>");
			fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n",line_count,yytext);
		}



"+"|"-" {
			fprintf(tokenout,"<ADDOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"ADDOP");
			
		}

"*" | 
"/" | 
"%" {
			fprintf(tokenout,"<MULOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"MULOP");
			
		}

"++" |
"--" {
			fprintf(tokenout,"<INCOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"INCOP");
			
		}

"<" | 
"<=" |
">" |
">=" | 
"==" | 
"!=" {
			fprintf(tokenout,"<RELOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RELOP> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"RELOP");
			
		}

"=" {
			fprintf(tokenout,"<ASSIGNOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ASSIGNOP> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"ASSIGNOP");
			
		}

"&&" |
"||" {
			fprintf(tokenout,"<LOGICOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LOGICOP> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"LOGICOP");
			
		}

"&" |
"|" | 
"^" | 
"<<" | 
">>" {
			fprintf(tokenout,"<BITOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <BITOP> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"BITOP");
			
		}

"!" {
			fprintf(tokenout,"<NOT,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"NOTOP");
			
		}

"(" {
			fprintf(tokenout,"<LPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"LPAREN");
			
		}	


")" {
			fprintf(tokenout,"<RPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"RPAREN");
			
		}

"{" {
			fprintf(tokenout,"<LCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"LCURL");
			
		}

"}" {
			fprintf(tokenout,"<RCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"RCURL");
			
		}

"[" {
			fprintf(tokenout,"<LTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LTHIRD> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"LTHIRD");
			
		}

"]" {
			fprintf(tokenout,"<RTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"RTHIRD");
			
		}						

"," {
			fprintf(tokenout,"<COMMA,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"COMMA");
			
		}

";" {
			fprintf(tokenout,"<SEMICOLON,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n",line_count,yytext);
			st.insert(string(yytext),"SEMICOLON");
			
		}



{DIGIT}+ {
				fprintf(tokenout,"<CONST_INT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n",line_count,yytext);
				st.insert(string(yytext),"CONST_INT");
				
				
			}
{FLOAT_NUMBER} {
				fprintf(tokenout,"<CONST_FLOAT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);
				st.insert(yytext,"CONST_FLOAT");
				
		}

{ILL_FORMED_NUMBER} {
				fprintf(logout,"Error at line no %d :Ill formed number %s\n",line_count,yytext);
				error_count++;
				
				}
{DECIMAL_POINT_ERROR} {
				fprintf(logout,"Error at line no %d :Too many decimal point %s\n",line_count,yytext);
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
			        fprintf(tokenout,"<CONST_CHAR,%s>",s.c_str());
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				st.insert(s,"CONST_CHAR");
				
			  	
}

{MUL_CHAR_ERROR} {

				fprintf(logout,"Error at line no %d :Multi character constant error for character sequence like 				%s\n",line_count,yytext);
				error_count++;
}




{INVALID_SUFFIX} {
				fprintf(logout,"Error at line no %d :Invalid prefix on ID or invalid suffix on Number %s\n",line_count,yytext);
				error_count++;
					
                             }



{SINGLE_LINE_COMMENT} |
{MULTI_LINE_COMMENT_1} {
				for(int i=0;i<yyleng;i++)
				{	
					if(yytext[i]=='\n') line_count++;		
			        }
				fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n",line_count,yytext);
				//printf(logout,"TOKEN <COMMENT> Lexeme %s found\n",yytext);

                             }
{UNFINISHED_COMMENT} {
				for(int i=0;i<yyleng;i++)
				{	
					if(yytext[i]=='\n') line_count++;		
			        }
				fprintf(logout,"Error at line no %d:Unfinished comment %s found\n",line_count,yytext);
				error_count++;

                     }

<INITIAL>["] {
			
			BEGIN STRING;
			str_index = 0;
			str ="";
			//str_index++;

               }


<STRING>["] {
			const char* s1 = str.c_str();
			fprintf(tokenout,"<STRING,%s>",s1);
			fprintf(logout,"Line no %d : TOKEN<STRING> Lexeme %s found\n",line_count,s1);
			BEGIN INITIAL;
}
<STRING>("\\\n")* {
			//str = str+"\n";
			fprintf(logout,"\n");
			//str = str + '\n';
			line_count++;
}



<STRING><<EOF>> {
			 const char* s1 = str.c_str();
                 	 fprintf(logout,"Error at line no %d:Unterminated string %s found\n",line_count,s1);
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
				 fprintf(tokenout,"<IDENTIFIER,%s>",yytext);
			         fprintf(logout,"Line no %d: TOKEN <IDENTIFIER> Lexeme %s found\n",line_count,yytext);
				 st.insert(string(yytext),"ID");
				 
			
			 }

{IDENTIFIER}<{IDENTIFIER} {
				cout<<"hi vector"<<endl;
				counter++;
				BEGIN VECTOR;
}
<VECTOR>(<{IDENTIFIER}) {
					yymore();
					cout<<"j=hi 2"<<endl;
					counter++;
}
<VECTOR>">" {
	cout<<"hi 3"<<endl;
	counter--;
}
<VECTOR>\n {if(counter!=0) {cout<<"error"<<endl;}
		else {cout<<"yaaaay congrats"<<endl;}
		cout<<counter<<endl;
                counter = 0;
}
 int i;
"0x" {
	result = 0;
	BEGIN HEX;
}
. {
	int val = yytext - '0';
	result = result *16 + val;
}
"\." {
	int val = yytext-'0';
	 
}


{WHITESPACE}+ {}

{UNFINISHED_CHAR} {
				fprintf(logout,"Error at line no %d:UnFINISHED character %s found\n",line_count,yytext);
			 	error_count++;
}
{UNRECONGNIZED_CHARACTER} {
				fprintf(logout,"Error at line no %d:Unrecognized character %s found\n",line_count,yytext);
			 	error_count++;
} 


%%

int main(int argc,char *argv[]){
	st.enterScope(10);
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout= fopen("1605084_log.txt","w");
	tokenout= fopen("1605084_token.txt","w");

	yyin= fin;
	yylex();
	//fprintf(logout,st.printScopeTable());
	
	st.printAll();

	fprintf(logout,"Total lines : %d\n",line_count);
        fprintf(logout,"Total errors : %d\n",error_count);
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}
