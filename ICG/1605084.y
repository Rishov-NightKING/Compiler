%{
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

int label_count = 0;
int temp_count = 0;

SymbolTable symbolTable;

vector<SymbolInfo*>declaration_list_vector;
vector<pair<string,string>>parameter_list_vector;
vector<SymbolInfo*>argument_list_vector;

vector<string> variable_declaration;
vector<string> func_variable_declaration;
vector<pair<string,int>> array_declarartion;//variable/function/array
string currentFunction;

void yyerror(const char *s)
{
 	fprintf(errorout,"Error at line no %d :  %s\n\n",line_count,s);
	error_count++;
}

char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", label_count);
	label_count++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", temp_count);
	temp_count++;
	strcat(t,b);
	return t;
}

void optimizeCode(FILE *asmfile);
void chomp( string &s);

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
		//fprintf(logout,"At line no : %d start : program\n",line_count);

		//fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		$$ = new SymbolInfo();
		$$->set_symbol_name($1->get_symbol_name());

		if(error_count == 0)
		{
			string temp_code = "";
			temp_code += ".MODEL SMALL\n";
			temp_code += ".STACK 100H\n";
			temp_code += ".DATA \n";

			for(int i=0;i<variable_declaration.size();i++)
			{
				temp_code += variable_declaration[i]+" dw ?\n";
			}

			for(int i=0;i<array_declarartion.size();i++)
			{
				temp_code += array_declarartion[i].first+" dw "+to_string(array_declarartion[i].second)+" dup(?)\n";
			}

			$1->code = temp_code + ".CODE\n"+$1->code;
			
			$1->code += "OUTDEC PROC\n";
			$1->code += "PUSH AX\n";
			$1->code += "PUSH BX\n";
			$1->code += "PUSH CX\n";
			$1->code += "PUSH DX\n";
			$1->code += "CMP AX, 0\n";
			$1->code += "JGE BEGIN\n";
			$1->code += "PUSH AX\n";
			$1->code += "MOV DL, '-'\n";
			$1->code += "MOV AH, 2\n";
			$1->code += "INT 21H\n";
			$1->code += "POP AX\n";
			$1->code += "NEG AX\n\n";

			$1->code += "BEGIN:\n";
			$1->code += "XOR CX, CX\n";
			$1->code += "MOV BX, 10\n\n";

			$1->code += "REPEATATION:\n";
			$1->code += "XOR DX, DX\n";
			$1->code += "DIV BX\n";
			$1->code += "PUSH DX\n";
			$1->code += "INC CX\n";
			$1->code += "OR AX, AX\n";
			$1->code += "JNE REPEATATION\n";
			$1->code += "MOV AH, 2\n\n";

			$1->code += "LOOP_PRINT:\n";
			$1->code += "POP DX\n";
			$1->code += "ADD DL, 30H\n";
			$1->code += "INT 21H\n";
			$1->code += "LOOP LOOP_PRINT\n\n";

			$1->code += "MOV AH, 2\n";
			$1->code += "MOV DL, 10\n";
			$1->code += "INT 21H\n\n";

			$1->code += "MOV DL, 13\n";
			$1->code += "INT 21H\n\n";

			$1->code += "POP DX\n";
			$1->code += "POP CX\n";
			$1->code += "POP BX\n";
			$1->code += "POP AX\n";

			$1->code += "RET\n";
			$1->code += "OUTDEC ENDP\n";
			$1->code += "END MAIN\n\n";

			FILE *asmfile = fopen("1605084_code.asm","w");
			fprintf(asmfile,"%s\n",$1->code.c_str());
			fclose(asmfile);
			//add optimization later
			asmfile = fopen("1605084_code.asm","r");
			optimizeCode(asmfile);
		}
	}
	;

program: program unit 
		{
			//fprintf(logout,"At line no : %d program : program unit\n",line_count);
			
			//fprintf(logout,"%s\n%s\n\n",$1->get_symbol_name().c_str(),$2->get_symbol_name().c_str());
			$$ = new SymbolInfo();
			$$->set_symbol_name($1->get_symbol_name().append($2->get_symbol_name()));
			$$->code = $1->code + $2->code;
		}
		| unit
		{
			//fprintf(logout,"At line no : %d program : unit\n",line_count);
			
			//fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
			$$ = new SymbolInfo();
			$$->set_symbol_name($1->get_symbol_name());
			$$->code = $1->code;
		}
		;
	
