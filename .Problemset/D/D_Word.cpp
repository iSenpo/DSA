#include <iostream>
using namespace std;
string s;
int LowerCase(){
    int counter = 0;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            counter++;
        }
    }
    return counter;
}
int UpperCase(){
     int counter = 0;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            counter++;
        }
    }
    return counter;
}
int main(){
    cin>>s;
    char temp;
    if(UpperCase()>LowerCase()){
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                temp = toupper(s[i]);
                cout<<temp;
            }
            else{
                cout<<s[i];
            }
        }
    }
    else{
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                temp = tolower(s[i]);
                cout<<temp;
            }
            else{
                cout<<s[i];
            }
        }
    }
    return 0;
}