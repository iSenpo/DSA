#include <iostream>
using namespace std;
int Poss(int a){
    if(a == 0 || a == 2 || a == 6 || a == 9){
        return 2;
    }
    if(a == 1){
        return 7;
    }
    if(a == 3 || a == 4){
        return 3;
    }
    if(a == 5){
        return 4;
    }
    if(a == 7){
        return 5;
    }
    if(a == 8){
        return 1;
    }
    return 1;
}
int main(){
    string s;
    cin>>s;
    int d1 = Poss(s[0]-'0');
    int d2 = Poss(s[1]-'0');
    cout<<d1*d2;
    return 0;
}