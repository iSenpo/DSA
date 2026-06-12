#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

void solve()
{
    int n , m;
    cin >> n >> m;
    string s[n];
    
    vector<int> v1, v2 , v3, v4; 
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
       for(int j = 0 ; j < m ; j++){
            if(s[i][j] == 'v'){
                v1.push_back(j);
            }
            if(s[i][j] == 'i'){
                v2.push_back(j);
            }
            if(s[i][j] == 'k'){
                v3.push_back(j);
            }
            if(s[i][j] == 'a'){
                v4.push_back(j);
            }
       }
    }
    if(v1.empty() || v2.empty() || v3.empty() || v4.empty()){
        cout << "NO\n";
        return;
    }
    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());
    sort(v3.begin() , v3.end());
    sort(v4.begin() , v4.end());
    for(int i = 0 ; i < v2.size() ; i++){
        if(v2[i] > v1[0]){
            for(int j = 0 ; j < v3.size() ; j++){
                if(v3[j] > v2[i]){
                    if(v3[j] < v4[v4.size()-1]){
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}