%{
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<bits/stdc++.h>
#include "1605084_symbolTable.h"


using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;

FILE *fp;
FILE *errorout;
FILE *logout;

extern int line_count;
extern int error_count;

SymbolTable symbolTable;

vector<SymbolInfo*>declaration_list_vector;
vector<pair<string,string>>parameter_list_vector;
vector<SymbolInfo*>argument_list_vector;


void yyerror(const char *s)
{
 	fprintf(errorout,"Error at line no %d :  %s\n\n",line_count,s);
	error_count++;
}



%}

%union{
        SymbolInfo* symbol;
}


%token <symbol>ID
%token <symbol>CONST_INT
%token <symbol>CONST_FLOAT
%token <symbol>CONST_CHAR
%token <symbol>ADDOP
%token <symbol>MULOP
%token <symbol>LOGICOP
%token <symbol>RELOP
%token <symbol>STRING
%token IF ELSE FOR WHILE DO BREAK CONTINUE INT FLOAT CHAR DOUBLE VOID RETURN SWITCH CASE DEFAULT INCOP DECOP ASSIGNOP LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD SEMICOLON COMMA NOT PRINTLN BITOP 

%type <symbol>start parameter_list arguments argument_list unit type_specifier expression logic_expression rel_expression simple_expression term unary_expression factor variable var_declaration declaration_list program  func_declaration func_definition statement expression_statement compound_statement statements

%left INCOP DECOP
%left ADDOP 
%left MULOP
%left RELOP LOGICOP BITOP
%right ASSIGNOP 


%nonassoc ELSE_LOWER
%nonassoc ELSE
%error-verbose
%%

start: program
	{
		fprintf(logout,"At line no : %d start : program\n",line_count);

		fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		$$ = new SymbolInfo();
		$$->set_symbol_name($1->get_symbol_name());
	}
	;

program: program unit 
		{
			fprintf(logout,"At line no : %d program : program unit\n",line_count);
			
			fprintf(logout,"%s\n%s\n\n",$1->get_symbol_name().c_str(),$2->get_symbol_name().c_str());
			$$ = new SymbolInfo();
			$$->set_symbol_name($1->get_symbol_name().append($2->get_symbol_name()));
		}
		| unit
		{
			fprintf(logout,"At line no : %d program : unit\n",line_count);
			
			fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
			$$ = new SymbolInfo();
			$$->set_symbol_name($1->get_symbol_name());
		}
		;
	
