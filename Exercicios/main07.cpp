#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    string str, rev;
    cin >> test;
    for(int i=0; i<test; i++){
        // string 
        cin >> str; 
        int tam_str = str.length();

        // reverte string
        for(int j=tam_str-1; j>=0; j--){
            rev.push_back(str[j]);
        } 
        int tam_rev = rev.length();
        
        // criando auxiliares
        int i_rev=0, i_str=0;
        string str_aux = str.substr(i_str, tam_str); 
        string rev_aux = rev.substr(i_rev, tam_rev); 

        // comparando substring 

        // retirando o ultimo elemento de str e o primeiro de rev
        while(str_aux.compare(rev_aux) != 0){
            i_rev ++;
            rev_aux = rev.substr(i_rev, tam_rev);
            str_aux.pop_back();
        } 
        int cont_rev = i_rev;

        // reiniciando auxiliares
        i_rev=0; i_str=0;
        str_aux = str.substr(i_str, tam_str); 
        rev_aux = rev.substr(i_rev, tam_rev); 

        // retirando o primero elemento de str e o ultimo de rev
        while(str_aux.compare(rev_aux) != 0){
            i_str ++;
            str_aux = str.substr(i_str, tam_str);
            rev_aux.pop_back();
        } 
        int cont_str = i_str;

        if(cont_str < cont_rev) cout << cont_str << endl;
        else cout << cont_rev << endl;

        rev.clear();
    }
}