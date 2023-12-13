#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<fstream>

using namespace std;



class SymbolInfo
{
    string symbol_name;
    string type;
public:
    SymbolInfo *next;

    SymbolInfo()
    {
        symbol_name = "";
        type = "";
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


    bool chain_insert(SymbolInfo* s)
    {
        SymbolInfo *temp_symbol= s;
        //cout<<temp_symbol->get_symbol_name()<<endl;
        hash_pos = hash1(temp_symbol->get_symbol_name());
        insert_index = 0;

        SymbolInfo *newNode = new SymbolInfo(temp_symbol->get_symbol_name(),temp_symbol->get_symbol_type());

        SymbolInfo *check_duplicate = hashTable[hash_pos];
        SymbolInfo *temp = hashTable[hash_pos];

        while(check_duplicate != NULL)
        {
            if(check_duplicate->get_symbol_name() == temp_symbol->get_symbol_name())
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
                //fprintf(logout,"%d :--> ",i);
                cout<<i<<":--> ";
                SymbolInfo *temp = hashTable[i];
                while(temp != NULL)
                {
                    string temp1 = temp->get_symbol_name();
                    const char* s1 = temp1.c_str();
                    string temp2 = temp->get_symbol_type();
                    const char* s2 = temp2.c_str();
                    cout<<" < "<<temp->get_symbol_name()<<" : "<<temp->get_symbol_type()<<" > ";
                    //fprintf(logout," <  %s :  %s >",s1,s2);
                    temp = temp->next;
                }
                cout<<endl;
                //fprintf(logout,"\n");
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
    bool insert(SymbolInfo* s)
    {
        current_scope_table->chain_insert(s);
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
            //fprintf(logout,"ScopeTable# %d\n\n",temp_id);
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
