#include <iostream>
using namespace std;


int main(){
    string s= "";
    getline(cin,s);
    int counter = 0;
    for(int i = 0; i<s.size() ;i++){
        if((s[i] >= 'A' && s[i] <= 'Z') || s[i] == ' '){
            counter++;
        }
    }
    if(counter+1 == s.size()){
    if ((s[0] >= 'A' && s[0] <= 'Z') || s[0] == ' '){
        cout<<s;
        return 0;
    }
    }
    if((counter+1 == s.size()) || (counter == s.size())){
        for(int i =0 ; i<s.size();i++){
            
            if (s[i] >= 'A' && s[i] <= 'Z'){
                s[i] += 32;
            }
            else if (s[i] >= 'a' && s[i] <= 'z'){
                s[i] -= 32;
            }
            else 
                continue;
        }
    }

    cout<<s;
    return 0;
}