unit: var_declaration
	{
		//fprintf(logout,"At line no : %d unit : var_declaration\n",line_count);
		
		//fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		$$ = new SymbolInfo();
		$$->set_symbol_name($1->get_symbol_name());	

		$$->code = $1->code;
	}
    | func_declaration
	{
		//fprintf(logout,"At line no : %d unit : func_declaration\n",line_count);
		
		//fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		$$ = new SymbolInfo();
		$$->set_symbol_name($1->get_symbol_name());	
		$$->code = $1->code;
	}
	| func_definition
	{
		//fprintf(logout,"At line no : %d unit : func definition\n",line_count);
		
		//fprintf(logout,"%s\n\n",$1->get_symbol_name().c_str());
		$$ = new SymbolInfo();
		$$->set_symbol_name($1->get_symbol_name());	
		$$->code = $1->code;
	}
	;
     
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
		{
			//fprintf(logout,"At line no : %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);

			$$ = new SymbolInfo();		
			string s = $1->get_symbol_name()+$2->get_symbol_name()+"("+$4->get_symbol_name()+");\n";
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

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
						symb->para_list.push_back(make_pair(parameter_list_vector[i].first,parameter_list_vector[i].second+to_string(symbolTable.getNextScopeTableID())));
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
			//fprintf(logout,"At line no : %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
			
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+$2->get_symbol_name()+"();\n";
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

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
		 
func_definition: type_specifier ID LPAREN parameter_list RPAREN
			{
				
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
							symb->para_list.push_back(make_pair(parameter_list_vector[i].first,parameter_list_vector[i].second+to_string(symbolTable.getNextScopeTableID())));
						}
						symbolTable.insert(symb);
						currentFunction = $2->get_symbol_name();
						//cout<<"Func definition :"<<currentFunction<<endl;
						variable_declaration.push_back(currentFunction+"_return");
					}
					//parameter_list_vector.clear();
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
								currentFunction = $2->get_symbol_name();
								//cout<<"Func definition :"<<currentFunction<<endl;
								variable_declaration.push_back(currentFunction+"_return");		
							}

						}
						else if(symb->is_function_defined == true)
						{
							fprintf(errorout,"Error at line no : %d  Function already defined.\n\n",line_count);
							error_count++;
						}	
						//parameter_list_vector.clear();
				
					}
					else
					{
						fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
						error_count++;
					}
				}
				 
			
			}compound_statement{

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+$2->get_symbol_name()+"("+$4->get_symbol_name()+")\n"+$7->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				$$->code = $2->get_symbol_name()+" PROC\n";
				$$->set_symbol_type($1->get_symbol_type());


				if($2->get_symbol_name() == "main")
				{
					$$->code += "MOV AX, @DATA\n";
					$$->code += "MOV DS, AX\n";
					$$->code += $7->code;
					$$->code += "LReturn"+currentFunction+":\n";
					$$->code += "MOV AH, 4CH\n";
					$$->code += "INT 21H\n";
				}
				else
				{
					for(int i=0;i<func_variable_declaration.size();i++)
					{
						symbolTable.lookUp($2->get_symbol_name())->func_var_list.push_back(func_variable_declaration[i]);
					}
					func_variable_declaration.clear();
					string temp_code = $$->code;
					temp_code += "PUSH AX\n";
					temp_code += "PUSH BX\n";
					temp_code += "PUSH CX\n";
					temp_code += "PUSH DX\n";

					SymbolInfo* check = symbolTable.lookUp($2->get_symbol_name());
					for(int i=0;i<check->para_list.size();i++)
					{
						temp_code += "PUSH "+check->para_list[i].second+"\n";
					}

					for(int i=0;i<check->func_var_list.size();i++)
					{
						temp_code += "PUSH "+check->func_var_list[i]+"\n";
					}
					temp_code += $7->code + "LReturn"+currentFunction+":\n";

					for(int i=check->func_var_list.size()-1;i>-1;i--)
					{
						temp_code += "POP "+check->func_var_list[i]+"\n";
					}
					for(int i=check->para_list.size()-1;i>-1;i--)
					{
						temp_code += "POP "+check->para_list[i].second+"\n";
					}

					temp_code += "POP DX\n";
					temp_code += "POP CX\n";
					temp_code += "POP BX\n";
					temp_code += "POP AX\n";
					temp_code += "RET\n";

					$$->code = temp_code + $2->get_symbol_name()+" ENDP\n";

					
				}
				parameter_list_vector.clear();
	
			}
			| type_specifier ID LPAREN RPAREN 
			{
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
							symb->para_list.push_back(make_pair(parameter_list_vector[i].first,parameter_list_vector[i].second+to_string(symbolTable.getNextScopeTableID())));
						}
						symbolTable.insert(symb);
						currentFunction = $2->get_symbol_name();
						//cout<<"Func definition :"<<currentFunction<<endl;
						variable_declaration.push_back(currentFunction+"_return");
					}
					//parameter_list_vector.clear();
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
								currentFunction = $2->get_symbol_name();
								//cout<<"Func definition :"<<currentFunction<<endl;
								variable_declaration.push_back(currentFunction+"_return");		
							}

						}
						else if(symb->is_function_defined == true)
						{
							fprintf(errorout,"Error at line no : %d  Function already defined.\n\n",line_count);
							error_count++;
						}	
						//parameter_list_vector.clear();
				
					}
					else
					{
						fprintf(errorout,"Error at line no : %d  Variable/array of same name already exits\n\n",line_count);
						error_count++;
					}
				}

			}
			compound_statement{

					$$ = new SymbolInfo();
					string s = $1->get_symbol_name()+$2->get_symbol_name()+"()\n"+$6->get_symbol_name();
					$$->set_symbol_name(s);
					//fprintf(logout,"%s\n\n",s.c_str());

					$$->code = $2->get_symbol_name()+" PROC\n";
					$$->set_symbol_type($1->get_symbol_type());


					if($2->get_symbol_name() == "main")
					{
						$$->code += "MOV AX, @DATA\n";
						$$->code += "MOV DS, AX\n";
						$$->code += $6->code;
						$$->code += "LReturn"+currentFunction+":\n";
						$$->code += "MOV AH, 4CH\n";
						$$->code += "INT 21H\n";
					}
					else
					{
						for(int i=0;i<func_variable_declaration.size();i++)
						{
							symbolTable.lookUp($2->get_symbol_name())->func_var_list.push_back(func_variable_declaration[i]);
						}
						func_variable_declaration.clear();
						string temp_code = $$->code;
						temp_code += "PUSH AX\n";
						temp_code += "PUSH BX\n";
						temp_code += "PUSH CX\n";
						temp_code += "PUSH DX\n";

						SymbolInfo* check = symbolTable.lookUp($2->get_symbol_name());
						for(int i=0;i<check->para_list.size();i++)
						{
							temp_code += "PUSH "+check->para_list[i].second+"\n";
						}

						for(int i=0;i<check->func_var_list.size();i++)
						{
							temp_code += "PUSH "+check->func_var_list[i]+"\n";
						}
						temp_code += $6->code + "LReturn"+currentFunction+":\n";

						for(int i=0;i<check->func_var_list.size();i++)
						{
							temp_code += "POP "+check->func_var_list[i]+"\n";
						}
						for(int i=0;i<check->para_list.size();i++)
						{
							temp_code += "POP "+check->para_list[i].second+"\n";
						}

						temp_code += "POP DX\n";
						temp_code += "POP CX\n";
						temp_code += "POP BX\n";
						temp_code += "POP AX\n";
						temp_code += "RET\n";

						$$->code = temp_code + $2->get_symbol_name()+" ENDP\n";
					}
					parameter_list_vector.clear();
			}
			;				


