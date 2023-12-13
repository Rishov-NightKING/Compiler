#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<fstream>
#include"1605084_symbolTable.h"
using namespace std;


int main()
{
    SymbolTable st;
    st.enterScope(3);
    //cout<<"main"<<endl;
    SymbolInfo* s = new SymbolInfo();
    s->set_symbol_name("10");
    s->set_symbol_type("CONST_INT");
    //cout<<"main"<<endl;
    st.insert(s);
    st.enterScope(3);
    SymbolInfo* s1 = new SymbolInfo("20","CONST_INT");
    //cout<<"main"<<endl;
    st.insert(s1);
    st.exitScope();
    //cout<<"main"<<endl;
    //st.remove("20");

    st.printAll();

    SymbolInfo* sym = st.lookUp("10");

    cout<<sym->get_symbol_name()<<endl;
    cout<<sym->get_symbol_type()<<endl;

    string x = "abc";
    string y = "sbc";
    if(x==y)
    {
    cout<<"yagjdjvbfjvbjfbvjhfbvjhbgfhv"<<endl;
    }



}
