%option noyywrap
%x SINGLE_LINE_COMMENT
%x MULTI_LINE_COMMENT

%{
#include<bits/stdc++.h>

using namespace std;

int line_count=1;
int error_count =0;
string str;
int str_index;

FILE *logout;
FILE *tokenout;


class SymbolInfo
{
    string symbol_name;
    string type;
public:
    SymbolInfo *next;

    SymbolInfo()
    {
        symbol_name = nullptr;
        type = nullptr;
        next = NULL;
    }

    SymbolInfo(string name,string _type)
    {
        symbol_name = name;
        type = _type;
        next = NULL;
    }

    void set_symbol_name(string name)
    {
        symbol_name = name;
    }

    void set_symbol_type(string _type)
    {
        type = _type;
    }

    string get_symbol_name()
    {
        return symbol_name;
    }

    string get_symbol_type()
    {
        return type;
    }

    ~SymbolInfo()
    {

    }

};

class ScopeTable
{
    int table_size;
    SymbolInfo **hashTable;

public:
    ScopeTable *parentScope;
    int lookup_index;
    int delete_index;
    int insert_index;
    int hash_pos;
    int *chain_size;

    ScopeTable()
    {
        parentScope = NULL;
        hashTable = NULL;
        table_size = 0;
    }

    ScopeTable(int capacity)
    {
        table_size = capacity;
        hashTable = new SymbolInfo*[capacity];
        for(int i=0; i<capacity; i++)
        {
            hashTable[i] = NULL;
        }
        chain_size = new int[capacity];
        for(int i=0; i<capacity; i++)
        {
            chain_size[i] = 0;
        }
    }

    int getTableSize()
    {
        return table_size;
    }


    int hash1(string word)
    {
        int seed = 131;
        unsigned long hash = 0;
        int len = word.length();
        for(int i = 0; i < len; i++)
        {
            hash = (hash * seed) + word[i];
        }
        return hash % table_size;
    }
    int hash2(string word)
    {
        unsigned hash = 0;
        int len = word.length();
        for (int i = 0; i < len; i++)
        {
            hash ^= (hash << 5) + (hash >> 2) + word[i];
        }
        return hash % table_size;
    }


    bool chain_insert(string name,string type)
    {
        hash_pos = hash1(name);
        insert_index = 0;

        SymbolInfo *newNode = new SymbolInfo(name,type);

        SymbolInfo *check_duplicate = hashTable[hash_pos];
        SymbolInfo *temp = hashTable[hash_pos];

        while(check_duplicate != NULL)
        {
            if(check_duplicate->get_symbol_name() == name)
            {
                break;
            }
            check_duplicate = check_duplicate->next;
        }
        if(check_duplicate != NULL )
        {
            //cout<<" < "<<name<<","<<type<<" > "<<"already exists in current ScopeTable"<<endl;
            return false;
        }
        if(hashTable[hash_pos] == NULL)
        {
            hashTable[hash_pos] = newNode;
            chain_size[hash_pos]++;
            return true;
        }
        else
        {
            SymbolInfo* start_node = hashTable[hash_pos];
            insert_index++;
            while(start_node->next != NULL)
            {
                insert_index++;
                start_node = start_node->next;
            }
            start_node->next = newNode;
            chain_size[hash_pos]++;
            return true;
        }
    }

    SymbolInfo* chain_look_up(string name)
    {
        hash_pos = hash1(name);
        lookup_index = 0;

        SymbolInfo *temp = hashTable[hash_pos];

        while(temp != NULL)
        {
            if(temp->get_symbol_name() == name)
            {
                return temp;
            }
            temp = temp->next;
            lookup_index++;
        }
        return NULL;
    }
    bool chain_delete(string name)
    {
        delete_index =0;
        SymbolInfo *temp,*prev;
        hash_pos = hash1(name);
        temp = hashTable[hash_pos] ; //start at the beginning
        while (temp != NULL)
        {
            if (temp->get_symbol_name() == name) break ;
            prev = temp;
            temp = temp->next ;
            delete_index++; //move to next node
        }
        if (temp == NULL)
        {
            return false ;
        }
        if (temp == hashTable[hash_pos]) //delete the first node
        {
            hashTable[hash_pos] = hashTable[hash_pos]->next ;
            delete temp;
            chain_size[hash_pos]--;
        }
        else
        {
            prev->next = temp->next ;
            delete temp;
            chain_size[hash_pos]--;
        }
    }

    void printScopeTable()
    {
        for(int i=0; i<table_size; i++)
        {
            if(chain_size[i] != 0)
            {
		fprintf(logout,"%d :--> ",i);
                cout<<i<<":--> ";
                SymbolInfo *temp = hashTable[i];
                while(temp != NULL)
                {
		    string temp1 = temp->get_symbol_name();
		    const char* s1 = temp1.c_str();
		    string temp2 = temp->get_symbol_type();
		    const char* s2 = temp2.c_str();
                    cout<<" < "<<temp->get_symbol_name()<<" : "<<temp->get_symbol_type()<<" > ";
		    fprintf(logout," <  %s :  %s >",s1,s2);
                    temp = temp->next;
                }
                cout<<endl;
		fprintf(logout,"\n");
            }

        }
    }

    ~ScopeTable()
    {
        for(int i=0; i<table_size; i++)
        {
            if(hashTable[i]!=NULL)
            {
                delete hashTable[i];
            }
        }
        delete[] hashTable;
    }
};


class SymbolTable
{
    ScopeTable *current_scope_table;
public:
    int id;

    SymbolTable()
    {
        id = 0;
        current_scope_table = NULL;
    }
    void enterScope(int size)
    {
        id++;
        cout<<endl;
        //cout<<"New ScopeTable with id "<<id<<" created"<<endl<<endl;
        ScopeTable *newScopeTable =new ScopeTable(size);
        newScopeTable->parentScope = current_scope_table;
        current_scope_table = newScopeTable;
    }
    void exitScope()
    {
        if(current_scope_table==NULL)
        {
            cout<<"No scope found"<<endl;
            return;
        }
        ScopeTable *temp = current_scope_table->parentScope;
        current_scope_table->~ScopeTable();
        cout<<"ScopeTable with id "<<id<<" removed"<<endl;
        current_scope_table = temp;
        id--;

    }
    bool insert(string name,string type)
    {
        current_scope_table->chain_insert(name,type);
    }
    bool remove(string name)
    {
        bool ans = current_scope_table->chain_delete(name);
        if(ans)
        {
            cout<<"Found in ScopeTable #"<<id<<" at position "<<current_scope_table->hash_pos<<","<<current_scope_table->delete_index<<endl;
            cout<<"Deleted entry at "<<current_scope_table->hash_pos<<","<<current_scope_table->delete_index<<" from current scopetable"<<endl;
        }
        else
        {
            cout<<"Not found"<<endl;
            cout<<name<<" not found"<<endl;
        }

        return ans;
    }
    SymbolInfo* lookUp(string name)
    {
        ScopeTable *temp = current_scope_table;
        int temp_id = id;
        while(temp!= NULL)
        {
            if(temp->chain_look_up(name))
            {
                cout<<"Found in ScopeTable# "<<temp_id<<" at posisition "<<temp->hash_pos<<","<<temp->lookup_index<<endl;
                //cout<<"found"<<endl;
                return temp->chain_look_up(name);
            }
            temp_id--;
            temp = temp->parentScope;
        }
        cout<<"Not found"<<endl;
        return NULL;
    }

    void printCurrent()
    {
        if(current_scope_table == NULL)
        {
            cout<<"No table exists"<<endl;
            return;
        }
        cout<<"ScopeTable#"<<id<<endl;
        current_scope_table->printScopeTable();
    }
    void printAll()
    {
        int temp_id = id;
        ScopeTable *temp = current_scope_table;
        if(temp == NULL)
        {
            cout<<"No table exists"<<endl;
            return;
        }
        while(temp!=NULL)
        {
            fprintf(logout,"ScopeTable# %d\n\n",temp_id);
            cout<<"ScopeTable#"<<temp_id<<endl;
            temp->printScopeTable();
            cout<<endl;
            temp = temp->parentScope;
            temp_id--;
        }
    }
    ~SymbolTable()
    {

    }

};

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


{UNFINISHED_COMMENT} {
				fprintf(logout,"Error at line no %d:Unfinished comment %s found\n",line_count,yytext);
				error_count++;

                             }


"//" {
			BEGIN SINGLE_LINE_COMMENT;
}
<SINGLE_LINE_COMMENT>[$] {
			//fprintf(tokenout,"<STRING,%s>",yytext);
			fprintf(logout,"Line no %d :A comment %s found\n",line_count,yytext);
			BEGIN INITIAL;
			
}



{IDENTIFIER} {
				 fprintf(tokenout,"<IDENTIFIER,%s>",yytext);
			         fprintf(logout,"Line no %d: TOKEN <IDENTIFIER> Lexeme %s found\n",line_count,yytext);
				 st.insert(string(yytext),"ID");
				 
			
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