parameter_list: parameter_list COMMA type_specifier ID
			{
				//fprintf(logout,"At line no : %d parameter_list : parameter_list COMMA type_specifier ID\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+","+$3->get_symbol_name()+$4->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair($3->get_symbol_type(),$4->get_symbol_name()));


			}
			| parameter_list COMMA type_specifier
			{
				//fprintf(logout,"At line no : %d parameter_list : parameter_list COMMA type_specifier\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+","+$3->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair($3->get_symbol_type(),"NIL"));
			}
			| type_specifier ID
			{
				//fprintf(logout,"At line no : %d parameter_list : type_specifier ID\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+$2->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				parameter_list_vector.push_back(make_pair($1->get_symbol_type(),$2->get_symbol_name()));
			}
			| type_specifier
			{
				//fprintf(logout,"At line no : %d parameter_list : type_specifier\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

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

						variable_declaration.push_back(parameter_list_vector[i].second+to_string(symbolTable.getCurrentScopeTableID()));
					}
					//confusion
				} 
				statements RCURL{
				//fprintf(logout,"At line no : %d compound_statement : LCURL statements RCURL\n",line_count);

				$$ = new SymbolInfo();	
				string s = "{\n"+$3->get_symbol_name()+"\n}\n";
				$$->set_symbol_name(s);

				$$->code = $3->code;

				//fprintf(logout,"%s\n\n",s.c_str());

				
				symbolTable.printAll();
				symbolTable.exitScope();
			}
 		    | LCURL RCURL
			{
				//fprintf(logout,"At line no : %d compound_statement : LCURL RCURL\n",line_count);
				$$ = new SymbolInfo();
				string s = "{}\n";
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				symbolTable.enterScope(10);

				//symbolTable.printAll();
				symbolTable.exitScope();

			}
 		    ;

var_declaration: type_specifier declaration_list SEMICOLON
		{
			//fprintf(logout,"At line no : %d var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+$2->get_symbol_name()+";";
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());


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
					if(declaration_list_vector[i]->get_symbol_class() == "ARRAY")
					{
						array_declarartion.push_back(make_pair(declaration_list_vector[i]->get_symbol_name()+to_string(symbolTable.getCurrentScopeTableID()),declaration_list_vector[i]->ara_size));
					}
					else
					{
						variable_declaration.push_back(declaration_list_vector[i]->get_symbol_name()+to_string(symbolTable.getCurrentScopeTableID()));
						func_variable_declaration.push_back(declaration_list_vector[i]->get_symbol_name()+to_string(symbolTable.getCurrentScopeTableID()));
					}
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
			//fprintf(logout,"At line no : %d type_specifier : INT\n",line_count);
			
			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("int ");
			s->set_symbol_type("INT");
			$$ = s;
			//fprintf(logout,"%s\n\n",$$->get_symbol_name().c_str());
			
		}
 		| FLOAT
		{
			//fprintf(logout,"At line no : %d type_specifier : FLOAT\n",line_count);

			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("float ");
			s->set_symbol_type("FLOAT");
			$$ = s;
			//fprintf(logout,"%s \n\n",$$->get_symbol_name().c_str());
		}
		| VOID
		{
			//fprintf(logout,"At line no : %d type_specifier : VOID\n",line_count);
			
			SymbolInfo* s = new SymbolInfo();
			s->set_symbol_name("void ");
			s->set_symbol_type("VOID");
			$$ = s;
			//fprintf(logout,"%s \n\n",$$->get_symbol_name().c_str());
		}
 		;
 		
declaration_list: declaration_list COMMA ID
		{
			//fprintf(logout,"At line no : %d declaration_list : declaration_list COMMA ID\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+","+$3->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			
			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name($3->get_symbol_name());
			symb->set_symbol_class("VARIABLE"); 

			declaration_list_vector.push_back(symb);

				
		}
		| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
		{
			//fprintf(logout,"At line no : %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+","+$3->get_symbol_name()+"["+$5->get_symbol_name()+"]";
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_class("ARRAY");
			symb->set_symbol_name($3->get_symbol_name());
			symb->ara_size = atoi($5->get_symbol_name().c_str());

			declaration_list_vector.push_back(symb);

		}
		| ID
		{
			//fprintf(logout,"At line no : %d declaration_list : ID\n",line_count);
			
			$$ = new SymbolInfo();
			$$->set_symbol_name($1->get_symbol_name());
			//fprintf(logout,"%s\n\n",$$->get_symbol_name().c_str());
			

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name($1->get_symbol_name());
			symb->set_symbol_class("VARIABLE"); 

			declaration_list_vector.push_back(symb);	
			
		}
		| ID LTHIRD CONST_INT RTHIRD
		{
			//fprintf(logout,"At line no : %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n",line_count);
			
			$$ = new SymbolInfo();
			$$->set_symbol_name($1->get_symbol_name()+"["+$3->get_symbol_name()+"]");
			//fprintf(logout,"%s\n\n",$$->get_symbol_name().c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_class("ARRAY");
			symb->set_symbol_name($1->get_symbol_name());
			symb->ara_size = atoi($3->get_symbol_name().c_str());

			declaration_list_vector.push_back(symb);
		}
		;

statements: statement
		{
			//fprintf(logout,"At line no : %d statements : statement\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			$$->code = $1->code;
		}
		| statements statement
		{
				//fprintf(logout,"At line no : %d statements : statements statement\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+"\n"+$2->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				$$->code = $1->code + $2->code;
		}
		;
	   
