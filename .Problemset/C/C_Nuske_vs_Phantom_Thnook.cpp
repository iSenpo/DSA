#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)

char a[2001][2001];
int n , m , q ;

void input()
{
    cin >> n >> m >> q;
    fo(i , n){
        fo(j , m){
            cin >> a[i][j];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    input();
    return 0;
}