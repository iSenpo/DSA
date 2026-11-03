#include <iostream>
using namespace std;

string line1 = "qwertyuiop";
string line2 = "asdfghjkl;";
string line3 = "zxcvbnm,./";

void ShiftRight(char a,string keyboard){
   for(int i = 0; i < 10 ; i++){
        if(a == keyboard[i]){
            cout<<keyboard[i+1];
            break;
        }
   }
}
void ShiftLeft(char a,string keyboard){
   for(int i = 0; i < 10 ; i++){
        if(a == keyboard[i]){
            cout<<keyboard[i-1];
            break;
        }
   }
}
int main(){
    char input;
    cin>>input;
    string line;
    cin.ignore();
    getline(cin,line);
    if(input == 'R'){
        for(int i = 0; i<line.size();i++){
            if(line[i] == 'q'){
                cout<<"q";
                continue;
            }
            if(line[i] == 'a'){
                cout<<"a";
                continue;
            }
            if(line[i] == 'z'){
                cout<<"z";
                continue;
            }
            ShiftLeft(line[i],line1);
            ShiftLeft(line[i],line2);
            ShiftLeft(line[i],line3);
        }
    }
    else{
        for(int i = 0; i<line.size();i++){
             if(line[i] == '/'){
                cout<<"/";
                continue;
            }
            if(line[i] == ';'){
                cout<<";";
                continue;
            }
            if(line[i] == 'p'){
                cout<<"p";
                continue;
            }
            ShiftRight(line[i],line1);
            ShiftRight(line[i],line2);
            ShiftRight(line[i],line3);
            
        }
    }
    return 0;
}