statement: var_declaration
		{
			//fprintf(logout,"At line no : %d statement : var_declaration\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());
		}
		| expression_statement
		{
			//fprintf(logout,"At line no : %d statement : expression_statement\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());
			$$->code = $1->code;
		}
		| compound_statement
		{
			//fprintf(logout,"At line no : %d statement : compound_statement\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());
			$$->code = $1->code;
		}
		| FOR LPAREN expression_statement expression_statement expression RPAREN statement
		{
			//fprintf(logout,"At line no : %d statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);

			$$ = new SymbolInfo();
			string s = "for("+$3->get_symbol_name()+" "+$4->get_symbol_name()+" "+$5->get_symbol_name()+")\n"+$7->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			if($3->get_symbol_type() == "VOID" || $4->get_symbol_type() == "VOID" || $5->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			} 
			else
			{
				string temp_code = $3->code;

				char *label1 = newLabel();
				char *label2 = newLabel();

				temp_code += string(label1)+":\n";
				temp_code += $4->code;
				temp_code += "MOV AX, "+$4->get_symbol_value()+"\n";
				temp_code += "CMP AX, 0\n";
				temp_code += "JE "+string(label2)+"\n";
				temp_code += $7->code;
				temp_code += $5->code;
				temp_code += string(label2)+":\n";
				$$->code = temp_code;

			}
		}
		| IF LPAREN expression RPAREN statement %prec ELSE_LOWER 
		{
			//fprintf(logout,"At line no : %d statement : IF LPAREN expression RPAREN statement\n",line_count);

			$$ = new SymbolInfo();
			string s = "if("+$3->get_symbol_name()+")\n"+$5->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			
			if($3->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}
			else
			{
				string temp_code = $3->code;
				char *label = newLabel();
				temp_code += "MOV AX, "+$3->get_symbol_value()+"\n";
				temp_code += "CMP AX, 0\n";
				temp_code += "JE "+string(label)+"\n";
				temp_code += $5->code;
				temp_code += string(label)+":\n";
				$$->code = temp_code;
			}
		}
		| IF LPAREN expression RPAREN statement ELSE statement
		{
			//fprintf(logout,"At line no : %d statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);

			$$ = new SymbolInfo();
			string s = "if("+$3->get_symbol_name()+")\n"+"else\n"+$7->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			if($3->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}
			else
			{
				string temp_code = $3->code;
				char *label1 = newLabel();
				char *label2 = newLabel();
				temp_code += "MOV AX, "+$3->get_symbol_value()+"\n";
				temp_code += "CMP AX, 0\n";
				temp_code += "JE "+string(label1)+"\n";
				temp_code += $5->code;
				temp_code += "JMP "+string(label2)+"\n";
				temp_code += string(label1)+":\n";
				temp_code += $7->code;
				temp_code += string(label2)+":\n";
				$$->code = temp_code;
			}

		}
		| WHILE LPAREN expression RPAREN statement
		{
			//fprintf(logout,"At line no : %d statement : WHILE LPAREN expression RPAREN statement\n",line_count);

			$$ = new SymbolInfo();
			string s = "while("+$3->get_symbol_name()+")\n"+$5->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			if($3->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type Mismatch \n\n",line_count);
				error_count++;
			}
			else
			{
				string temp_code = "";
				char *label1 = newLabel();
				char *label2 = newLabel();
				temp_code += string(label1)+":\n";
				temp_code += $3->code;
				temp_code += "MOV AX, "+$3->get_symbol_value()+"\n";
				temp_code += "CMP AX, 0\n";
				temp_code += "JE "+string(label2)+"\n";
				temp_code += $5->code;
				temp_code += "JMP "+string(label1)+"\n";
				temp_code += string(label2)+":\n";	
				$$->code = temp_code;
			}		
		}
		| PRINTLN LPAREN ID RPAREN SEMICOLON
		{
			//fprintf(logout,"At line no : %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n",line_count);

			$$ = new SymbolInfo();
			string s = "println("+$3->get_symbol_name()+");";
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());


			//confusion
			string temp_code = "";
			if(symbolTable.lookUpScopeTableID($3->get_symbol_name()) == -1000)
			{
				fprintf(errorout,"Error at line no : %d  Undeclared variable %s\n",line_count,$3->get_symbol_name().c_str());
			}
			else
			{
				temp_code += "MOV AX, "+$3->get_symbol_name()+to_string(symbolTable.lookUpScopeTableID($3->get_symbol_name()))+"\n";
				temp_code += "CALL OUTDEC\n";
			}
			$$->code = temp_code;


		}
		| RETURN expression SEMICOLON
		{
			//fprintf(logout,"At line no : %d statement : RETURN expression SEMICOLON\n",line_count);

			$$ = new SymbolInfo();
			string s ="return "+$2->get_symbol_name()+";";
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			if($2->get_symbol_type() == "VOID")
			{
				fprintf(errorout,"Error at line no : %d   Type mismatch(return type can't be void) \n\n",line_count);
				error_count++;
			}
			else
			{
				string temp_code = $2->code;
				temp_code += "MOV AX, "+$2->get_symbol_value()+"\n";
				//cout<<"Return er moddhe : "<<currentFunction<<endl;
				temp_code += "MOV "+currentFunction+"_return, AX\n";
				//cout<<temp_code<<endl;
			    temp_code += "JMP LReturn"+currentFunction+"\n";
				//cout<<temp_code<<endl;

				$$->code = temp_code;

			}

		}
		;
	  
expression_statement: SEMICOLON
			{
				//fprintf(logout,"At line no : %d expression_statement : SEMICOLON\n",line_count);

				$$ = new SymbolInfo();
				$$->set_symbol_name(";");
				//fprintf(logout,"; \n\n");	
			}			
			| expression SEMICOLON
			{
				//fprintf(logout,"At line no : %d expression_statement : expression SEMICOLON\n",line_count);
				
				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+";";
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				$$->code = $1->code;
				$$->set_symbol_value($1->get_symbol_value());

			} 
			;
	  
