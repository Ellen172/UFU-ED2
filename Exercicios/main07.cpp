#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    string str, str2;
    cin >> test;
    for(int i=0; i<test; i++){
        int count=0;
        cin >> str; 
        for(int j=str.length()-1; j>=0; j--){
            str2.push_back(str[j]);
        }
        if(str.compare(str2) == 0){
            cout << count << endl;
        } else {
            for(int j=0; j<str.length(); j++){
                if(str[j] != str[0]) count++;
            }
            cout << count << endl;
        }
        str2.clear();
    }
}