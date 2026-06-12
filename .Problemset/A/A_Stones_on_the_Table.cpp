#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N  = 1e5 + 500;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int counter = 0;
    for(int i = 0 ; i< n-1 ; i++){
        if(s[i] == s[i+1]){
            counter++;
        }
    }
    cout<<counter;
    return 0;
}