variable: ID
		{
			//fprintf(logout,"At line no : %d variable : ID\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* check = symbolTable.lookUp($1->get_symbol_name());
			
			if(check != NULL)
			{
				$$->set_symbol_type(check->get_symbol_type());
			 
				$$->set_symbol_value($1->get_symbol_name()+to_string(symbolTable.lookUpScopeTableID($1->get_symbol_name())));
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
			//fprintf(logout,"At line no : %d variable : ID LTHIRD expression RTHIRD\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+"["+$3->get_symbol_name()+"]";
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* check = symbolTable.lookUp($1->get_symbol_name());

			if(check != NULL)
			{
				$$->set_symbol_type(check->get_symbol_type());
				int err = 0;
				if($3->get_symbol_type() != "INT")
				{
					$$->set_symbol_value($1->get_symbol_name()+to_string(symbolTable.lookUpScopeTableID($1->get_symbol_name())));
					error_count++;
					fprintf(errorout,"Error at line : %d   Non-integer Array Index\n\n",line_count);
					err = 1;
				}
				//seg fault
				else if(check->get_symbol_class() != "ARRAY")
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d   Type mismatch(%s is not an array)\n\n",line_count,check->get_symbol_name().c_str());
					err = 1;
				}
				/*cout<<$3->get_symbol_name()<<endl;
				int size = atoi($3->get_symbol_name().c_str());
				cout<<check->ara_size<<endl;
				if(size > check->ara_size)
				{
					error_count++;
					fprintf(errorout,"Error at line no : %d   Array index out of bound\n\n",line_count);
				}*/

				if(err == 0)
				{
					string temp_code = $3->code;
					temp_code += "MOV BX, "+$3->get_symbol_value()+"\n";
					temp_code += "ADD BX, BX\n";
					$$->set_symbol_value($1->get_symbol_name()+to_string(symbolTable.lookUpScopeTableID($1->get_symbol_name())));
					$$->code = temp_code;
				}
				

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
			//fprintf(logout,"At line no : %d expression : logic_expression\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());
			$$->set_symbol_value($1->get_symbol_value());
			$$->code = $1->code;
		}	
		| variable ASSIGNOP logic_expression
		{
			//fprintf(logout,"At line no : %d expression : variable ASSIGNOP logic_expression\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+" = "+$3->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());


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

			string temp_code = $1->code +$3->code;
			temp_code += "MOV AX, "+$3->get_symbol_value()+"\n";
			
			if($1->get_symbol_class() != "ARRAY")
			{
				temp_code += "MOV "+$1->get_symbol_value()+", AX\n";
			}
			else
			{
				temp_code += "MOV "+$1->get_symbol_value()+"[BX], AX\n";
			}

			$$->set_symbol_value($1->get_symbol_value());
			$$->code = temp_code;		
		} 	
		;
			
logic_expression: rel_expression
			{
				//fprintf(logout,"At line no : %d logic_expression : rel_expression\n",line_count);
			
				$$ = new SymbolInfo();
				string s = $1->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				$$->set_symbol_type($1->get_symbol_type());
				$$->set_symbol_value($1->get_symbol_value());
				$$->code = $1->code;

					
			}
			| rel_expression LOGICOP rel_expression 	
			{
				//fprintf(logout,"At line no : %d logic_expression : rel_expression LOGICOP rel_expression\n",line_count);
			
				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+" "+$2->get_symbol_name()+" "+$3->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

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
				else
				{
					string temp_code = $1->code + $3->code;
					char *temp = newTemp();
					char *label1 = newLabel();
					char *label2 = newLabel();
					char *label3 = newLabel();

					if($2->get_symbol_name() == "||")
					{
						temp_code += "MOV AX, "+$1->get_symbol_value()+"\n";
						temp_code += "CMP AX, 0\n";
						temp_code += "JNE "+string(label2)+"\n";
						temp_code += "MOV AX, "+$3->get_symbol_value()+"\n";
						temp_code += "CMP AX, 0\n";
						temp_code += "JNE "+string(label2)+"\n";
						temp_code += string(label1)+":\n";
						temp_code += "MOV "+string(temp)+", 0\n";
						temp_code += "JMP "+string(label3)+"\n";
						temp_code += string(label2)+":\n";
						temp_code += "MOV "+string(temp)+", 1\n";
						temp_code += string(label3)+":\n";

					}
					else
					{
						temp_code += "MOV AX, "+$1->get_symbol_value()+"\n";
						temp_code += "CMP AX, 0\n";
						temp_code += "JE "+string(label2)+"\n";
						temp_code += "MOV AX, "+$3->get_symbol_value()+"\n";
						temp_code += "CMP AX, 0\n";
						temp_code += "JE "+string(label2)+"\n";
						temp_code += string(label1)+":\n";
						temp_code += "MOV "+string(temp)+", 1\n";
						temp_code += "JMP "+string(label3)+"\n";
						temp_code += string(label2)+":\n";
						temp_code += "MOV "+string(temp)+", 0\n";
						temp_code += string(label3)+":\n";
					}
					
					$$->set_symbol_value(string(temp));
					variable_declaration.push_back(string(temp));
					$$->code = temp_code;
				}
			}
			;
			
rel_expression: simple_expression 
		{
			//fprintf(logout,"At line no : %d rel_expression : simple_expression\n",line_count);
		
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());
			$$->set_symbol_value($1->get_symbol_value());
			$$->code = $1->code;
		}
		| simple_expression RELOP simple_expression
		{
			//fprintf(logout,"At line no : %d rel_expression : simple_expression RELOP simple_expression\n",line_count);
		
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+" "+$2->get_symbol_name()+" "+$3->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			

			//confusion change bison
			if($1->get_symbol_type()=="FLOAT" || $3->get_symbol_type()=="FLOAT")
			{
				fprintf(errorout,"Error at line no : %d  Type conversion to integer(RELOP)\n\n",line_count);
				error_count++;
				
			}
			/*else if($1->get_symbol_type()=="FLOAT" && $3->get_symbol_type()=="INT")
			{
				fprintf(errorout,"Error at line no : %d  Type conversion to integer(RELOP)\n\n",line_count);
				error_count++;
			}*/

			$$->set_symbol_type("INT");

			string temp_code = $1->code + $3->code;
			temp_code += "MOV AX, " + $1->get_symbol_value()+"\n";
			//cout<<"rel ho"<<temp_code<<endl;
			temp_code += "CMP AX, " + $3->get_symbol_value()+"\n";
			char *temp = newTemp();
			char *label1 = newLabel();
			char *label2 = newLabel();

			if($2->get_symbol_name() == "<")
			{
				temp_code += "JL " + string(label1)+"\n";
			}
			else if($2->get_symbol_name() == "<=")
			{
				temp_code += "JLE " + string(label1)+"\n";
			}
			else if($2->get_symbol_name() == ">")
			{
				temp_code += "JG " + string(label1)+"\n";
			}
			else if($2->get_symbol_name() == ">=")
			{
				temp_code += "JGE " + string(label1)+"\n";
			}
			else if($2->get_symbol_name() == "==")
			{
				temp_code += "JE " + string(label1)+"\n";
			}
			else if($2->get_symbol_name() == "!=")
			{
				temp_code += "JNE " + string(label1)+"\n";
			}
			
			temp_code += "MOV "+string(temp) +", 0\n";
			temp_code += "JMP "+string(label2) +"\n";
			temp_code += string(label1)+":\nMOV "+string(temp)+", 1\n";
			temp_code += string(label2)+":\n";
			variable_declaration.push_back(string(temp));
			$$->set_symbol_value(string(temp));
			$$->code = temp_code;
		}	
		;
				
