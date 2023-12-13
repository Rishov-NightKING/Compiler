#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<fstream>
//#include<bits/stdc++.h>

using namespace std;
extern FILE *logout;


class SymbolInfo
{
private:
    string symbol_name;
    string symbol_type; //int,float,void
    string symbol_class; // array/func/variable?
    
    
	
	public:
    SymbolInfo *next;
    bool is_function_defined;	//true, false
    bool is_function_declared;
    int ara_size; 	//CONST_INT
    int parameter_no = 0;

    vector<pair<string,string>>para_list;  //pair<type,variable>4
    vector<pair<string,string>>arg_list;  //pair<type,variable>
	

    SymbolInfo()
    {
        symbol_name = "";
        symbol_type = "";
        symbol_class = "";
        ara_size = 0;
        is_function_defined = false;
        is_function_declared = false;
        next = NULL;
    }    


    SymbolInfo(string name,string sym_class)
    {
        symbol_name = name;
        symbol_class = sym_class;
        symbol_type = "";
        ara_size = 0;
        is_function_defined = false;
        is_function_declared = false;
        next = NULL;
    }

    void set_symbol_name(string name)
    {
        symbol_name = name;
    }

    string get_symbol_name()
    {
        return symbol_name;
    }

    void set_symbol_type(string _type)
    {
        symbol_type = _type;
    }

    string get_symbol_type()
    {
        return symbol_type;
    }

    void set_symbol_class(string sym_class)
    {
        symbol_class = sym_class;
    }
    string get_symbol_class()
    {
        return symbol_class;
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


    bool chain_insert(SymbolInfo* s)
    {
        SymbolInfo *newNode = s;
        hash_pos = hash1(s->get_symbol_name());
        insert_index = 0;

        SymbolInfo *check_duplicate = hashTable[hash_pos];
        SymbolInfo *temp = s;

        while(check_duplicate != NULL)
        {
            if(check_duplicate->get_symbol_name() == temp->get_symbol_name())
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
                //cout<<i<<":--> ";
                SymbolInfo *temp = hashTable[i];
                while(temp != NULL)
                {
                    string temp1 = temp->get_symbol_name();
                    const char* s1 = temp1.c_str();
                    string temp2 = temp->get_symbol_class();
                    const char* s2 = temp2.c_str();
                    string temp3 = temp->get_symbol_type();
                    const char* s3 = temp3.c_str();
                   // cout<<" < "<<temp->get_symbol_name()<<" : "<<temp->get_symbol_type()<<" > ";
                    fprintf(logout," <  name(%s) : ID(%s),  type(%s) >",s1,s2,s3);
                    temp = temp->next;
                }
                //cout<<endl;
                fprintf(logout,"\n\n");
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
    vector<int>scope_id;

    SymbolTable()
    {
        id = 0;
        current_scope_table = NULL;
    }
    void enterScope(int size)
    {
        id++;
        scope_id.push_back(id);
        //cout<<endl;
        //cout<<"New ScopeTable with id "<<id<<" created"<<endl<<endl;
        fprintf(logout,"\n\nNew ScopeTable with id %d created\n\n",id);
        ScopeTable *newScopeTable =new ScopeTable(size);
        newScopeTable->parentScope = current_scope_table;
        current_scope_table = newScopeTable;
    }
    void exitScope()
    {
        if(current_scope_table == NULL)
        {
            cout<<"No scope found"<<endl;
            return;
        }
        ScopeTable *temp = current_scope_table->parentScope;
        current_scope_table->~ScopeTable();
        //cout<<"ScopeTable with id "<<id<<" removed"<<endl;
        fprintf(logout,"\n\nScopeTable with id %d removed\n\n",id);
        current_scope_table = temp;
        scope_id.pop_back();
        //id--;

    }
    bool insert(SymbolInfo* s)
    {
        if(current_scope_table->chain_insert(s))
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
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
                //cout<<"Found in ScopeTable# "<<temp_id<<" at posisition "<<temp->hash_pos<<","<<temp->lookup_index<<endl;
                //cout<<"found"<<endl;
                return temp->chain_look_up(name);
            }
            temp_id--;
            temp = temp->parentScope;
        }
        //cout<<"Not found"<<endl;
        return NULL;
    }

    void printCurrent()
    {
        if(current_scope_table == NULL)
        {
            cout<<"No table exists"<<endl;
            return;
        }
       // cout<<"ScopeTable#"<<id<<endl;
        fprintf(logout,"ScopeTable#%d\n\n",id);
        current_scope_table->printScopeTable();
    }
    void printAll()
    {
        int temp_id = scope_id.size()-1;
        ScopeTable *temp = current_scope_table;
        if(temp == NULL)
        {
            cout<<"No table exists"<<endl;
            return;
        }
        while(temp!=NULL)
        {
            fprintf(logout,"ScopeTable# %d\n\n",scope_id.at(temp_id));
             // cout<<"ScopeTable#"<<temp_id<<endl;
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