unit: var_declaration
	{
		fprintf(logout,"At line no : %d unit : var_declaration\n",line_count);
		
		fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		$$ = new SymbolInfo();
		$$->set_symbol_name($1->get_symbol_name());	
	}
    | func_declaration
	{
		fprintf(logout,"At line no : %d unit : func_declaration\n",line_count);
		
		fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		$$ = new SymbolInfo();
		$$->set_symbol_name($1->get_symbol_name());	
	}
	| func_definition
	{
		fprintf(logout,"At line no : %d unit : func definition\n",line_count);
		
		fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		$$ = new SymbolInfo();
		$$->set_symbol_name($1->get_symbol_name());	
	}
	;
     
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
		{
			fprintf(logout,"At line no : %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);

			$$ = new SymbolInfo();		
			string s = $1->get_symbol_name()+$2->get_symbol_name()+"("+$4->get_symbol_name()+");\n";
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			//$$->set_symbol_type($1->get_symbol_type());
			
			SymbolInfo* symb = symbolTable.lookUp($2->get_symbol_name());

		
			if(symb == NULL)
			{
				//cout<<"hi(parameter)"<<endl;
				
				SymbolInfo* symb = new SymbolInfo();
				
				symb->set_symbol_name($2->get_symbol_name());
				symb->set_symbol_type($1->get_symbol_type());
				symb->set_symbol_class("FUNCTION");
				//symbolTable.insert(symb);

				int check_error = 0;
				for(int i=0;i<parameter_list_vector.size();i++)
				{
					if(parameter_list_vector[i].first == "VOID")
					{
						fprintf(errorout,"Error at line no : %d  Function parameter can't be void\n\n",line_count);
						error_count++;
						check_error = 1;
					}
					
				}
				if(check_error == 0)
				{
					symb->is_function_declared = true;
					for(int i=0;i<parameter_list_vector.size();i++)
					{
						symb->para_list.push_back(make_pair(parameter_list_vector[i].first,parameter_list_vector[i].second));
					}
					symbolTable.insert(symb);
				}
				parameter_list_vector.clear();
			}
			else 
			{
				if(symb->get_symbol_class() == "FUNCTION")
				{
					//return type mismatch
					if(symb->get_symbol_type() != $1->get_symbol_type())
					{
						fprintf(errorout,"Error at line no : %d  Function Return Type Mismatch\n\n",line_count);
						error_count++;
					}
					if(parameter_list_vector.size() == symb->para_list.size())
					{
						for(int i=0;i<parameter_list_vector.size();i++)
						{
							if(parameter_list_vector[i].first != symb->para_list[i].first)
							{
								fprintf(errorout,"Error at line no : %d  Function Parameter Mismatch\n\n",line_count);
								error_count++;	
							}
						}
					}
					else if(symb->para_list.size() != parameter_list_vector.size())
					{
						fprintf(errorout,"Error at line no : %d  Conflict in number of parameters of function : %s \n\n",line_count,symb->get_symbol_name().c_str());
						error_count++;

					}
					
					for(int i=0;i<parameter_list_vector.size();i++)
					{
						if(parameter_list_vector[i].first == "VOID")
						{
							fprintf(errorout,"Error at line no : %d  Function parameter can't be void\n\n",line_count);
							error_count++;
						}
					}
					parameter_list_vector.clear();
				}
				else
				{
					fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
					error_count++;
				}
			}

		}
		| type_specifier ID LPAREN RPAREN SEMICOLON //parameter list empty
		{
			fprintf(logout,"At line no : %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
			
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+$2->get_symbol_name()+"();\n";
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());
			SymbolInfo* symb = symbolTable.lookUp($2->get_symbol_name());
			if(symb == NULL)
			{
				SymbolInfo* symb = new SymbolInfo();
				symb->is_function_declared = true;
				symb->set_symbol_name($2->get_symbol_name());
				symb->set_symbol_type($1->get_symbol_type());
				symb->set_symbol_class("FUNCTION");

				symbolTable.insert(symb);
				//confusion
				parameter_list_vector.clear();
			}
			else 
			{
				if(symb->get_symbol_class() == "FUNCTION")
				{
					if(symb->get_symbol_type() != $1->get_symbol_type())
					{
						fprintf(errorout,"Error at line no : %d  Function Return Type Mismatch\n\n",line_count);
						error_count++;
					}
					if(parameter_list_vector.size() == symb->para_list.size())
					{
						for(int i=0;i<parameter_list_vector.size();i++)
						{
							if(parameter_list_vector[i].first != symb->para_list[i].first)
							{
								fprintf(errorout,"Error at line no : %d  Function Parameter Mismatch\n\n",line_count);
								error_count++;	
							}
						}
					}
					else if(symb->para_list.size() != parameter_list_vector.size())
					{
						fprintf(errorout,"Error at line no : %d  Conflict in number of parameters of function : %s \n\n",line_count,symb->get_symbol_name().c_str());
						error_count++;

					}
					parameter_list_vector.clear();
				}
				else
				{
					fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
					error_count++;
				}			
			}
			
		}
		;
		 
func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement
			{
				fprintf(logout,"At line no : %d func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+$2->get_symbol_name()+"("+$4->get_symbol_name()+")\n"+$6->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());


				SymbolInfo* symb = symbolTable.lookUp($2->get_symbol_name());

				if(symb == NULL) //function not found
				{
					SymbolInfo* symb = new SymbolInfo();
					symb->set_symbol_name($2->get_symbol_name());
					symb->set_symbol_type($1->get_symbol_type());
					symb->set_symbol_class("FUNCTION");
					symb->is_function_defined = true;
					symb->is_function_declared = true;

					int check_error = 0;
					for(int i=0;i<parameter_list_vector.size();i++)
					{
						if(parameter_list_vector[i].first == "VOID")
						{
							fprintf(errorout,"Error at line no : %d  Function parameter can't be void\n\n",line_count);
							error_count++;
							check_error = 1;
						}
					}
					if(check_error == 0)
					{
						for(int i=0;i<parameter_list_vector.size();i++)
						{
							symb->para_list.push_back(make_pair(parameter_list_vector[i].first,parameter_list_vector[i].second));
						}
						symbolTable.insert(symb);
					}

					parameter_list_vector.clear();
				}
				else
				{
					if(symb->get_symbol_class() == "FUNCTION")
					{
						//previously not defined
						if(symb->is_function_defined == false && symb->is_function_declared == true)
						{
							int check_error = 0;
							if(symb->get_symbol_type() != $1->get_symbol_type())
							{
								fprintf(errorout,"Error at line no : %d  Function Return Type Mismatch\n\n",line_count);
								error_count++;
								check_error = 1;
							}
							if(symb->para_list.size() != parameter_list_vector.size())
							{
								fprintf(errorout,"Error at line no : %d  Conflict in number of parameters of function : %s \n\n",line_count,symb->get_symbol_name().c_str());
								error_count++;
								check_error = 1;
							}
							else if(parameter_list_vector.size() == symb->para_list.size())
							{
								for(int i=0;i<parameter_list_vector.size();i++)
								{
									if(parameter_list_vector[i].first != symb->para_list[i].first)
									{
										fprintf(errorout,"Error at line no : %d  Function Parameter Mismatch\n\n",line_count);
										error_count++;
										check_error = 1;	
									}
								}
							}
					
							for(int i=0;i<parameter_list_vector.size();i++)
							{
								if(parameter_list_vector[i].first == "VOID")
								{
									fprintf(errorout,"Error at line no : %d  Function parameter can't be void\n\n",line_count);
									error_count++;
									check_error = 1;
								}
							}
							

							if(check_error == 0)
							{
								symbolTable.lookUp($2->get_symbol_name())->is_function_defined = true;
							}

						}
						else if(symb->is_function_defined == true)
						{
							fprintf(errorout,"Error at line no : %d  Function already defined.\n\n",line_count);
							error_count++;
						}	
						parameter_list_vector.clear();
				
					}
					else
					{
						fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
						error_count++;
					}
					
				}
			}
			| type_specifier ID LPAREN RPAREN compound_statement
			{
				fprintf(logout,"At line no : %d func_definition : type_specifier ID LPAREN RPAREN compound_statement\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+$2->get_symbol_name()+"()\n"+$5->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());


				SymbolInfo* symb = symbolTable.lookUp($2->get_symbol_name());

				if(symb == NULL) //function not found
				{
					SymbolInfo* symb = new SymbolInfo();
					symb->set_symbol_name($2->get_symbol_name());
					symb->set_symbol_type($1->get_symbol_type());
					symb->set_symbol_class("FUNCTION");
					symb->is_function_defined = true;
					symb->is_function_declared = true;

					symbolTable.insert(symb);

					parameter_list_vector.clear();
				}
				else
				{
					if(symb->get_symbol_class() == "FUNCTION")
					{
						//previously not defined
						if(symb->is_function_defined == false && symb->is_function_declared == true)
						{
							int check_error = 0;
							if(symb->get_symbol_type() != $1->get_symbol_type())
							{
								fprintf(errorout,"Error at line no : %d  Function Return Type Mismatch\n\n",line_count);
								error_count++;
								check_error = 1;
							}
							if(symb->para_list.size() != parameter_list_vector.size())
							{
								fprintf(errorout,"Error at line no : %d  Conflict in number of parameters of function : %s \n\n",line_count,symb->get_symbol_name().c_str());
								error_count++;
								check_error = 1;
							}
							if(parameter_list_vector.size() == symb->para_list.size())
							{
								for(int i=0;i<parameter_list_vector.size();i++)
								{
									if(parameter_list_vector[i].first != symb->para_list[i].first)
									{
										fprintf(errorout,"Error at line no : %d  Function Parameter Mismatch\n\n",line_count);
										error_count++;
										check_error = 1;	
									}
								}
							}
					
							for(int i=0;i<parameter_list_vector.size();i++)
							{
								if(parameter_list_vector[i].first == "VOID")
								{
									fprintf(errorout,"Error at line no : %d  Function parameter can't be void\n\n",line_count);
									error_count++;
									check_error = 1;
								}
							}
							
							if(check_error == 0)
							{
								symbolTable.lookUp($2->get_symbol_name())->is_function_defined = true;
							}

						}
						else if(symb->is_function_defined == true)
						{
							fprintf(errorout,"Error at line no : %d  Function already defined.\n\n",line_count);
							error_count++;
						}	
						parameter_list_vector.clear();
						
					}
					else
					{
						fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
						error_count++;
					}
					
				}
				
			}
			;				


parameter_list: parameter_list COMMA type_specifier ID
			{
				fprintf(logout,"At line no : %d parameter_list : parameter_list COMMA type_specifier ID\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+","+$3->get_symbol_name()+$4->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair($3->get_symbol_type(),$4->get_symbol_name()));


			}
			| parameter_list COMMA type_specifier
			{
				fprintf(logout,"At line no : %d parameter_list : parameter_list COMMA type_specifier\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+","+$3->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair($3->get_symbol_type(),"NIL"));
			}
			| type_specifier ID
			{
				fprintf(logout,"At line no : %d parameter_list : type_specifier ID\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+$2->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair($1->get_symbol_type(),$2->get_symbol_name()));
			}
			| type_specifier
			{
				fprintf(logout,"At line no : %d parameter_list : type_specifier\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair($1->get_symbol_type(),"NIL"));

			}
			;

 		
compound_statement: LCURL{
					symbolTable.enterScope(10);

					for(int i=0;i<parameter_list_vector.size();i++)
					{
						SymbolInfo* symb = new SymbolInfo();
						symb->set_symbol_type(parameter_list_vector[i].first);
						symb->set_symbol_name(parameter_list_vector[i].second);
						symb->set_symbol_class("VARIABLE");
						symbolTable.insert(symb);
					}
				} 
				statements RCURL{
				fprintf(logout,"At line no : %d compound_statement : LCURL statements RCURL\n",line_count);

				$$ = new SymbolInfo();	
				string s = "{\n"+$3->get_symbol_name()+"\n}\n";
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				
				symbolTable.printAll();
				symbolTable.exitScope();
			}
 		    | LCURL RCURL
			{
				fprintf(logout,"At line no : %d compound_statement : LCURL RCURL\n",line_count);
				$$ = new SymbolInfo();
				string s = "{}\n";
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

			}
 		    ;

var_declaration: type_specifier declaration_list SEMICOLON
		{
			fprintf(logout,"At line no : %d var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+$2->get_symbol_name()+";";
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());


			for(int i=0;i<declaration_list_vector.size();i++)
			{
				declaration_list_vector[i]->set_symbol_type($1->get_symbol_type());
					
			}

			for(int i=0;i<declaration_list_vector.size();i++)
			{
				declaration_list_vector[i]->set_symbol_type($1->get_symbol_type());
			}

			for(int i=0;i<declaration_list_vector.size();i++)
			{
				if(declaration_list_vector[i]->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Variable/Array type can't be void\n\n",line_count);
					error_count++;
					continue;
				}
				else if(symbolTable.insert(declaration_list_vector[i]) == true)
				{

				}
				else if(symbolTable.insert(declaration_list_vector[i]) == false)
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d  Multiple declaration of variable/array %s\n\n",line_count,declaration_list_vector[i]->get_symbol_name().c_str());
				}
			}
			declaration_list_vector.clear();

		}
		;
 		 
type_specifier: INT
		{
			fprintf(logout,"At line no : %d type_specifier : INT\n",line_count);
			
			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("int ");
			s->set_symbol_type("INT");
			$$ = s;
			fprintf(logout,"%s\n\n",$$->get_symbol_name().c_str());
			
		}
 		| FLOAT
		{
			fprintf(logout,"At line no : %d type_specifier : FLOAT\n",line_count);

			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("float ");
			s->set_symbol_type("FLOAT");
			$$ = s;
			fprintf(logout,"%s \n\n",$$->get_symbol_name().c_str());
		}
		| VOID
		{
			fprintf(logout,"At line no : %d type_specifier : VOID\n",line_count);
			
			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("void ");
			s->set_symbol_type("VOID");
			$$ = s;
			fprintf(logout,"%s \n\n",$$->get_symbol_name().c_str());
		}
 		;
 		
declaration_list: declaration_list COMMA ID
		{
			fprintf(logout,"At line no : %d declaration_list : declaration_list COMMA ID\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+","+$3->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			
			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name($3->get_symbol_name());
			symb->set_symbol_class("VARIABLE"); 

			declaration_list_vector.push_back(symb);

				
		}
		| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
		{
			fprintf(logout,"At line no : %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+","+$3->get_symbol_name()+"["+$5->get_symbol_name()+"]";
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_class("ARRAY");
			symb->set_symbol_name($3->get_symbol_name());
			symb->ara_size = atoi($5->get_symbol_name().c_str());

			declaration_list_vector.push_back(symb);


		}
		| ID
		{
			fprintf(logout,"At line no : %d declaration_list : ID\n",line_count);
			
			$$ = new SymbolInfo();
			$$->set_symbol_name($1->get_symbol_name());
			fprintf(logout,"%s\n\n",$$->get_symbol_name().c_str());
			

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name($1->get_symbol_name());
			symb->set_symbol_class("VARIABLE"); 

			declaration_list_vector.push_back(symb);	
			
		}
		| ID LTHIRD CONST_INT RTHIRD
		{
			fprintf(logout,"At line no : %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n",line_count);
			
			$$ = new SymbolInfo();
			$$->set_symbol_name($1->get_symbol_name()+"["+$3->get_symbol_name()+"]");
			fprintf(logout,"%s\n\n",$$->get_symbol_name().c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_class("ARRAY");
			symb->set_symbol_name($1->get_symbol_name());
			symb->ara_size = atoi($3->get_symbol_name().c_str());

			declaration_list_vector.push_back(symb);
		}
		;

statements: statement
		{
			fprintf(logout,"At line no : %d statements : statement\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
		}
		| statements statement
		{
				fprintf(logout,"At line no : %d statements : statements statement\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+"\n"+$2->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());
		}
		;
	   
statement: var_declaration
		{
			fprintf(logout,"At line no : %d statement : var_declaration\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
		}
		| expression_statement
		{
			fprintf(logout,"At line no : %d statement : expression_statement\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
		}
		| compound_statement
		{
			fprintf(logout,"At line no : %d statement : compound_statement\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
		}
		| FOR LPAREN expression_statement expression_statement expression RPAREN statement
		{
			fprintf(logout,"At line no : %d statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);

			$$ = new SymbolInfo();
			string s = "for("+$3->get_symbol_name()+" "+$4->get_symbol_name()+" "+$5->get_symbol_name()+")\n"+$7->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			if($3->get_symbol_type() == "VOID" || $4->get_symbol_type() == "VOID" || $5->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			} 
		}
		| IF LPAREN expression RPAREN statement %prec ELSE_LOWER 
		{
			fprintf(logout,"At line no : %d statement : IF LPAREN expression RPAREN statement\n",line_count);

			$$ = new SymbolInfo();
			string s = "if("+$3->get_symbol_name()+")\n"+$5->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			
			if($3->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}
		}
		| IF LPAREN expression RPAREN statement ELSE statement
		{
			fprintf(logout,"At line no : %d statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);

			$$ = new SymbolInfo();
			string s = "if("+$3->get_symbol_name()+")\n"+"else\n"+$7->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			if($3->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}
		}
		| WHILE LPAREN expression RPAREN statement
		{
			fprintf(logout,"At line no : %d statement : WHILE LPAREN expression RPAREN statement\n",line_count);

			$$ = new SymbolInfo();
			string s = "while("+$3->get_symbol_name()+")\n"+$5->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			if($3->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}		
		}
		| PRINTLN LPAREN ID RPAREN SEMICOLON
		{
			fprintf(logout,"At line no : %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n",line_count);

			$$ = new SymbolInfo();
			string s = "\n ("+$3->get_symbol_name()+");";
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
		}
		| RETURN expression SEMICOLON
		{
			fprintf(logout,"At line no : %d statement : RETURN expression SEMICOLON\n",line_count);

			$$ = new SymbolInfo();
			string s ="return "+$2->get_symbol_name()+";";
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			if($2->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type mismatch(return type can't be void) \n\n",line_count);
				error_count++;
			}

		}
		;
	  
expression_statement: SEMICOLON
			{
				fprintf(logout,"At line no : %d expression_statement : SEMICOLON\n",line_count);

				$$ = new SymbolInfo();
				$$->set_symbol_name(";");
				fprintf(logout,"; \n\n");	
			}			
			| expression SEMICOLON
			{
				fprintf(logout,"At line no : %d expression_statement : expression SEMICOLON\n",line_count);
				
				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+";";
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

			} 
			;
	  
variable: ID
		{
			fprintf(logout,"At line no : %d variable : ID\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* check = symbolTable.lookUp($1->get_symbol_name());
			
			if(check != NULL)
			{
				$$->set_symbol_type(check->get_symbol_type());
				if(check->get_symbol_class() != "VARIABLE")
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d   Type mismatch(%s is not a variable)\n\n",line_count,check->get_symbol_name().c_str());
				}
			}
			else if(check == NULL)
			{
				error_count++;
				fprintf(errorout,"Error at line no : %d  Undeclared variable %s\n\n",line_count,$1->get_symbol_name().c_str());
				$$->set_symbol_type("INT");
			}
			//seg fault
			
			
			
		}
		| ID LTHIRD expression RTHIRD
		{
			fprintf(logout,"At line no : %d variable : ID LTHIRD expression RTHIRD\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+"["+$3->get_symbol_name()+"]";
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* check = symbolTable.lookUp($1->get_symbol_name());

			if(check != NULL)
			{
				$$->set_symbol_type(check->get_symbol_type());
				if($3->get_symbol_type() != "INT")
				{
					error_count++;
					fprintf(errorout,"Error at line : %d   Non-integer Array Index\n\n",line_count);

				}
				//seg fault
				else if(check->get_symbol_class() != "ARRAY")
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d   Type mismatch(%s is not an array)\n\n",line_count,check->get_symbol_name().c_str());
				}
				/*cout<<$3->get_symbol_name()<<endl;
				int size = atoi($3->get_symbol_name().c_str());
				cout<<check->ara_size<<endl;
				if(size > check->ara_size)
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d   Array index out of bound\n\n",line_count);
				}*/
			}
			else if(check == NULL)
			{	
				$$->set_symbol_type("INT");
				error_count++;
				fprintf(errorout,"Error at line no : %d  Undeclared array %s\n\n",line_count,$1->get_symbol_name().c_str());
			}
				
		} 
		;


expression: logic_expression
		{
			fprintf(logout,"At line no : %d expression : logic_expression\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());		
		}	
		| variable ASSIGNOP logic_expression
		{
			fprintf(logout,"At line no : %d expression : variable ASSIGNOP logic_expression\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+" = "+$3->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());


			if($1->get_symbol_type() != $3->get_symbol_type())
			{
				fprintf(errorout,"Error at line no : %d  Type mismatch(ASSIGNOP)\n\n",line_count);
				error_count++;
			}

			if($3->get_symbol_type() == "VOID")
			{	
				fprintf(errorout,"Error at line no : %d   Void type can't be assigned to a variable\n\n",line_count);
				error_count++;
			}
			else if($1->get_symbol_type()=="INT" && $3->get_symbol_type()=="FLOAT")
			{
				fprintf(errorout,"Error at line no : %d  Floating point number is assigned to an integer type variable\n\n",line_count);
				error_count++;
				$$->set_symbol_type("INT");
			}
			else if($1->get_symbol_type()=="FLOAT" && $3->get_symbol_type()=="INT")
			{
				fprintf(errorout,"Error at line no : %d  Integer number is assigned to an floating point type variable\n\n",line_count);
				error_count++;
				$$->set_symbol_type("FLOAT");
			}
			else
			{
				$$->set_symbol_type("INT");
			}		
		} 	
		;
			
logic_expression: rel_expression
			{
				fprintf(logout,"At line no : %d logic_expression : rel_expression\n",line_count);
			
				$$ = new SymbolInfo();
				string s = $1->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				$$->set_symbol_type($1->get_symbol_type());

					
			}
			| rel_expression LOGICOP rel_expression 	
			{
				fprintf(logout,"At line no : %d logic_expression : rel_expression LOGICOP rel_expression\n",line_count);
			
				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+" "+$2->get_symbol_name()+" "+$3->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				$$->set_symbol_type("INT");

				if($1->get_symbol_type()=="INT" && $3->get_symbol_type()=="FLOAT")
				{
					fprintf(errorout,"Error at line no : %d  Type conversion to integer(LOGICOP)\n\n",line_count);
					error_count++;
				}
				else if($1->get_symbol_type()=="FLOAT" && $3->get_symbol_type()=="INT")
				{
					fprintf(errorout,"Error at line no : %d  Type conversion to integer(LOGICOP)\n\n",line_count);
					error_count++;
				}
			}
			;
			
rel_expression: simple_expression 
		{
			fprintf(logout,"At line no : %d rel_expression : simple_expression\n",line_count);
		
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());
		}
		| simple_expression RELOP simple_expression
		{
			fprintf(logout,"At line no : %d rel_expression : simple_expression RELOP simple_expression\n",line_count);
		
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+" "+$2->get_symbol_name()+" "+$3->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type("INT");

			if($1->get_symbol_type()=="INT" && $3->get_symbol_type()=="FLOAT")
			{
				fprintf(errorout,"Error at line no : %d  Type conversion to integer(RELOP)\n\n",line_count);
				error_count++;
				
			}
			else if($1->get_symbol_type()=="FLOAT" && $3->get_symbol_type()=="INT")
			{
				fprintf(errorout,"Error at line no : %d  Type conversion to integer(RELOP)\n\n",line_count);
				error_count++;
			}
		}	
		;
				
simple_expression: term 
			{
				fprintf(logout,"At line no : %d simple_expression : term\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				$$->set_symbol_type($1->get_symbol_type());
			}
			| simple_expression ADDOP term
			{
				fprintf(logout,"At line no : %d simple_expression : simple_expression ADDOP term\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+" "+$2->get_symbol_name()+" "+$3->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());
				
				if($1->get_symbol_type() == "VOID" || $3->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Type mismatch(Void type can't be used in ADD operations)\n\n",line_count);
					error_count++;
					$$->set_symbol_type("INT");
				}
				if($1->get_symbol_type() == "FLOAT" || $3->get_symbol_type() == "FLOAT")
				{
					$$->set_symbol_type("FLOAT");	
				}
				else
				{
					$$->set_symbol_type("INT");
				}
								
			} 
			;
					
	term:	unary_expression
		{
			fprintf(logout,"At line no : %d term : unary_expression\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());
		
		}
		|  term MULOP unary_expression
		{
			fprintf(logout,"At line no : %d term : term MULOP unary_expression\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+" "+$2->get_symbol_name()+" "+$3->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());


			if($1->get_symbol_type() == "VOID" || $3->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d  Type mismatch(Void type can't be used in MUL operations)\n\n",line_count);
				error_count++;
				//confused
				$$->set_symbol_type("INT");
			}
			else if($2->get_symbol_name() == "%")
			{
				if($1->get_symbol_type() == "FLOAT" || $3->get_symbol_type() == "FLOAT")
				{
					fprintf(errorout,"Error at line no : %d  Both operand of modulus operator should be integer. \n\n",line_count);
					$$->set_symbol_type("INT");
					error_count++;
				}
			} 
			else
			{
				if($1->get_symbol_type() == "FLOAT" || $3->get_symbol_type() == "FLOAT")
				{
					//cout<<"hi float"<<endl;
					$$->set_symbol_type("FLOAT");
				}
				else if($1->get_symbol_type() == "INT" && $3->get_symbol_type() == "INT")
				{
					//cout<<"hi int"<<endl;
					$$->set_symbol_type("INT");
				}
			}
		}
		;

unary_expression: ADDOP unary_expression  
			{
				fprintf(logout,"At line no : %d unary_expression : ADDOP unary_expression\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+$2->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());
				
				if($2->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Type mismatch(ADDOP)\n\n",line_count);
					error_count++;
					$$->set_symbol_type("INT");
				}
				else
				{
					$$->set_symbol_type($2->get_symbol_type());
				}
				
			}
			| NOT unary_expression 
			{
				fprintf(logout,"At line no : %d unary_expression : NOT unary_expression\n",line_count);

				$$ = new SymbolInfo();
				string s = "!"+$2->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				if($2->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Type mismatch(NOT)\n\n",line_count);
					error_count++;
					$$->set_symbol_type("INT");
				}
				else
				{
					$$->set_symbol_type($2->get_symbol_type());
				}
			}
			| factor 
			{
				fprintf(logout,"At line no : %d unary_expression : factor\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name();
				$$->set_symbol_name(s);
				fprintf(logout,"%s\n\n",s.c_str());

				
				$$->set_symbol_type($1->get_symbol_type());

			}
			;
	
factor: variable
		{
			fprintf(logout,"At line no : %d factor : variable\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());
		}
		| ID LPAREN argument_list RPAREN
		{
			fprintf(logout,"At line no : %d factor : ID LPAREN argument_list RPAREN\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+"("+$3->get_symbol_name()+")";
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());
	
			SymbolInfo* symb = symbolTable.lookUp($1->get_symbol_name());

			/*cout<<symb->get_symbol_name()<<endl;
			for(int i=0;i<argument_list_vector.size();i++)
			{
				cout<<argument_list_vector[i]->get_symbol_name()<<endl;
			}*/


			if(symb == NULL)
			{
				fprintf(errorout,"Error at line no : %d  Function not defined or declared before\n\n",line_count);
				error_count++;
				//confusion
				$$->set_symbol_type("INT");
			}
			else if(symb->get_symbol_class() == "FUNCTION")
			{
				$$->set_symbol_type(symb->get_symbol_type());
				//if(symb->is_function_defined == true)
				//{
					if(symb->para_list.size() != argument_list_vector.size())
					{
						fprintf(errorout,"Error at line no : %d  Invalid number of arguments in the function\n\n",line_count);
						error_count++;
					}
					else
					{
						for(int i=0;i<argument_list_vector.size();i++)
						{
							if(argument_list_vector[i]->get_symbol_type() != symb->para_list[i].first)
							{
								fprintf(errorout,"Error at line no : %d  Function Argument Type Mismatch\n\n",line_count);
								error_count++;
							}		
						}
					}

				//}
				/*else
				{
					fprintf(errorout,"Error at line no : %d  Function should be defined before calling\n\n",line_count);
					error_count++;
				}*/
				
				argument_list_vector.clear();
			}
			else if(symb->get_symbol_class() != "FUNCTION")
			{
				fprintf(errorout,"Error at line no : %d  It's not a function\n\n",line_count);
				error_count++;
			}
		}
		| LPAREN expression RPAREN
		{
			fprintf(logout,"At line no : %d factor : LPAREN expression RPAREN\n",line_count);

			$$ = new SymbolInfo();
			string s = "("+$2->get_symbol_name()+")";
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($2->get_symbol_type());
		}
		| CONST_INT
		{
			fprintf(logout,"At line no : %d factor : CONST_INT\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type("INT");		
		} 
		| CONST_FLOAT
		{
			fprintf(logout,"At line no : %d factor : CONST_FLOAT\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type("FLOAT");
		}
		| variable INCOP
		{
			fprintf(logout,"At line no : %d factor : variable INCOP\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+"++";
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());
		} 
		| variable DECOP
		{
			fprintf(logout,"At line no : %d factor : variable DECOP\n",line_count);
		    
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+"--";
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());
		}
		;
	
argument_list: arguments
		{
			fprintf(logout,"At line no : %d argument_list : arguments\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

		}
	    |	
		{ 
			$$ = new SymbolInfo(); 
			fprintf(logout,"At line no : %d  argument_list : (empty) \n\n",line_count);
			$$->set_symbol_name("");
		}  
		;
	
arguments: arguments COMMA logic_expression
		{
			fprintf(logout,"At line no : %d arguments : arguments COMMA logic_expression\n",line_count);
			
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+","+$3->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name($3->get_symbol_name());
			symb->set_symbol_type($3->get_symbol_type());
			symb->set_symbol_class("VARIABLE");//argument = variable

			
			argument_list_vector.push_back(symb);
		}
		| logic_expression
		{
			fprintf(logout,"At line no : %d arguments : logic_expression\n",line_count);
		    
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name($1->get_symbol_name());
			symb->set_symbol_type($1->get_symbol_type());
			symb->set_symbol_class("VARIABLE");

			argument_list_vector.push_back(symb);
		}
		;
 		   

%%
int main(int argc,char *argv[])
{

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}
	
	errorout = fopen("1605084_error.txt","w");
    logout = fopen("1605084_log.txt","w");

	yyin=fp;
	symbolTable.enterScope(10);
	yyparse();

	fprintf(logout,"\n\nSymbol Table :\n\n");
	symbolTable.printAll();
	fprintf(logout,"\nTotal lines : %d\n",line_count);
	fprintf(logout,"\nTotal errros : %d\n",error_count);
	fprintf(errorout,"\nTotal errros : %d\n",error_count);
	fclose(fp);
	fclose(errorout);
	fclose(logout);
	
	return 0;
}