simple_expression: term 
			{
				//fprintf(logout,"At line no : %d simple_expression : term\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				$$->set_symbol_type($1->get_symbol_type());
				$$->set_symbol_value($1->get_symbol_value());
				$$->code = $1->code;

			}
			| simple_expression ADDOP term
			{
				//fprintf(logout,"At line no : %d simple_expression : simple_expression ADDOP term\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+" "+$2->get_symbol_name()+" "+$3->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());
				
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

				string temp_code = $1->code + $3->code;
				temp_code += "MOV AX, "+$1->get_symbol_value()+"\n";
				char *temp = newTemp();
				if($2->get_symbol_name() == "+")
				{
					temp_code += "ADD AX, "+$3->get_symbol_value()+"\n";
				}
				else if($2->get_symbol_name() == "-")
				{
					temp_code += "SUB AX, "+$3->get_symbol_value()+"\n";
				}
				temp_code += "MOV "+string(temp)+", AX\n";
				$$->set_symbol_value(string(temp));
				$$->code = temp_code;
				variable_declaration.push_back(string(temp));
								
			} 
			;
					
	term:	unary_expression
		{
			//fprintf(logout,"At line no : %d term : unary_expression\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());
			$$->set_symbol_value($1->get_symbol_value());
			$$->code = $1->code;
		
		}
		|  term MULOP unary_expression
		{
			//fprintf(logout,"At line no : %d term : term MULOP unary_expression\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+" "+$2->get_symbol_name()+" "+$3->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());


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


				string temp_code = $1->code+$3->code;
				char *temp = newTemp();
				temp_code += "MOV AX, "+$1->get_symbol_value()+"\n";
				temp_code += "MOV BX, "+$3->get_symbol_value()+"\n";
				temp_code += "MOV DX, 0\n";
				temp_code += "DIV BX\n";
				temp_code += "MOV "+string(temp)+", DX\n";
				$$->set_symbol_value(string(temp));
				$$->code = temp_code;
				variable_declaration.push_back(string(temp));

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

				if($2->get_symbol_name() == "/")
				{
					string temp_code = $1->code+$3->code;
					char *temp = newTemp();
					temp_code += "MOV AX, "+$1->get_symbol_value()+"\n";
					temp_code += "MOV BX, "+$3->get_symbol_value()+"\n";
					temp_code += "DIV BX\n";
					temp_code += "MOV "+string(temp)+", AX\n";
					$$->set_symbol_value(string(temp));
					$$->code = temp_code;
					variable_declaration.push_back(string(temp));
				}
				else
				{
					string temp_code = $1->code+$3->code;
					char *temp = newTemp();
					temp_code += "MOV AX, "+$1->get_symbol_value()+"\n";
					temp_code += "MOV BX, "+$3->get_symbol_value()+"\n";
					temp_code += "MUL BX\n";
					temp_code += "MOV "+string(temp)+", AX\n";
					$$->set_symbol_value(string(temp));
					$$->code = temp_code;
					variable_declaration.push_back(string(temp));
				}
			}
		}
		;

