#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        s = "0" + s;
        int size = s.size();
        int index = 0;
        for(int i = size - 1 ; i >= 0 ; i--){
            if(s[i] >= '5'){
                s[i] = '0';
                index = i;
                int j = i - 1;
                while(s[j] == '9'){
                    s[j--] = '0';
                }
                s[j]++;
            }
        }
        for(int i = index ; i < size ; i++){
            s[i] = '0';
        }
        if(s.front() == '0'){
            s = s.substr(1);
        }
        cout << s << endl;
        
    }
    return 0;
}