#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    string s[n];
    int counter = 0;
    int inCounter = 0;
    for(int i = 0 ; i < n; i++){
        cin>>s[i];
        inCounter = 0;
        for(int j = 0; j < s[i].size() ; j++){
            if(s[i][j] == '4' || s[i][j] == '7'){
                inCounter++;
            }
        }
        if(inCounter <= k){
            counter++;
        }
    }
    cout<<counter;
    return 0;
}