unary_expression: ADDOP unary_expression  
			{
				//fprintf(logout,"At line no : %d unary_expression : ADDOP unary_expression\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name()+$2->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());
				
				if($2->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Type mismatch(ADDOP)\n\n",line_count);
					error_count++;
					$$->set_symbol_type("INT");
				}
				else
				{
					$$->set_symbol_type($2->get_symbol_type());
					string temp_code = $2->code;
					if($1->get_symbol_name() == "-")
					{
						temp_code += "MOV AX, "+$2->get_symbol_value()+"\n";
						temp_code += "NEG AX\n";
						temp_code += "MOV "+$2->get_symbol_value()+", AX\n";
					}
					$$->set_symbol_value($2->get_symbol_value());
					$$->code = temp_code;
				}
				
			}
			| NOT unary_expression 
			{
				//fprintf(logout,"At line no : %d unary_expression : NOT unary_expression\n",line_count);

				$$ = new SymbolInfo();
				string s = "!"+$2->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				if($2->get_symbol_type() == "VOID")
				{
					fprintf(errorout,"Error at line no : %d  Type mismatch(NOT)\n\n",line_count);
					error_count++;
					$$->set_symbol_type("INT");
				}
				else
				{
					$$->set_symbol_type($2->get_symbol_type());
					string temp_code = $2->code;
					temp_code += "MOV AX, "+$2->get_symbol_value()+"\n";
					temp_code += "NOT AX\n";
					temp_code += "MOV "+$2->get_symbol_value()+", AX\n";
					$$->set_symbol_value($$->get_symbol_value());
					$$->code = temp_code;
				}
			}
			| factor 
			{
				//fprintf(logout,"At line no : %d unary_expression : factor\n",line_count);

				$$ = new SymbolInfo();
				string s = $1->get_symbol_name();
				$$->set_symbol_name(s);
				//fprintf(logout,"%s\n\n",s.c_str());

				
				$$->set_symbol_type($1->get_symbol_type());
				$$->code = $1->code;
				$$->set_symbol_value($1->get_symbol_value());

			}
			;
	
factor: variable
		{
			//fprintf(logout,"At line no : %d factor : variable\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());

			string temp_code = $1->code ;

			if($1->get_symbol_type() == "ARRAY")
			{
				char *temp = newTemp();
				temp_code += "MOV AX, "+$1->get_symbol_value()+"[BX]\n";
				temp_code += "MOV "+string(temp)+", AX\n";
				variable_declaration.push_back(string(temp));
				$$->set_symbol_value(string(temp));
			}
			else{
				$$->set_symbol_value($1->get_symbol_value());
			}
			$$->code = temp_code;

		}
		| ID LPAREN argument_list RPAREN
		{
			//fprintf(logout,"At line no : %d factor : ID LPAREN argument_list RPAREN\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+"("+$3->get_symbol_name()+")";
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());
	
			SymbolInfo* symb = symbolTable.lookUp($1->get_symbol_name());


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
						string temp_code = $3->code;
						for(int i=0;i<argument_list_vector.size();i++)
						{
							temp_code += "MOV AX, "+argument_list_vector[i]->get_symbol_value()+"\n";
							//cout<<"argument:"<<argument_list_vector[i]->get_symbol_value()<<endl;
							temp_code += "MOV "+symbolTable.lookUp($1->get_symbol_name())->para_list[i].second+", AX\n";
							//cout<<symbolTable.lookUp($1->get_symbol_name())->para_list[i].second<<endl;
							//confusion
							if(argument_list_vector[i]->get_symbol_type() != symb->para_list[i].first)
							{
								fprintf(errorout,"Error at line no : %d  Function Argument Type Mismatch\n\n",line_count);
								error_count++;
							}		
						}

						temp_code += "CALL "+$1->get_symbol_name()+"\n";
						temp_code += "MOV AX, "+$1->get_symbol_name()+"_return\n";
						char *temp = newTemp();
						temp_code += "MOV "+string(temp)+", AX\n";
						$$->set_symbol_value(temp);
						$$->code = temp_code;
						variable_declaration.push_back(string(temp));

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
			//fprintf(logout,"At line no : %d factor : LPAREN expression RPAREN\n",line_count);

			$$ = new SymbolInfo();
			string s = "("+$2->get_symbol_name()+")";
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($2->get_symbol_type());
			$$->code = $2->code;
			$$->set_symbol_value($2->get_symbol_value());
		}
		| CONST_INT
		{
			//fprintf(logout,"At line no : %d factor : CONST_INT\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type("INT");	

			char *temp = newTemp();
			string temp_code = "";
			temp_code += "MOV "+string(temp)+", "+$1->get_symbol_name()+"\n";
			$$->code = temp_code;
			$$->set_symbol_value(string(temp));
			variable_declaration.push_back(string(temp));

		} 
		| CONST_FLOAT
		{
			//fprintf(logout,"At line no : %d factor : CONST_FLOAT\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type("FLOAT");

			char *temp = newTemp();
			string temp_code = "";
			temp_code += "MOV "+string(temp)+", "+$1->get_symbol_name()+"\n";
			$$->code = temp_code;
			$$->set_symbol_value(string(temp));
			variable_declaration.push_back(string(temp));
		}
		| variable INCOP
		{
			//fprintf(logout,"At line no : %d factor : variable INCOP\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+"++";
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());

			char *temp = newTemp();
			string temp_code = "";
			if($1->get_symbol_class() == "ARRAY")
			{
				temp_code += "MOV AX, "+$1->get_symbol_value()+"[BX]\n";
			}
			else
			{
				temp_code += "MOV AX, "+$1->get_symbol_value()+"\n";
			}
			temp_code += "MOV "+string(temp)+", AX\n";

			if($1->get_symbol_class() == "ARRAY")
			{
				temp_code += "MOV AX, "+$1->get_symbol_value()+"[BX]\n";
				temp_code += "INC AX\n";
				temp_code += "MOV "+$1->get_symbol_value()+"[BX],AX\n";
			}
			else{
				temp_code += "INC "+$1->get_symbol_value()+"\n";
			}
			variable_declaration.push_back(string(temp));
			$$->code = temp_code;
			$$->set_symbol_value(string(temp));
		} 
		| variable DECOP
		{
			//fprintf(logout,"At line no : %d factor : variable DECOP\n",line_count);
		    
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+"--";
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			$$->set_symbol_type($1->get_symbol_type());

			char *temp = newTemp();
			string temp_code = "";
			if($1->get_symbol_class() == "ARRAY")
			{
				temp_code += "MOV AX, "+$1->get_symbol_value()+"[BX]\n";
			}
			else
			{
				temp_code += "MOV AX, "+$1->get_symbol_value()+"\n";
			}
			temp_code += "MOV "+string(temp)+", AX\n";

			if($1->get_symbol_class() == "ARRAY")
			{
				temp_code += "MOV AX, "+$1->get_symbol_value()+"[BX]\n";
				temp_code += "DEC AX\n";
				temp_code += "MOV "+$1->get_symbol_value()+"[BX],AX\n";
			}
			else{
				temp_code += "DEC "+$1->get_symbol_value()+"\n";
			}
			variable_declaration.push_back(string(temp));
			$$->code = temp_code;
			$$->set_symbol_value(string(temp));
		}
		;
	
