#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n<26){
        cout<<"NO";
        return 0;
    }
    string s;
    cin>>s;
    bool letter[26];
    for(int i = 0 ; i < 26 ; i++){
        letter[i] = true;
    }

    for(int i = 0 ; i < 26 ;i++){
        char temp = 'a' + i;
        char temp2 = 'A' + i;
        for(int k = 0 ; k < n ; k++){
            if(s[k] == temp || s[k] == temp2){
                letter[i] = false;
            }
        }
    }

    for(int i = 0; i<min(n,26) ; i++){
        if(letter[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}