argument_list: arguments
		{
			//fprintf(logout,"At line no : %d argument_list : arguments\n",line_count);

			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			$$->code = $1->code;

		}
	    |	
		{ 
			$$ = new SymbolInfo(); 
			//fprintf(logout,"At line no : %d  argument_list : (empty) \n\n",line_count);
			$$->set_symbol_name("");
		}  
		;
	
arguments: arguments COMMA logic_expression
		{
			//fprintf(logout,"At line no : %d arguments : arguments COMMA logic_expression\n",line_count);
			
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name()+","+$3->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name($3->get_symbol_name());
			symb->set_symbol_type($3->get_symbol_type());
			symb->set_symbol_class("VARIABLE");//argument = variable
			symb->set_symbol_value($3->get_symbol_value());


			argument_list_vector.push_back(symb);

			$$->code = $1->code+$3->code;
		}
		| logic_expression
		{
			//fprintf(logout,"At line no : %d arguments : logic_expression\n",line_count);
		    
			$$ = new SymbolInfo();
			string s = $1->get_symbol_name();
			$$->set_symbol_name(s);
			//fprintf(logout,"%s\n\n",s.c_str());

			SymbolInfo* symb = new SymbolInfo();
			symb->set_symbol_name($1->get_symbol_name());
			symb->set_symbol_type($1->get_symbol_type());
			symb->set_symbol_class("VARIABLE");
			symb->set_symbol_value($1->get_symbol_value());

			argument_list_vector.push_back(symb);

			$$->code = $1->code;

		}
		;
 		   


%%
void optimizeCode(FILE *asmfile)
{
	FILE* optimizedFile = fopen("1605084_Code.asm","w");
	char* line = NULL;
	size_t len = 0;

	vector<string>unoptimizedFileVector;
	while ((getline(&line, &len, asmfile)) != -1)
	{
		unoptimizedFileVector.push_back(string(line));
	}
	bool *duplicateCheck = new bool[unoptimizedFileVector.size()];
	for(int i=0;i<unoptimizedFileVector.size();i++)
	{
		duplicateCheck[i] = false;
	}

	for(int i=0;i<unoptimizedFileVector.size();i++)
	{
		if(unoptimizedFileVector[i].find("MOV") == 0)
		{
			if(unoptimizedFileVector[i+1].find("MOV") == 0)
			{
				int pos = 0;
				string s1,s2;
			
				s1 = unoptimizedFileVector[i];
				s2 = unoptimizedFileVector[i+1];
				chomp(s1);//erase new line from string
				chomp(s2);
				//cout<<s1;


				string line1_secondPart,line2_secondPart;
				while ((pos = s1.find(" ")) != string::npos) 
				{
					//line1_firstPart = s1.substr(0, pos);//MOV
					//cout<<line1_firstPart<<endl;
					line1_secondPart = s1.substr(pos+1,s1.size()-1);
					
					//cout<<line1_secondPart;
					break;
				}
				pos = 0;
				while ((pos = s2.find(" ")) != string::npos) 
				{
					//line2_firstPart = s2.substr(0, pos);//MOV
					//cout<<line1_firstPart<<endl;
					line2_secondPart = s2.substr(pos+1,s2.size()-1);
					//line2_secondPart '\n';
					//cout<<line1_secondPart;
					break;
				}

				string s3,s4,s5,s6;
				pos =0;
				while ((pos = line1_secondPart.find(", ")) != string::npos) 
				{
					//cout<<"hi"<<endl;
					s3 = line1_secondPart.substr(0, pos);
					//cout<<line1_firstPart<<endl;
					s4 = line1_secondPart.substr(pos+2,line1_secondPart.size()-1);
					
					break;
					
				}
				pos =0;
				while ((pos = line2_secondPart.find(", ")) != string::npos) 
				{
					s5 = line2_secondPart.substr(0, pos);
					//cout<<line1_firstPart<<endl;
					s6 = line2_secondPart.substr(pos+2,line1_secondPart.size()-1);
					
					break;
				}
				
				if(s3==s6 && s4 == s5)
				{
					/*cout<<"duplicate "<<endl;
					cout<<s3<<endl;
					cout<<s4<<endl;
					cout<<s5<<endl;
					cout<<s6<<endl;*/
					duplicateCheck[i+1] = true;
				}
			}
			if(duplicateCheck[i] == false)
			{
				fprintf(optimizedFile,"%s",unoptimizedFileVector[i].c_str());
			}
		}
		else
		{
			fprintf(optimizedFile,"%s",unoptimizedFileVector[i].c_str());
		}
		
		
	}
	fclose(asmfile);
	fclose(optimizedFile);


}
void chomp( string &s)
{
		int pos;
		if((pos=s.find('\n')) != string::npos)
		{
			s.erase(pos);
		}
}
int main(int argc,char *argv[])
{

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}
	
	errorout = fopen("1605084_log.txt","w");
    //logout = fopen("1605084_log.txt","w");

	yyin=fp;
	symbolTable.enterScope(10);
	yyparse();

	//fprintf(logout,"\n\nSymbol Table :\n\n");
	//symbolTable.printAll();
	fprintf(errorout,"\nTotal lines : %d\n",line_count);
	fprintf(errorout,"\nTotal errros : %d\n",error_count);
	//fprintf(errorout,"\nTotal errros : %d\n",error_count);
	fclose(fp);
	fclose(errorout);
	//fclose(logout);
	
	return 0;
}

